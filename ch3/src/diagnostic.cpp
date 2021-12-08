#include "diagnostic.hpp"

#include <boost/dynamic_bitset.hpp>
#include <fstream>
#include <format>
#include <iostream>
#include <iterator>
#include <memory>
#include <ranges>
#include <vector>
#include <span>


namespace ch3 {

	std::vector<PositonInfo> read_diagnostic_data(std::string file_path) {
		std::ifstream file(file_path);

		if (!file.good()) {
			std::cerr << "Failed to open file: " << file_path;
			throw std::runtime_error("File Failure");
		}

		std::vector<PositonInfo> positions{};

		std::string buffer;
		while (!file.eof()) {
			std::getline(file, buffer);

			if (buffer == "") {
				continue;
			}

			for (size_t i = 0; i < buffer.length(); ++i) {
				char bit = buffer[i];
				if (positions.size() != buffer.length()) {
					positions.push_back(PositonInfo{ i, 0, 0 });
				}

				if (bit == '0') {
					positions[i].zeros++;
				}
				else if (bit == '1') {
					positions[i].ones++;
				}
				else {
					throw std::runtime_error("Unexpected bit: " + bit);
				}

			}
		}

		return positions;
	}

	DiagnosticData read_and_return_diagnostic_data(std::string file_path) {
		std::ifstream file(file_path);

		if (!file.good()) {
			std::cerr << "Failed to open file: " << file_path;
			throw std::runtime_error("File Failure");
		}

		DiagnosticData data;

		std::string buffer;
		while (!file.eof()) {
			std::getline(file, buffer);

			if (buffer == "") {
				continue;
			}
			else {
				data.diagnostic_lines.push_back(buffer);
			}

			for (size_t i = 0; i < buffer.length(); ++i) {
				char bit = buffer[i];
				if (data.position_stats.size() != buffer.length()) {
					data.position_stats.push_back(PositonInfo{ i, 0, 0 });
				}

				if (bit == '0') {
					data.position_stats[i].zeros++;
				}
				else if (bit == '1') {
					data.position_stats[i].ones++;
				}
				else {
					throw std::runtime_error("Unexpected bit: " + bit);
				}
			}
		}

		return data;
	}

	int get_power_consumption(std::span<PositonInfo> positions) {
		auto gamma_rate_bit = find_most_common_bits(positions);
		int gamma_rate = static_cast<int>(gamma_rate_bit.to_ulong());
		std::cout << "Gamma Rate: " << gamma_rate << '\n';

		auto epsilon_rate_bit = find_least_common_bits(gamma_rate_bit);
		int epsilon_rate = static_cast<int>(epsilon_rate_bit.to_ulong());
		std::cout << "Epsilon Rate: " << epsilon_rate << '\n';

		return gamma_rate * epsilon_rate;
	}

	int get_life_support_rating(DiagnosticData& diagnostic_data) {
		const size_t bit_length = diagnostic_data.position_stats.size();

		auto o2_results = std::make_unique<DiagnosticData>(diagnostic_data);
		auto co2_results = std::make_unique<DiagnosticData>(diagnostic_data);
		for (auto i = 0; i < bit_length; ++i) {
			if (o2_results->diagnostic_lines.size() <= 1 && co2_results->diagnostic_lines.size() <=1) {
				break;
			}

			if (o2_results->diagnostic_lines.size() > 1) {
				char bit_c = most_common_bit(o2_results->position_stats[i], '1');
				auto matches_most_common_bit = [i, bit_c](const std::string line) { return line[i] == bit_c; };
				std::span<std::string> o2_span(o2_results->diagnostic_lines);

				o2_results = filter_lines(o2_span, matches_most_common_bit);
			}

			if (co2_results->diagnostic_lines.size() > 1) {
				char bit_c = least_common_bit(co2_results->position_stats[i], '0');
				auto matches_least_common_bit = [i, bit_c](const std::string line) { return line[i] == bit_c; };
				std::span<std::string> co2_span(co2_results->diagnostic_lines);
				co2_results = filter_lines(co2_span, matches_least_common_bit);
			}
		}

		if (o2_results->diagnostic_lines.empty() || co2_results->diagnostic_lines.empty()) {
			std::string error_text = std::format("O2 Size: {}, CO2 Size: {}", o2_results->diagnostic_lines.size(), co2_results->diagnostic_lines.size());
			std::cerr << "One of the results list was empty" << error_text << '\n';
			throw std::runtime_error(error_text);
		}
		const std::string o2_bit_str{ o2_results->diagnostic_lines[0] };
		const std::string co2_bit_str{ co2_results->diagnostic_lines[0] };

		std::cout << std::format("O2 Result: {}", o2_bit_str) << '\n';
		std::cout << std::format("CO2 Results: {}", co2_bit_str) << '\n';
		return convert_bit_str_to_int(o2_bit_str) * convert_bit_str_to_int(co2_bit_str);
	}

	int get_life_support_rating(std::string file_path) {
		DiagnosticData data = read_and_return_diagnostic_data(file_path);
		return get_life_support_rating(data);
	}

	std::unique_ptr<DiagnosticData> filter_lines(std::span<std::string> diagnostic_lines, std::function<bool(const std::string)> predicate) {
		auto filtered_data = std::make_unique<DiagnosticData>(DiagnosticData{});

		for (auto& line : diagnostic_lines | std::views::filter(predicate)) {

			for (size_t i = 0; i < line.length(); ++i) {
				char bit = line[i];
				if (filtered_data->position_stats.size() != line.length()) {
					filtered_data->position_stats.push_back(PositonInfo{ i, 0, 0 });
				}

				if (bit == '0') {
					filtered_data->position_stats[i].zeros++;
				}
				else if (bit == '1') {
					filtered_data->position_stats[i].ones++;
				}
				else {
					throw std::runtime_error("Unexpected bit: " + bit);
				}
			}
			filtered_data->diagnostic_lines.push_back(line);
		}

		return filtered_data;
	}
}
