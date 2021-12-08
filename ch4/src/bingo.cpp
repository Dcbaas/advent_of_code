#include "bingo.hpp"

#include <ranges>
#include <sstream>

namespace ch4 {
	BingoBoard::BingoBoard(std::string board_data) : winning_combination(std::nullopt), has_bingo(false) {
		constexpr char row_delim{ '\n' };
		constexpr char col_delim{ ' ' };

		size_t row_pos{ 0 };
		std::string row_str;
		while ((row_pos = board_data.find(row_delim)) != std::string::npos) {
			row_str = board_data.substr(0, row_pos);

			std::vector<BingoSpace> bingo_spaces;

			size_t col_position{ 0 };
			std::string column;
			int value;
			while ((col_position = board_data.find(col_delim)) != std::string::npos) {
				column = row_str.substr(0, col_position);
				std::stringstream stream(column);
				stream >> value;
				bingo_spaces.push_back(BingoSpace{ value, false });
				row_str.erase(0, col_position + 1);
			}
			bingo_spaces.shrink_to_fit();
			board.push_back(bingo_spaces);
			board_data.erase(0, row_pos + 1);
		}
	}

	bool BingoBoard::check_victory_conditions() {
		// Check for victory rows first
		for (const auto& row : board) {
			auto marks = row | std::views::transform([](const BingoSpace space) { return space.marked; });
			std::set<bool> distinct_marks(marks.begin(), marks.end());
			if (distinct_marks.contains(true) && !distinct_marks.contains(false)) {
				// We have a winning board
				auto winning_numbers = row | std::views::transform([](const BingoSpace space) { return space.value; });
				std::ranges::to
			}
			

		}

		return false;
	}

}