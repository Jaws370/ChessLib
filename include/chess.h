#pragma once

#include "game_data.h"
#include "types.h"

#include <string>

class chess {
	table_bundle tables;

	game_data gd;

	piece_color p1_color;
	piece_color p2_color;

	int minimax(game_data pseudo_gd, int depth, bool is_maximizing);

public:
	explicit chess(const std::string &fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	void move(const int old_pos, const int new_pos) {
		gd.move(old_pos, new_pos, tables.lookup_table, tables.between_table);
	}

	void ai_move(int depth);

	bool check_move(int old_pos, int new_pos);

	sb get_valid_moves(const int pos) { return gd.get_valid_moves(pos, tables.lookup_table, tables.between_table); }

	[[nodiscard]] sb get_table_lookup(const int pos) const {
		sb result = 0;
		for (int i = 0; i < 8; i++) result |= tables.lookup_table.queen_table[pos][i];
		return result;
	}

	[[nodiscard]] sb get_between_table(const int pos1, const int pos2) const {
		return tables.between_table[pos1][pos2];
	}

	void set_board(const std::string &fen) { gd.set(fen, tables.lookup_table, tables.between_table); };
	[[nodiscard]] std::string get_board() const { return gd.get(); };
};
