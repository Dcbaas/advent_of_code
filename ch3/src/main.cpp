#include "diagnostic.hpp"
#include "time_track.hpp"

#include <iostream>
#include <string>
#include <span>
#include <vector>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: no input file specified" << "\n\n";
		std::cout << "Usage:" << '\n' << "ch3.exe <input file path>" << '\n';
		return 1;
	}

	std::string file_path{ argv[1] };

	auto p1Execution = [&file_path]() {
		std::vector<ch3::PositonInfo> positions = ch3::read_diagnostic_data(file_path);
		std::span<ch3::PositonInfo> span{ positions };
		//std::bitset<64> gamma_rate_bit = ch3::calculate_gamma_rate_bit_set(span);
		std::bitset <64> gamma_rate{ "10110" };
		ch3::print_span(span);
		//std::bitset<64> epsilon_rate_bit = ch3::calculate_epsilon_rate_bit_set(gamma_rate_bit);
		//return ch3::get_power_consumption(gamma_rate_bit, epsilon_rate_bit);
		return 45L;
	};

	auto [result, duration] = common::time_solve_duration<unsigned long>(p1Execution);


	std::cout << "Part1. Power Consumption: " << result << " Duration: " << duration << '\n';

	return 0;
}