#include <bitset>
#include <iostream>
#include "../include/chess.h"

void print_bit_board(const sb board) {
	const std::bitset<64> b_set_board = board;

	for (int i{63}; i >= 0; i--) {
		std::cout << (b_set_board[i] == 1 ? 'X' : '0') << " ";

		if (i % 8 == 0) { std::cout << std::endl; }
	}
}

bool test_valid_moves(const sb board, const sb correct_board, const std::string &test_name) {
	if (board == correct_board) {
		std::cout << "[PASSED] " << test_name << std::endl;
		return true;
	}

	std::cout << "[FAILED] " << test_name << std::endl;
	print_bit_board(board);
	std::cout << std::endl << "output should be:" << std::endl;
	print_bit_board(correct_board);

	return false;
}

int main() {
	std::string failed_tests;
	int passed{0};
	int total{0};

	chess game;

	std::string test_name = "white pawn at index 9, default board";
	uint64_t correct_board = 0x0000000002020000ULL;
	if (test_valid_moves(game.get_valid_moves(9), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/5n2/8/8/8");
	test_name = "black knight at index 26, empty board";
	correct_board = 0x00000A1100110A00ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/5p2/8/8/8");
	test_name = "black pawn at index 26, empty board";
	correct_board = 0x0000000000040000ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/5b2/8/8/8");
	test_name = "black bishop at index 26, empty board";
	correct_board = 0x4020110A000A1120ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/5r2/8/8/8");
	test_name = "black rook at index 26, empty board";
	correct_board = 0x04040404FB040404ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/5q2/8/8/8");
	test_name = "black queen at index 26, empty board";
	correct_board = 0x4424150EFB0E1524ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/5k2/8/8/8");
	test_name = "black king at index 26, empty board";
	correct_board = 0x0000000E0A0E0000ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;
	// --- white pawn (not on rank 8) ---
	game.set_board("8/8/8/8/8/8/8/7P");
	test_name = "white pawn at index 0 (h1), empty board";
	correct_board = 0x0000000000000100ULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/8/8/P7");
	test_name = "white pawn at index 7 (a1), empty board";
	correct_board = 0x0000000000008000ULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- black pawn (not on rank 1) ---
	game.set_board("7p/8/8/8/8/8/8/8");
	test_name = "black pawn at index 56 (h8), empty board";
	correct_board = 0x0001000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("p7/8/8/8/8/8/8/8");
	test_name = "black pawn at index 63 (a8), empty board";
	correct_board = 0x0080000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- knight ---
	game.set_board("8/8/8/8/8/8/8/7N");
	test_name = "knight at index 0 (h1), empty board";
	correct_board = 0x0000000000020400ULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/8/8/N7");
	test_name = "knight at index 7 (a1), empty board";
	correct_board = 0x0000000000402000ULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("7N/8/8/8/8/8/8/8");
	test_name = "knight at index 56 (h8), empty board";
	correct_board = 0x0004020000000000ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("N7/8/8/8/8/8/8/8");
	test_name = "knight at index 63 (a8), empty board";
	correct_board = 0x0020400000000000ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- bishop ---
	game.set_board("8/8/8/8/8/8/8/7B");
	test_name = "bishop at index 0 (h1), empty board";
	correct_board = 0x8040201008040200ULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/8/8/B7");
	test_name = "bishop at index 7 (a1), empty board";
	correct_board = 0x0102040810204000ULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("7B/8/8/8/8/8/8/8");
	test_name = "bishop at index 56 (h8), empty board";
	correct_board = 0x0002040810204080ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("B7/8/8/8/8/8/8/8");
	test_name = "bishop at index 63 (a8), empty board";
	correct_board = 0x0040201008040201ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- rook ---
	game.set_board("8/8/8/8/8/8/8/7R");
	test_name = "rook at index 0 (h1), empty board";
	correct_board = 0x01010101010101FEULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/8/8/R7");
	test_name = "rook at index 7 (a1), empty board";
	correct_board = 0x808080808080807FULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("7R/8/8/8/8/8/8/8");
	test_name = "rook at index 56 (h8), empty board";
	correct_board = 0xFE01010101010101ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("R7/8/8/8/8/8/8/8");
	test_name = "rook at index 63 (a8), empty board";
	correct_board = 0x7F80808080808080ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- queen ---
	game.set_board("8/8/8/8/8/8/8/7Q");
	test_name = "queen at index 0 (h1), empty board";
	correct_board = 0x81412111090503FEULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/8/8/Q7");
	test_name = "queen at index 7 (a1), empty board";
	correct_board = 0x8182848890A0C07FULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("7Q/8/8/8/8/8/8/8");
	test_name = "queen at index 56 (h8), empty board";
	correct_board = 0xFE03050911214181ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("Q7/8/8/8/8/8/8/8");
	test_name = "queen at index 63 (a8), empty board";
	correct_board = 0x7FC0A09088848281ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- king ---
	game.set_board("8/8/8/8/8/8/8/7K");
	test_name = "king at index 0 (h1), empty board";
	correct_board = 0x0000000000000302ULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/8/8/K7");
	test_name = "king at index 7 (a1), empty board";
	correct_board = 0x000000000000C040ULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("7K/8/8/8/8/8/8/8");
	test_name = "king at index 56 (h8), empty board";
	correct_board = 0x0203000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("K7/8/8/8/8/8/8/8");
	test_name = "king at index 63 (a8), empty board";
	correct_board = 0x40C0000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"); // default

	// --- white pawns (rank 2, indices 8-15) ---
	test_name = "white pawn at index 8 (h2), default board";
	correct_board = 0x0000000001010000ULL;
	if (test_valid_moves(game.get_valid_moves(8), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 9 (g2), default board";
	correct_board = 0x0000000002020000ULL;
	if (test_valid_moves(game.get_valid_moves(9), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 10 (f2), default board";
	correct_board = 0x0000000004040000ULL;
	if (test_valid_moves(game.get_valid_moves(10), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 11 (e2), default board";
	correct_board = 0x0000000008080000ULL;
	if (test_valid_moves(game.get_valid_moves(11), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 12 (d2), default board";
	correct_board = 0x0000000010100000ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 13 (c2), default board";
	correct_board = 0x0000000020200000ULL;
	if (test_valid_moves(game.get_valid_moves(13), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 14 (b2), default board";
	correct_board = 0x0000000040400000ULL;
	if (test_valid_moves(game.get_valid_moves(14), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white pawn at index 15 (a2), default board";
	correct_board = 0x0000000080800000ULL;
	if (test_valid_moves(game.get_valid_moves(15), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- black pawns (rank 7, indices 48-55) ---
	test_name = "black pawn at index 48 (h7), default board";
	correct_board = 0x0000010100000000ULL;
	if (test_valid_moves(game.get_valid_moves(48), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 49 (g7), default board";
	correct_board = 0x0000020200000000ULL;
	if (test_valid_moves(game.get_valid_moves(49), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 50 (f7), default board";
	correct_board = 0x0000040400000000ULL;
	if (test_valid_moves(game.get_valid_moves(50), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 51 (e7), default board";
	correct_board = 0x0000080800000000ULL;
	if (test_valid_moves(game.get_valid_moves(51), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 52 (d7), default board";
	correct_board = 0x0000101000000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 53 (c7), default board";
	correct_board = 0x0000202000000000ULL;
	if (test_valid_moves(game.get_valid_moves(53), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 54 (b7), default board";
	correct_board = 0x0000404000000000ULL;
	if (test_valid_moves(game.get_valid_moves(54), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black pawn at index 55 (a7), default board";
	correct_board = 0x0000808000000000ULL;
	if (test_valid_moves(game.get_valid_moves(55), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- white pieces on rank 1 (all blocked except knights) ---
	test_name = "white rook at index 0 (h1), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(0), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white knight at index 1 (g1), default board";
	correct_board = 0x0000000000050000ULL;
	if (test_valid_moves(game.get_valid_moves(1), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white bishop at index 2 (f1), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(2), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white king at index 3 (e1), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(3), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white queen at index 4 (d1), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white bishop at index 5 (c1), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(5), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white knight at index 6 (b1), default board";
	correct_board = 0x0000000000A00000ULL;
	if (test_valid_moves(game.get_valid_moves(6), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "white rook at index 7 (a1), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(7), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- black pieces on rank 8 (all blocked except knights) ---
	test_name = "black rook at index 56 (h8), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(56), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black knight at index 57 (g8), default board";
	correct_board = 0x0000050000000000ULL;
	if (test_valid_moves(game.get_valid_moves(57), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black bishop at index 58 (f8), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(58), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black king at index 59 (e8), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(59), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black queen at index 60 (d8), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black bishop at index 61 (c8), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(61), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	print_bit_board(game.get_table_lookup(54));

	test_name = "black knight at index 62 (b8), default board";
	correct_board = 0x0000A00000000000ULL;
	if (test_valid_moves(game.get_valid_moves(62), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	test_name = "black rook at index 63 (a8), default board";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(63), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	std::cout << "Passed: " << passed << "/" << total << std::endl;
	std::cout << std::endl;
	std::cout << "Failed:\n" << failed_tests << std::endl;

	return 0;
}
