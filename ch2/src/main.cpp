#include "dive.hpp"

#include <iostream>

int main(int argc, char** argv) {
	std::cout << "Hello World" << "\n";

	std::string up_line{ "up 6" };

	std::tuple<ch2::Direction, int> line_data{ ch2::parse_line(up_line) };

	return 0;
}