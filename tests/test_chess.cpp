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

	// =====================
	// ON THE WALL
	// =====================

	// --- white pawn ---
	game.set_board("8/8/8/8/8/8/8/3P4");
	test_name = "white pawn at index 4 (d1), empty board";
	correct_board = 0x0000000000001000ULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/P7/8/8/8");
	test_name = "white pawn at index 31 (a4), empty board";
	correct_board = 0x0000008000000000ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7P/8/8/8");
	test_name = "white pawn at index 24 (h4), empty board";
	correct_board = 0x0000000100000000ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- black pawn ---
	game.set_board("8/8/8/8/p7/8/8/8");
	test_name = "black pawn at index 31 (a4), empty board";
	correct_board = 0x0000000000800000ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("3p4/8/8/8/8/8/8/8");
	test_name = "black pawn at index 60 (d8), empty board";
	correct_board = 0x0010000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7p/8/8/8");
	test_name = "black pawn at index 24 (h4), empty board";
	correct_board = 0x0000000000010000ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- knight ---
	game.set_board("8/8/8/8/8/8/8/3N4");
	test_name = "knight at index 4 (d1), empty board";
	correct_board = 0x0000000000284400ULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/N7/8/8/8");
	test_name = "knight at index 31 (a4), empty board";
	correct_board = 0x0000402000204000ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("3N4/8/8/8/8/8/8/8");
	test_name = "knight at index 60 (d8), empty board";
	correct_board = 0x0044280000000000ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7N/8/8/8");
	test_name = "knight at index 24 (h4), empty board";
	correct_board = 0x0000020400040200ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- bishop ---
	game.set_board("8/8/8/8/8/8/8/3B4");
	test_name = "bishop at index 4 (d1), empty board";
	correct_board = 0x0000000182442800ULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/B7/8/8/8");
	test_name = "bishop at index 31 (a4), empty board";
	correct_board = 0x0810204000402010ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("3B4/8/8/8/8/8/8/8");
	test_name = "bishop at index 60 (d8), empty board";
	correct_board = 0x0028448201000000ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7B/8/8/8");
	test_name = "bishop at index 24 (h4), empty board";
	correct_board = 0x1008040200020408ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- rook ---
	game.set_board("8/8/8/8/8/8/8/3R4");
	test_name = "rook at index 4 (d1), empty board";
	correct_board = 0x10101010101010EFULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/R7/8/8/8");
	test_name = "rook at index 31 (a4), empty board";
	correct_board = 0x808080807F808080ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("3R4/8/8/8/8/8/8/8");
	test_name = "rook at index 60 (d8), empty board";
	correct_board = 0xEF10101010101010ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7R/8/8/8");
	test_name = "rook at index 24 (h4), empty board";
	correct_board = 0x01010101FE010101ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- queen ---
	game.set_board("8/8/8/8/8/8/8/3Q4");
	test_name = "queen at index 4 (d1), empty board";
	correct_board = 0x10101011925438EFULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/Q7/8/8/8");
	test_name = "queen at index 31 (a4), empty board";
	correct_board = 0x8890A0C07FC0A090ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("3Q4/8/8/8/8/8/8/8");
	test_name = "queen at index 60 (d8), empty board";
	correct_board = 0xEF38549211101010ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7Q/8/8/8");
	test_name = "queen at index 24 (h4), empty board";
	correct_board = 0x11090503FE030509ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- king ---
	game.set_board("8/8/8/8/8/8/8/3K4");
	test_name = "king at index 4 (d1), empty board";
	correct_board = 0x0000000000003828ULL;
	if (test_valid_moves(game.get_valid_moves(4), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/K7/8/8/8");
	test_name = "king at index 31 (a4), empty board";
	correct_board = 0x000000C040C00000ULL;
	if (test_valid_moves(game.get_valid_moves(31), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("3K4/8/8/8/8/8/8/8");
	test_name = "king at index 60 (d8), empty board";
	correct_board = 0x2838000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(60), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/7K/8/8/8");
	test_name = "king at index 24 (h4), empty board";
	correct_board = 0x0000000302030000ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// =====================
	// ONE SPACE FROM WALL
	// =====================

	// --- white pawn ---
	game.set_board("8/8/8/8/8/8/3P4/8");
	test_name = "white pawn at index 12 (d2), empty board";
	correct_board = 0x0000000010100000ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1P6/8/8/8");
	test_name = "white pawn at index 30 (b4), empty board";
	correct_board = 0x0000004000000000ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3P4/8/8/8/8/8/8");
	test_name = "white pawn at index 52 (d7), empty board";
	correct_board = 0x1000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6P1/8/8/8");
	test_name = "white pawn at index 25 (g4), empty board";
	correct_board = 0x0000000200000000ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- black pawn ---
	game.set_board("8/8/8/8/8/8/3p4/8");
	test_name = "black pawn at index 12 (d2), empty board";
	correct_board = 0x0000000000000010ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1p6/8/8/8");
	test_name = "black pawn at index 30 (b4), empty board";
	correct_board = 0x0000000000400000ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3p4/8/8/8/8/8/8");
	test_name = "black pawn at index 52 (d7), empty board";
	correct_board = 0x0000101000000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6p1/8/8/8");
	test_name = "black pawn at index 25 (g4), empty board";
	correct_board = 0x0000000000020000ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- knight ---
	game.set_board("8/8/8/8/8/8/3N4/8");
	test_name = "knight at index 12 (d2), empty board";
	correct_board = 0x0000000028440044ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1N6/8/8/8");
	test_name = "knight at index 30 (b4), empty board";
	correct_board = 0x0000A0100010A000ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3N4/8/8/8/8/8/8");
	test_name = "knight at index 52 (d7), empty board";
	correct_board = 0x4400442800000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6N1/8/8/8");
	test_name = "knight at index 25 (g4), empty board";
	correct_board = 0x0000050800080500ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- bishop ---
	game.set_board("8/8/8/8/8/8/3B4/8");
	test_name = "bishop at index 12 (d2), empty board";
	correct_board = 0x0000018244280028ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1B6/8/8/8");
	test_name = "bishop at index 30 (b4), empty board";
	correct_board = 0x040810A000A01008ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3B4/8/8/8/8/8/8");
	test_name = "bishop at index 52 (d7), empty board";
	correct_board = 0x2800284482010000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6B1/8/8/8");
	test_name = "bishop at index 25 (g4), empty board";
	correct_board = 0x2010080500050810ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- rook ---
	game.set_board("8/8/8/8/8/8/3R4/8");
	test_name = "rook at index 12 (d2), empty board";
	correct_board = 0x101010101010EF10ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1R6/8/8/8");
	test_name = "rook at index 30 (b4), empty board";
	correct_board = 0x40404040BF404040ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3R4/8/8/8/8/8/8");
	test_name = "rook at index 52 (d7), empty board";
	correct_board = 0x10EF101010101010ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6R1/8/8/8");
	test_name = "rook at index 25 (g4), empty board";
	correct_board = 0x02020202FD020202ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- queen ---
	game.set_board("8/8/8/8/8/8/3Q4/8");
	test_name = "queen at index 12 (d2), empty board";
	correct_board = 0x101011925438EF38ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1Q6/8/8/8");
	test_name = "queen at index 30 (b4), empty board";
	correct_board = 0x444850E0BFE05048ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3Q4/8/8/8/8/8/8");
	test_name = "queen at index 52 (d7), empty board";
	correct_board = 0x38EF385492111010ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6Q1/8/8/8");
	test_name = "queen at index 25 (g4), empty board";
	correct_board = 0x22120A07FD070A12ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// --- king ---
	game.set_board("8/8/8/8/8/8/3K4/8");
	test_name = "king at index 12 (d2), empty board";
	correct_board = 0x0000000000382838ULL;
	if (test_valid_moves(game.get_valid_moves(12), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1K6/8/8/8");
	test_name = "king at index 30 (b4), empty board";
	correct_board = 0x000000E0A0E00000ULL;
	if (test_valid_moves(game.get_valid_moves(30), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3K4/8/8/8/8/8/8");
	test_name = "king at index 52 (d7), empty board";
	correct_board = 0x3828380000000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/6K1/8/8/8");
	test_name = "king at index 25 (g4), empty board";
	correct_board = 0x0000000705070000ULL;
	if (test_valid_moves(game.get_valid_moves(25), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	// =====================
	// BLOCKER TESTS
	// =====================

	game.set_board("8/8/8/4P3/4P3/8/8/8");
	test_name = "white pawn e4, friendly pawn blocks on e5";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(27), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/3p4/3P4/8/8/8");
	test_name = "white pawn d4, enemy pawn blocks on d5";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(28), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/4p3/8/4P3/8");
	test_name = "white pawn e2, enemy on e4 blocks double push";
	correct_board = 0x0000000000080000ULL;
	if (test_valid_moves(game.get_valid_moves(11), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/8/4p3/4P3/8");
	test_name = "white pawn e2, enemy on e3 blocks all";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(11), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/4p3/4p3/8/8/8");
	test_name = "black pawn e5, friendly pawn blocks on e4";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(35), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3p4/8/3P4/8/8/8/8");
	test_name = "black pawn d7, enemy on d5 blocks double push";
	correct_board = 0x0000100000000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/3p4/3P4/8/8/8/8/8");
	test_name = "black pawn d7, enemy on d6 blocks all";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(52), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/3P1N2/1p3n2/4N3/8/8/8");
	test_name = "white knight e4, mixed blockers on landing squares";
	correct_board = 0x0000002200221400ULL;
	if (test_valid_moves(game.get_valid_moves(27), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/2N3P1/4n3/8/4pn2/8/8");
	test_name = "black knight d5, mixed blockers on landing squares";
	correct_board = 0x0014220022100000ULL;
	if (test_valid_moves(game.get_valid_moves(35), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/5P1P/3p4/6N1/3P4/R1B5");
	test_name = "white knight b3, mostly blocked by friendly except d4 enemy";
	correct_board = 0x0000000008000805ULL;
	if (test_valid_moves(game.get_valid_moves(17), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/1Pn5/8/4B3/8/5p2/8");
	test_name = "white bishop e4, friendly on g6, enemies on c6 and c2";
	correct_board = 0x0001221400142241ULL;
	if (test_valid_moves(game.get_valid_moves(27), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/2R3p1/8/4b3/8/2b3N1/8/8");
	test_name = "black bishop d5, enemies on f7 and b3, friendly on f3 and b7";
	correct_board = 0x0020140014020000ULL;
	if (test_valid_moves(game.get_valid_moves(35), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/P3P3/8/2B5/8/3q3r");
	test_name = "white bishop f3, friendly on d5 and h5, enemies on d1 and h1";
	correct_board = 0x0000000050005088ULL;
	if (test_valid_moves(game.get_valid_moves(21), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/1p1p4/2b5/1p1p4/8/8/8");
	test_name = "black bishop c5, all diagonals blocked one step by friendly";
	correct_board = 0x0000000000000000ULL;
	if (test_valid_moves(game.get_valid_moves(37), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/4P3/8/8/n3R2b/8/4q3/8");
	test_name = "white rook e4, friendly on e7, enemies on e2/a4/h4";
	correct_board = 0x00000808F7080800ULL;
	if (test_valid_moves(game.get_valid_moves(27), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/3R4/8/r2r3p/8/3N4/8");
	test_name = "black rook d4, friendly on a4/h4, enemies on d6/d2";
	correct_board = 0x000010106E101000ULL;
	if (test_valid_moves(game.get_valid_moves(28), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("1P6/8/8/pR2n3/8/8/1P6/8");
	test_name = "white rook b5, friendly on b8/b2, enemies on e5/a5";
	correct_board = 0x004040B840400000ULL;
	if (test_valid_moves(game.get_valid_moves(38), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/5R2/8/2r2r1B/8/8/5p2/8");
	test_name = "black rook f5, friendly on f2/c5, enemies on f7/h5";
	correct_board = 0x0004041B04040000ULL;
	if (test_valid_moves(game.get_valid_moves(34), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/1Pb1P3/8/2n1Q1r1/8/4q3/8");
	test_name = "white queen e4, mixed blockers on all sides";
	correct_board = 0x0001221C361C2A41ULL;
	if (test_valid_moves(game.get_valid_moves(27), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/4pp2/8/1r2q2R/8/2Q1N1B1/8/8");
	test_name = "black queen d5, mixed blockers on all diagonals and ranks";
	correct_board = 0x41221C371C2A0000ULL;
	if (test_valid_moves(game.get_valid_moves(35), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/pbP5/4n3/8/P1Q5/8/2r5");
	test_name = "white queen c3, friendly on c6/a3, enemies on c1/f6/e5/a6";
	correct_board = 0x000000A8705F70A8ULL;
	if (test_valid_moves(game.get_valid_moves(21), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/3R1p1p/8/3n1q1r/8/3B1Q1N/8");
	test_name = "black queen f4, friendly on f6/h4/h6/d4, enemies on f2/d6/d2/h2";
	correct_board = 0x0000100E0A0E1500ULL;
	if (test_valid_moves(game.get_valid_moves(26), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/3PPn2/3PKb2/3qpr2/8/8");
	test_name = "white king e4, friendly on d4/d5/e5, enemies on f5/f4/f3/e3/d3";
	correct_board = 0x00000004041C0000ULL;
	if (test_valid_moves(game.get_valid_moves(27), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/2p1pp2/2p1kR2/2B1NQ2/8/8/8");
	test_name = "black king d5, friendly on c5/d6/e6/c6, enemies on e5/e4/d4/c4";
	correct_board = 0x000010141C000000ULL;
	if (test_valid_moves(game.get_valid_moves(35), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/6Pq/6PK/6nr/8/8");
	test_name = "white king h4, friendly on g4/g5, enemies on g3/h3/h5";
	correct_board = 0x0000000100030000ULL;
	if (test_valid_moves(game.get_valid_moves(24), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/BN6/kp6/pR6/8/8/8");
	test_name = "black king a5, friendly on a4/b5, enemies on b4/b6/a6";
	correct_board = 0x0000C00040000000ULL;
	if (test_valid_moves(game.get_valid_moves(39), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/1p3p2/8/3B4/8/1n3q2/8");
	test_name = "white bishop d4, enemies two steps away on all diagonals";
	correct_board = 0x0000442800284400ULL;
	if (test_valid_moves(game.get_valid_moves(28), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("4K3/8/8/B3r2R/8/8/8/4Q3");
	test_name = "black rook e5, enemies on all four edges of rank/file";
	correct_board = 0x080808F708080808ULL;
	if (test_valid_moves(game.get_valid_moves(35), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/8/8/8/1P1P4/b7/nQ1P4/qr6");
	test_name = "white queen b2, friendly on b4/d4/d2, enemies on b1/a2/a3/a1";
	correct_board = 0x0000000000E0A0E0ULL;
	if (test_valid_moves(game.get_valid_moves(14), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	game.set_board("8/4R3/7p/6bp/8/4Q3/8/8");
	test_name = "black bishop g5, friendly on h6/h4, enemies on e7/e3";
	correct_board = 0x0008040005080000ULL;
	if (test_valid_moves(game.get_valid_moves(33), correct_board, test_name)) { passed++; } else {
		failed_tests += test_name + "\n";
	}
	total++;

	std::cout << "Passed: " << passed << "/" << total << std::endl;
	std::cout << std::endl;
	std::cout << "Failed:\n" << failed_tests << std::endl;

	return 0;
}
