#include "dive.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>


namespace ch2 {
	TravelData record_travel_data(std::string& file_path) {
		std::ifstream file(file_path);
		if (!file.good()) {
			throw std::runtime_error("File failed to open: " + file_path);
		}

		TravelData travel_data{ 0,0 };

		std::string buffer;
		while (!file.eof()) {
			std::getline(file, buffer);
			auto [direction, distance] = parse_line(buffer);
			switch (direction) {
			case Direction::forward:
				travel_data.horizontal += distance;
				break;
			case Direction::down:
				travel_data.depth += distance;
				break;
			case Direction::up:
				travel_data.depth -= distance;
				break;
			default:
				throw std::runtime_error("Unknown Direction");
			}
		}

		return travel_data;
	}

	std::tuple<Direction, int> parse_line(std::string& line) {
		constexpr char delimiter = ' ';
		int distance;

		auto position{ line.find(delimiter) };
		auto direction{ static_cast<Direction>(line.substr(0, position)[0])};
		auto len_str{ line.substr(position + 1) };
		std::stringstream stream(len_str);
		 
		stream >> distance;
		return std::make_tuple(direction, distance);
	}

	int calculate_travel_scaler(TravelData& travel_data) {
		return travel_data.horizontal * travel_data.depth;
	}
}