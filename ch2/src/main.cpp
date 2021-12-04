#include "dive.hpp"

#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: no input file specified" << "\n\n";
		std::cout << "Usage:" << '\n' << "ch2.exe <input file path>" << '\n';
	}

	std::string file_path{ argv[1] };

	ch2::TravelData travel_data{ ch2::record_travel_data(file_path) };
	int travel_scalar{ ch2::calculate_travel_scaler(travel_data) };

	std::cout << "Travel Scalar: " << travel_scalar << '\n';
	return 0;
}