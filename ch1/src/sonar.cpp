#include "sonar.hpp"

#include <fstream>
#include <numeric>
#include <vector>
#include <sstream>
#include <stdexcept>

namespace ch1 {

	int count_depth_increases(std::string& file_path) {
		std::ifstream file(file_path);
		if (!file.good()) {
			throw std::runtime_error("File failed to open: " + file_path);
		}
		std::string buffer;

		int total_increases{ 0 };
		int previous_depth{ -1 };
		int current_depth;

		while (!file.eof()) {
			std::getline(file, buffer);
			std::stringstream stream(buffer);
			stream >> current_depth;

			if (previous_depth != -1 && previous_depth < current_depth) {
				total_increases++;
			}

			previous_depth = current_depth;
		}

		return total_increases;
	}

	int count_depth_window_increases(std::string& file_path) {
		int total_increases{ 0 };

		std::ifstream file(file_path);
		if (!file.good()) {
			throw std::runtime_error("File failed to open: " + file_path);
		}

		std::vector<int> depths;
		auto adjust_window = [&depths](int current_depth) {
			constexpr int WINDOW_SIZE = 3;
			depths.push_back(current_depth);

			if (depths.size() < WINDOW_SIZE) {
				// Don't calculate a sum until the window is full
				return -1;
			}

			auto window_end{ depths.end() };
			auto window_start{ window_end - 3};
			return std::accumulate(window_start, window_end, 0);
		};

		int previous_depth_sum = -1;

		std::string buffer;
		int current_depth;
		int current_depth_sum;
		while (!file.eof()) {
			std::getline(file, buffer);
			std::stringstream stream(buffer);
			stream >> current_depth;
			current_depth_sum = adjust_window(current_depth);

			if (previous_depth_sum != -1 && previous_depth_sum < current_depth_sum) {
				total_increases++;
			}
			previous_depth_sum = current_depth_sum;
		}

		return total_increases;
	}
}
