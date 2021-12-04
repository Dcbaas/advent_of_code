#include "sonar.hpp"
#include "time_track.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: no input file specified" << "\n\n";
		std::cout << "Usage:" << '\n' << "ch1.exe <input file path>" << '\n';
		return 1;
	}

	std::string file_path{ argv[1] };

	// Pt 1 Timed
	auto [total_increases_pt1, duration] = common::time_solve_duration<int>([&file_path]() {return ch1::count_depth_increases(file_path); });
	auto [total_increases_pt2, duration2] = common::time_solve_duration<int>([&file_path]() {return ch1::count_depth_window_increases(file_path); });



	//std::cout << "Depth increased a total of " << total_increases << " times." << "\n";
	std::cout << "Part1. Depth Increases: " << total_increases_pt1 << " Duration: " << duration << '\n';
	std::cout << "Part2. Depth Increases: " << total_increases_pt2 << " Duration: " << duration2 << '\n';

	return 0;
}