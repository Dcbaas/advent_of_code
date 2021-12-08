#ifndef BINGO_H
#define BINGO_H

#include <string>
#include <set>
#include <span>
#include <vector>

namespace ch4 {
	struct BingoSpace {
		int value;
		bool marked;
	};
	class BingoBoard {
	public: 
		BingoBoard(std::string board_data);

		bool record_number(int value);
		int get_score();
		std::vector<int> winning_numbers();

	private:

		bool check_victory_conditions();
		// Inner vec is columns, outer vec is rows 
		std::vector<std::vector<BingoSpace> > board;
		std::set<const int> recorded_numbers;
		std::vector<std::span<int> > winning_combinations;
		bool has_bingo;
	};
}
#endif // !BINGO_H
