#include "sonar.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: no input file specified" << "\n\n";
		std::cout << "Usage:" << '\n' << "ch1.exe <input file path>" << '\n';
	}

	std::string file_path{ argv[1] };

	unsigned int total_increases{ ch1::count_depth_increases(file_path) };

	std::cout << "Depth increased a total of " << total_increases << " times." << "\n";

	return 0;
}