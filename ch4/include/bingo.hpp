#ifndef BINGO_H
#define BINGO_H

#include <concepts>
#include <optional>
#include <string>
#include <set>
#include <span>
#include <tuple>
#include <vector>

namespace ch4 {

	

	struct BingoSpace {
		int value;
		bool marked;
	};

	enum class VictoryType { row, column };

	class BingoBoard {
	public: 
		BingoBoard(std::string board_data);

		bool record_number(int value);
		const size_t numbers_recorded() const { return recorded_numbers.size(); };
		const unsigned int get_score() const;
		std::optional<std::tuple<VictoryType, std::span<int>>> get_winning_numbers() const;

	private:

		bool check_victory_conditions();
		// Inner vec is columns, outer vec is rows 
		std::vector<std::vector<BingoSpace> > board;
		std::set<int> recorded_numbers;
		std::optional<std::tuple<VictoryType, std::vector<int>>> winning_combination;
		bool has_bingo;
	};
}
#endif // !BINGO_H
