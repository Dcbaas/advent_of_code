#include "dive.hpp"
#include "time_track.hpp"

#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: no input file specified" << "\n\n";
		std::cout << "Usage:" << '\n' << "ch2.exe <input file path>" << '\n';
		return 1;
	}

	std::string file_path{ argv[1] };
	//std::string file_path{ "input\\travel_data.txt" };

	auto pt1Function = [&file_path]() {
		ch2::TravelData travel_data{ ch2::record_travel_data(file_path) };
		return ch2::calculate_travel_scaler(travel_data);
	};

	auto pt2Function = [&file_path]() {
		ch2::TravelData travel_data{ ch2::record_travel_data_with_aim(file_path) };
		return ch2::calculate_travel_scaler(travel_data);
	};
	
	auto [travel_scalar_pt1, duration] = common::time_solve_duration<int>(pt1Function);
	auto [travel_scalar_pt2, duration2] = common::time_solve_duration<int>(pt2Function);

	std::cout << "Part1. Travel Scalar: " << travel_scalar_pt1 << " Duration: " << duration << '\n';
	std::cout << "Part2. Travel Scalar: " << travel_scalar_pt2 << " Duration: " << duration2 << '\n';
	return 0;
}