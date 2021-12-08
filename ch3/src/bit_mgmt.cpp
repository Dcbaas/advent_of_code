#include "diagnostic.hpp"

#include <iostream>
#include <stdexcept>

namespace ch3 {

	char most_common_bit(const PositonInfo& pos_info, char tie_bit) {
		if (pos_info.zeros == pos_info.ones) {
			return tie_bit;
		}
		return pos_info.ones > pos_info.zeros ? '1' : '0';
	}

	char least_common_bit(const PositonInfo& pos_info, char tie_bit) {
		if (pos_info.zeros == pos_info.ones) {
			return tie_bit;
		}
		else if (pos_info.ones == 0 || pos_info.zeros == 0) {
			// Use the only bit availibe in the position. Otherwise when filtering the result set becomes empty.
			return most_common_bit(pos_info, tie_bit);
		}
		return pos_info.ones > pos_info.zeros ? '0' : '1';
	}

	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions) {
		return find_most_common_bits(positions, std::nullopt);
	}

	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions, char tie_bit) {
		if (tie_bit != '0' && tie_bit != '1') {
			std::cerr << " tie_bit was not 0 or 1. tie_bit: " << tie_bit << '\n';
			throw std::runtime_error("Invalid Tie Bit");
		}

		return find_most_common_bits(positions, std::make_optional(std::string{ tie_bit }));
	}

	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions, std::optional<std::string> tie_bit) {
		std::string buffer{ "" };
		for (const auto& position_info : positions) {
			if (tie_bit && position_info.ones == position_info.zeros) {
				buffer.append(tie_bit.value());
			}
			else if (position_info.ones > position_info.zeros) {
				buffer.append("1");
			}
			else {
				buffer.append("0");
			}
		}

		return boost::dynamic_bitset<block_t>(buffer);
	}


}