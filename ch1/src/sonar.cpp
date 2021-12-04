#include "sonar.hpp"
#include "file_utils.hpp"

#include <sstream>

namespace ch1 {
	unsigned int count_depth_increases(std::string& file_path) {
		unsigned int total_increases{ 0 };
		int previous{ -1 };
		auto parser = [&total_increases, &previous](std::string& line) {
			std::stringstream stream(line);
			int current_depth{ 0 };
			stream >> current_depth;
			if (previous != -1 && previous < current_depth) {
				total_increases++;
			}

			previous = current_depth;

			return current_depth;
		};

		auto lines = file_utils::read_line_data<int>(file_path, parser);

		return total_increases;
	}
}