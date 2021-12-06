#include "diagnostic.hpp"

#include <boost/dynamic_bitset.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <span>


namespace ch3 {

	std::vector<PositonInfo> read_diagnostic_data(std::string file_path) {
		std::ifstream file(file_path);

		if (!file.good()) {
			std::cerr << "Failed to open file: " << file_path;
			throw std::runtime_error("File Failure");
		}

		std::vector<PositonInfo> positions{};

		std::string buffer;
		while (!file.eof()) {
			std::getline(file, buffer);

			if (buffer == "") {
				continue;
			}

			for (size_t i = 0; i < buffer.length(); ++i) {
				char bit = buffer[i];
				if (positions.size() != buffer.length()) {
					positions.push_back(PositonInfo{ i, 0, 0 });
				}

				if (bit == '0') {
					positions[i].zeros++;
				}
				else if (bit == '1') {
					positions[i].ones++;
				}
				else {
					throw std::runtime_error("Unexpected bit: " + bit);
				}

			}
		}

		return positions;
	}

	int get_power_consumption(std::span<PositonInfo> positions) {
		std::string test_str{ "10110" };
		boost::dynamic_bitset<unsigned int> test1(test_str);

		std::string buffer{ "" };
		for (const auto& position_info : positions) {
			if (position_info.ones > position_info.zeros) {
				buffer.append("1");
			}
			else {
				buffer.append("0");
			}
		}
		boost::dynamic_bitset<unsigned int> gamma_rate_bit(buffer);
		int gamma_rate = static_cast<int>(gamma_rate_bit.to_ulong());
		std::cout << "Gamma Rate: " << gamma_rate << '\n';

		boost::dynamic_bitset<unsigned int> epsilon_rate_bit = gamma_rate_bit.flip();
		int epsilon_rate = static_cast<int>(epsilon_rate_bit.to_ulong());
		std::cout << "Epsilon Rate: " << epsilon_rate << '\n';

		return gamma_rate * epsilon_rate;
	}
}
