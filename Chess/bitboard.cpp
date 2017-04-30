#include "bitboard.h"
#include "position_constants.h"

//Creates empty board
BitBoard::BitBoard(){
	white_pawns = 0ULL;
	white_knights = 0ULL;
	white_bishops = 0ULL;
	white_rooks = 0ULL;
	white_queen = 0ULL;
	white_king = 0ULL;

	black_pawns = 0ULL;
	black_knights = 0ULL;
	black_bishops = 0ULL;
	black_rooks = 0ULL;
	black_queen = 0ULL;
	black_king = 0ULL;

	white_pieces = 0ULL;
	black_pieces = 0ULL;
	all_pieces = 0ULL;
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

//Updates the the bitboards containing multiple pieces
void BitBoard::UpdateBoardSets() {
	white_pieces = white_pawns | white_knights | white_bishops | white_rooks | white_queen | white_king;
	
	black_pieces = black_pawns | black_knights | black_bishops | black_rooks | black_queen | black_king;

	all_pieces = white_pieces | black_pieces;
}