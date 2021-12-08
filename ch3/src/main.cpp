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
		auto power_consumption_rate = ch3::get_power_consumption(span);
		return power_consumption_rate;
	};

	auto p2Execution = [&file_path]() {
		return ch3::get_life_support_rating(file_path);
	};

	auto [result, duration] = common::time_solve_duration<int>(p1Execution);
	auto [result2, duration2] = common::time_solve_duration<int>(p2Execution);


	std::cout << "Part1. Power Consumption: " << result << " Duration: " << duration << '\n';
	std::cout << "Part2. Life Support Rating: " << result2 << " Duration: " << duration2 << '\n';

	return 0;
}