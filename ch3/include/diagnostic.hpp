#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <boost/dynamic_bitset.hpp>
#include <functional>
#include <span>
#include <string>
#include <tuple>
#include <vector>

namespace ch3 {
	using block_t = unsigned short;

	struct PositonInfo {
		size_t position;
		size_t ones;
		size_t zeros;
	};

	struct DiagnosticData {
		std::vector<PositonInfo> position_stats;
		std::vector<std::string> diagnostic_lines;
	};

	std::vector<PositonInfo> read_diagnostic_data(std::string file_path);
	DiagnosticData read_and_return_diagnostic_data(std::string file_path);

	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions);
	inline boost::dynamic_bitset<block_t> find_least_common_bits(boost::dynamic_bitset<block_t> most_common_bits) { return most_common_bits.flip(); };

	int get_power_consumption(std::span<PositonInfo> positions);

	int get_life_support_rating(DiagnosticData& diagnostic_data);
	int get_life_support_rating(std::string file_path);

	std::vector<std::string> filter_lines(std::span<std::string> diagnostic_lines, std::function<bool(const std::string)> predicate);
}
#endif // !DIAGNOSTIC_H
