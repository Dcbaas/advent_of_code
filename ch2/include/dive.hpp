#ifndef DIVE_H
#define DIVE_H

#include <string>
#include <tuple>

namespace ch2 {
	struct TravelData {
		int horizontal;
		int depth;
		int aim;
	};

	enum class Direction : char {
		forward = 'f',
		up = 'u',
		down = 'd'
	};

	TravelData record_travel_data(std::string& file_path);

	TravelData record_travel_data_with_aim(std::string& file_path);

	std::tuple<Direction, int> parse_line(std::string& line);

	int calculate_travel_scaler(TravelData& travel_data);
}
#endif // !DIVE_H
