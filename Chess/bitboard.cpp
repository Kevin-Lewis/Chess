#include <iostream>
#include <fstream>
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

void BitBoard::PrintBoard(std::ofstream& file) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (white_pawns & 1LL << count)
				file << "P    ";
			else if (white_knights & 1LL << count)
				file << "N    ";
			else if (white_bishops & 1LL << count)
				file << "B    ";
			else if (white_rooks & 1LL << count)
				file << "R    ";
			else if (white_queen & 1LL << count)
				file << "Q    ";
			else if (white_king & 1LL << count)
				file << "K    ";

			else if (black_pawns & 1LL << count)
				file << "p    ";
			else if (black_knights & 1LL << count)
				file << "n    ";
			else if (black_bishops & 1LL << count)
				file << "b    ";
			else if (black_rooks & 1LL << count)
				file << "r    ";
			else if (black_queen & 1LL << count)
				file << "q    ";
			else if (black_king & 1LL << count)
				file << "k    ";
			
			else
				file << "-    ";
			++count;
		}
		file << std::endl << std::endl;
	}
	file << "_____________________________________" << std::endl;
}

//Executes move from 4 char string
void BitBoard::ExecuteMove(std::string move) {

	//If there is only one move to process
	if (move.find("oves") != std::string::npos)
		return;

	std::string pos = move.substr(0, 2);
	std::string newpos = move.substr(2, 2);

	//Converts string move to integer values
	int col1 = (pos[0] - 96);
	int col2 = (newpos[0] - 96);
	int row1 = pos[1] - 48;
	int row2 = newpos[1] - 48;

	//starting location on bitboard and ending location
	long long start = (((row1 - 1) * 8) + col1) - 1;
	long long end = (((row2 - 1) * 8) + col2) - 1;

	//Destroys piece at current end location if any
	if (all_pieces & 1LL << end) {
		if (white_pawns & 1LL << end) {
			white_pawns ^= 1LL << end;
		}
		else if (white_knights & 1LL << end) {
			white_knights ^= 1LL << end;
		}
		else if (white_bishops & 1LL << end) {
			white_bishops ^= 1LL << end;
		}
		else if (white_rooks & 1LL << end) {
			white_rooks ^= 1LL << end;
		}
		else if (white_queen & 1LL << end) {
			white_queen ^= 1LL << end;
		}
		else if (white_king & 1LL << end) {
			white_king ^= 1LL << end;
		}
		else if (black_pawns & 1LL << end) {
			black_pawns ^= 1LL << end;
		}
		else if (black_knights & 1LL << end) {
			black_knights ^= 1LL << end;
		}
		else if (black_bishops & 1LL << end) {
			black_bishops ^= 1LL << end;
		}
		else if (black_rooks & 1LL << end) {
			black_rooks ^= 1LL << end;
		}
		else if (black_queen & 1LL << end) {
			black_queen ^= 1LL << end;
		}
		else if (black_king & 1LL << end) {
			black_king ^= 1LL << end;
		}
	}

	//Checks which piece is moving and executes the move
	if (white_pawns & 1LL << start) {
		white_pawns ^= 1LL << start;
		white_pawns |= 1LL << end;
	}	
	else if (white_knights & 1LL << start) {
		white_knights ^= 1LL << start;
		white_knights |= 1LL << end;
	}	
	else if (white_bishops & 1LL << start) {
		white_bishops ^= 1LL << start;
		white_bishops |= 1LL << end;
	}	
	else if (white_rooks & 1LL << start) {
		white_rooks ^= 1LL << start;
		white_rooks |= 1LL << end;
	}	
	else if (white_queen & 1LL << start) {
		white_queen ^= 1LL << start;
		white_queen |= 1LL << end;
	}	
	else if (white_king & 1LL << start) {
		white_king ^= 1LL << start;
		white_king |= 1LL << end;
	}		
	else if (black_pawns & 1LL << start) {
		black_pawns ^= 1LL << start;
		black_pawns |= 1LL << end;
	}		
	else if (black_knights & 1LL << start) {
		black_knights ^= 1LL << start;
		black_knights |= 1LL << end;
	}		
	else if (black_bishops & 1LL << start) {
		black_bishops ^= 1LL << start;
		black_bishops |= 1LL << end;
	}		
	else if (black_rooks & 1LL << start) {
		black_rooks ^= 1LL << start;
		black_rooks |= 1LL << end;
	}		
	else if (black_queen & 1LL << start) {
		black_queen ^= 1LL << start;
		black_queen |= 1LL << end;
	}		
	else if (black_king & 1LL << start) {
		black_king ^= 1LL << start;
		black_king |= 1LL << end;
	}

	UpdateBoardSets();
}


//Updates the the bitboards containing multiple pieces
void BitBoard::UpdateBoardSets() {
	white_pieces = white_pawns | white_knights | white_bishops | white_rooks | white_queen | white_king;
	
	black_pieces = black_pawns | black_knights | black_bishops | black_rooks | black_queen | black_king;

	all_pieces = white_pieces | black_pieces;
}
