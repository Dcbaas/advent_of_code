#include "diagnostic.hpp"

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

		std::vector<PositonInfo> positions;

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

	std::bitset<64> calculate_gamma_rate_bit_set(std::span<PositonInfo> positions) {
		std::vector<char> bit_str(positions.size());

		for (const auto& position : positions) {
			bit_str.push_back(position.ones < position.zeros ? '0' : '1');
		}


		return std::bitset<64>(bit_str.data());
	}

	// Does this destroy the gamma rate? even if its pass by value? 
	std::bitset<64> calculate_epsilon_rate_bit_set(std::bitset<64> gamma_rate) {

		return gamma_rate.flip();
	}

	unsigned long get_power_consumption(const std::bitset<64>& gamma_rate, const std::bitset<64>& epsilon_rate) {
		return gamma_rate.to_ulong() * epsilon_rate.to_ulong();
	}

	void print_span(std::span<PositonInfo> my_span) {
		for (const auto& position : my_span) {
			std::cout << "Position: " << position.position << '\n';
		}
	}

}
