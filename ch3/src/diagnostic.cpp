#include "diagnostic.hpp"

#include <vector>


namespace ch3 {

	std::bitset<64> calculate_gamma_rate_bit_set(std::span<PositonInfo> positions) {
		std::vector<char> bit_str(positions.size());

		for (auto position : positions) {
			bit_str.push_back(position.ones < position.zeros ? '0' : '1');
		}


		return std::bitset<64>(bit_str.data());
	}

	// Does this destroy the gamma rate? 
	std::bitset<64> calculate_epsilon_rate_bit_set(std::bitset<64> gamma_rate) {

		return gamma_rate.flip();
	}

}
