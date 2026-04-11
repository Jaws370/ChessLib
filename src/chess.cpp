#include "../include/chess.h"

#include <iostream>
#include <random>

bool chess::check_move(const int old_pos, const int new_pos) {
	const sb valid_moves = gd.get_valid_moves(old_pos, tables.lookup_table, tables.between_table);
	const sb b_new_pos = sb{1} << new_pos;

	if (valid_moves & b_new_pos) { return true; }

	return false;
}

int chess::minimax(game_data pseudo_gd, const int depth, const bool is_maximizing) {
	if (depth == 0) {
		// || is_check_mate(); )
		return pseudo_gd.evaluate_position();
	}

	if (is_maximizing) {
		int best_score{INT_MIN};

		while (pseudo_gd.white_board) {
			const int piece_index = __builtin_ctzll(pseudo_gd.white_board);
			sb valid_moves = pseudo_gd.get_valid_moves(piece_index, tables.lookup_table, tables.between_table);

			// go through all valid moves for the piece
			while (valid_moves) {
				const int move_index = __builtin_ctzll(valid_moves);
				game_data new_pseudo_gd = pseudo_gd;

				new_pseudo_gd.move(piece_index, move_index, tables.lookup_table, tables.between_table);

				// check if the new move is good
				const int result = minimax(new_pseudo_gd, depth - 1, false);
				best_score = std::max(best_score, result);

				valid_moves &= ~(sb{1} << move_index);
			}

			pseudo_gd.white_board &= ~(sb{1} << piece_index);
		}

		return best_score;
	} else {
		int best_score{INT_MAX};

		while (pseudo_gd.black_board) {
			const int piece_index = __builtin_ctzll(pseudo_gd.black_board);
			sb valid_moves = pseudo_gd.get_valid_moves(piece_index, tables.lookup_table, tables.between_table);

			// go through all valid moves for the piece
			while (valid_moves) {
				const int move_index = __builtin_ctzll(valid_moves);
				game_data new_pseudo_gd = pseudo_gd;

				new_pseudo_gd.move(piece_index, move_index, tables.lookup_table, tables.between_table);

				// check if the new move is good
				const int result = minimax(new_pseudo_gd, depth - 1, true);
				best_score = std::min(best_score, result);

				valid_moves &= ~(sb{1} << move_index);
			}

			pseudo_gd.black_board &= ~(sb{1} << piece_index);
		}

		return best_score;
	}
}

void chess::ai_move(const int depth) {
	bool is_maximizing{false};

	if (p2_color == piece_color::WHITE) { is_maximizing = true; }

	game_data pseudo_gd = gd;
	std::pair<int, int> best_move{-1, -1};

	if (is_maximizing) {
		// get the best move
		int best_score{INT_MIN};

		while (pseudo_gd.white_board) {
			const int piece_index = __builtin_ctzll(pseudo_gd.white_board);
			sb valid_moves = pseudo_gd.get_valid_moves(piece_index, tables.lookup_table, tables.between_table);

			// go through all valid moves for the piece
			while (valid_moves) {
				const int move_index = __builtin_ctzll(valid_moves);
				game_data new_pseudo_gd = pseudo_gd;

				new_pseudo_gd.move(piece_index, move_index, tables.lookup_table, tables.between_table);

				// check if the new move is good
				const int result = minimax(new_pseudo_gd, depth - 1, false);
				if (result > best_score) {
					best_move = std::make_pair(piece_index, move_index);
					best_score = result;
				}

				valid_moves &= ~(sb{1} << move_index);
			}

			pseudo_gd.white_board &= ~(sb{1} << piece_index);
		}
	} else {
		// get the best move
		int best_score{INT_MAX};

		while (pseudo_gd.black_board) {
			const int piece_index = __builtin_ctzll(pseudo_gd.black_board);
			sb valid_moves = pseudo_gd.get_valid_moves(piece_index, tables.lookup_table, tables.between_table);

			// go through all valid moves for the piece
			while (valid_moves) {
				const int move_index = __builtin_ctzll(valid_moves);
				game_data new_pseudo_gd = pseudo_gd;

				new_pseudo_gd.move(piece_index, move_index, tables.lookup_table, tables.between_table);

				// check if the new move is good
				const int result = minimax(new_pseudo_gd, depth - 1, true);
				if (result < best_score) {
					best_move = std::make_pair(piece_index, move_index);
					best_score = result;
				}

				valid_moves &= ~(sb{1} << move_index);
			}

			pseudo_gd.black_board &= ~(sb{1} << piece_index);
		}
	}

	// make the best move
	if (best_move.first == -1 || best_move.second == -1) {
		std::cerr << "AI ERROR: NO BEST MOVE FOUND" << std::endl;
		return;
	}

	move(best_move.first, best_move.second);
}

chess::chess(const std::string &fen): gd(fen, tables.lookup_table, tables.between_table) {
	// randomly assign colors
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution dist(0, 1);
	int color = dist(rng);

	p1_color = static_cast<piece_color>(color);
	p2_color = static_cast<piece_color>(1 - color);
}
