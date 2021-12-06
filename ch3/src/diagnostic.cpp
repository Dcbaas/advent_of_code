#include "diagnostic.hpp"

#include <boost/dynamic_bitset.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
//#include <ranges>
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

	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions) {
		std::string buffer{ "" };
		for (const auto& position_info : positions) {
			if (position_info.ones > position_info.zeros) {
				buffer.append("1");
			}
			else {
				buffer.append("0");
			}
		}

		return boost::dynamic_bitset<block_t>(buffer);
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

	int get_02_rating(DiagnosticData& diagnostic_data) {
		std::span<PositonInfo> position_stats{ diagnostic_data.position_stats };
		auto most_common_bits = find_most_common_bits(position_stats);

		//auto result = static_cast<bool>(most_common_bits[0]);

		namespace ranges = std::ranges;
		std::vector<const std::string> working_results(diagnostic_data.diagnostic_lines);
		for (auto i = 0; i < most_common_bits.size(); ++i) {
			bool bit = static_cast<bool>(most_common_bits[i]);
			char bit_c = bit ? '1' : '0';
			auto matches_most_common_bit = [i, bit_c](std::string line) { return line[i] == bit_c; };
		
		}
		return 0;
	}

	int get_life_support_rating(DiagnosticData& diagnostic_data) {
		// Save on namespace
		namespace ranges = std::ranges;

		std::span<PositonInfo> position_stats{ diagnostic_data.position_stats };
		auto most_common_bits = find_most_common_bits(position_stats);

		//auto result = static_cast<bool>(most_common_bits[0]);

		std::vector<const std::string> o2_results(diagnostic_data.diagnostic_lines.size());
		std::vector<const std::string> co2_results(diagnostic_data.diagnostic_lines.size());
		for (auto i = 0; i < most_common_bits.size(); ++i) {
			bool bit = static_cast<bool>(most_common_bits[i]);
			char bit_c = bit ? '1' : '0';
			auto matches_most_common_bit = [i, bit_c](std::string line) { return line[i] == bit_c; };
			auto matches_least_common_bit = [i, bit_c](std::string line) { return line[i] != bit_c; };
	
			//if (o2_results.empty() && co2_results.empty()) {
			//	auto begin = diagnostic_data.diagnostic_lines.begin();
			//	auto end = diagnostic_data.diagnostic_lines.end();
			//	ranges::copy_if(begin, end, std::back_inserter(o2_results), matches_most_common_bit);
			//	ranges::copy_if(begin, end, std::back_inserter(co2_results), matches_most_common_bit);
			//}
			//else {
			//	ranges::copy_if(o2_results, std::back_inserter(o2_results), matches_most_common_bit);
			//	ranges::copy_if(co2_results, std::back_inserter(co2_results), matches_most_common_bit);
			//}
		}
		return 0;
	}
}
