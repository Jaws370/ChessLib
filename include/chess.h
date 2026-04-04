#pragma once

#include "game_data.h"
#include "types.h"

#include <string>

class chess {
	game_data gd;

	lookup_tables lookup_table;
	between_tables between_table;

	void set_game_data(const std::string &fen);
	void table_init();
	void minimax();

public:
	explicit chess(const std::string &fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	void move(const int old_pos, const int new_pos) { gd.move(old_pos, new_pos, lookup_table, between_table); }
	void ai_move();

	void check_move(const int old_pos, const int new_pos);
	void get_board();
};
