#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <bitset>
#include <span>

namespace ch3 {
	struct PositonInfo {
		size_t position;
		size_t ones;
		size_t zeros;
	};

	std::bitset<64> calculate_gamma_rate_bit_set(std::span<PositonInfo> positions);
	std::bitset<64> calculate_epsilon_rate_bit_set(int gamma_rate);


}
#endif // !DIAGNOSTIC_H
