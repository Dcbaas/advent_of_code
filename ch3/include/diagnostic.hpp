#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <bitset>
#include <span>
#include <string>
#include <vector>

namespace ch3 {
	struct PositonInfo {
		size_t position;
		size_t ones;
		size_t zeros;
	};

	std::vector<PositonInfo> read_diagnostic_data(std::string file_path);
	std::bitset<64> calculate_gamma_rate_bit_set(std::span<PositonInfo> positions);
	std::bitset<64> calculate_epsilon_rate_bit_set(std::bitset<64> gamma_rate);
	unsigned long get_power_consumption(const std::bitset<64>& gamma_rate, const std::bitset<64>& epsilon_rate);

	void print_span(std::span<PositonInfo> my_span);
}
#endif // !DIAGNOSTIC_H
