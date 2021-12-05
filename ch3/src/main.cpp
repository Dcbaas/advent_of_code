#include "diagnostic.hpp"
#include "time_track.hpp"

#include <iostream>
#include <string>
#include <span>
#include <vector>

int main(int argc, char** argv) {
	//if (argc < 2) {
	//	std::cout << "Error: no input file specified" << "\n\n";
	//	std::cout << "Usage:" << '\n' << "ch3.exe <input file path>" << '\n';
	//	return 1;
	//}

	//std::string file_path{ argv[1] };
	std::string file_path{ "C:\\dev\\Projects\\advent_of_code\\ch3\\input\\sample_diagnostic.txt" };

	auto p1Execution = [&file_path]() {
		std::vector<ch3::PositonInfo> positions = ch3::read_diagnostic_data(file_path);
		std::span<ch3::PositonInfo> span{ positions };
		auto gamma_rate = ch3::calculate_gamma_rate_bit_set(span);
		auto epsilon_rate = ch3::calculate_epsilon_rate_bit_set(gamma_rate);
		return ch3::get_power_consumption(gamma_rate, epsilon_rate);
	};

	auto [result, duration] = common::time_solve_duration<unsigned long>(p1Execution);


	std::cout << "Part1. Power Consumption: " << result << " Duration: " << duration << '\n';

	return 0;
}