#include <iostream>
#include "bitboard.h"
#include "position_constants.h"

//Creates empty board
BitBoard::BitBoard(){
	white_pawns = 0LL;
	white_knights = 0LL;
	white_bishops = 0LL;
	white_rooks = 0LL;
	white_queen = 0LL;
	white_king = 0LL;

	black_pawns = 0LL;
	black_knights = 0LL;
	black_bishops = 0LL;
	black_rooks = 0LL;
	black_queen = 0LL;
	black_king = 0LL;

	white_pieces = 0LL;
	black_pieces = 0LL;
	all_pieces = 0LL;
}

//Creates a board with all pieces in their starting positions
void BitBoard::NewBoard() {
	//Place the white pieces.
	white_pawns = ROW_B;
	white_knights = POS_A2 | POS_A7;
	white_bishops = POS_A3 | POS_A6;
	white_rooks = POS_A1 | POS_A8;
	white_queen = POS_A4;
	white_king = POS_A5;

	//Place the black pieces.
	black_pawns = ROW_G;
	black_knights = POS_H2 | POS_H7;
	black_bishops = POS_H3 | POS_H6;
	black_rooks = POS_H1 | POS_H8;
	black_queen = POS_H4;
	black_king = POS_H5;

	UpdateBoardSets();
}

void BitBoard::PrintBoard() {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (white_pawns & 1LL << count)
				std::cout << "P    ";
			else if (white_knights & 1LL << count)
				std::cout << "N    ";
			else if (white_bishops & 1LL << count)
				std::cout << "B    ";
			else if (white_rooks & 1LL << count)
				std::cout << "R    ";
			else if (white_queen & 1LL << count)
				std::cout << "Q    ";
			else if (white_king & 1LL << count)
				std::cout << "K    ";

			else if (black_pawns & 1LL << count)
				std::cout << "p    ";
			else if (black_knights & 1LL << count)
				std::cout << "n    ";
			else if (black_bishops & 1LL << count)
				std::cout << "b    ";
			else if (black_rooks & 1LL << count)
				std::cout << "r    ";
			else if (black_queen & 1LL << count)
				std::cout << "q    ";
			else if (black_king & 1LL << count)
				std::cout << "k    ";
			
			else
				std::cout << "-    ";

			++count;
		}
		std::cout << std::endl << std::endl;
	}
}

//Updates the the bitboards containing multiple pieces
void BitBoard::UpdateBoardSets() {
	white_pieces = white_pawns | white_knights | white_bishops | white_rooks | white_queen | white_king;
	
	black_pieces = black_pawns | black_knights | black_bishops | black_rooks | black_queen | black_king;

	all_pieces = white_pieces | black_pieces;
}