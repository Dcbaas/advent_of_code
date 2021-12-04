#ifndef FILE_READER_H
#define FILE_READER_H

#include <functional>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace file_utils {

	template <typename T>
	std::vector<T> read_line_data(std::string path, std::function <T(std::string&)> parser) {
		std::ifstream file(path);

		if (!file.good()) {
			std::runtime_error("File failed to open: " + path);
		}

		std::vector<T> lines;
		std::string buffer;
		while (!file.eof()) {
			std::getline(file, buffer);
			lines.push_back(parser(buffer));
		}

		return lines;
	}

}
#endif // !FILE_READER_H
