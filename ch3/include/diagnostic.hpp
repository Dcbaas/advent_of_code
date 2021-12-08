#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <boost/dynamic_bitset.hpp>
#include <functional>
#include <memory>
#include <optional>
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


	char most_common_bit(const PositonInfo& pos_info, char tie_bit);
	char least_common_bit(const PositonInfo& pos_info, char tie_bit);

	struct DiagnosticData {
		std::vector<PositonInfo> position_stats;
		std::vector<std::string> diagnostic_lines;
	};

	std::vector<PositonInfo> read_diagnostic_data(std::string file_path);
	DiagnosticData read_and_return_diagnostic_data(std::string file_path);

	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions);
	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions, char tie_bit);
	boost::dynamic_bitset<block_t> find_most_common_bits(std::span<PositonInfo> positions, std::optional<std::string> tie_bit);
	inline boost::dynamic_bitset<block_t> find_least_common_bits(boost::dynamic_bitset<block_t> most_common_bits) { return most_common_bits.flip(); };

	inline int convert_bit_str_to_int(const std::string& bit_str) { return static_cast<int>(boost::dynamic_bitset<block_t>(bit_str).to_ulong()); }

	int get_power_consumption(std::span<PositonInfo> positions);
	int get_life_support_rating(DiagnosticData& diagnostic_data);
	int get_life_support_rating(std::string file_path);

	std::unique_ptr<DiagnosticData> filter_lines(std::span<std::string> diagnostic_lines, std::function<bool(const std::string)> predicate);
}
#endif // !DIAGNOSTIC_H
