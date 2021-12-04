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
	
	auto [travel_scalar_pt1, duration] = common::time_solve_duration<int>(pt1Function);

	std::cout << "Part1. Travel Scalar: " << travel_scalar_pt1 << " Duration: " << duration << '\n';
	return 0;
}