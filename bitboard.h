#ifndef BITBOARD_H
#define BITBOARD_H
#include <iostream>
class BitboardController{
public:
	BitboardController();

	void newBoard();

	void printBoard(std::ofstream& file);

	std::string selectMove();

	void executeMove(std::string move);

	void setColor(bool White) { isWhite = White; }

private:
	typedef long long board;

	void updateBoardSets();

	long long findMoves(short piece);

	//White Pieces
	board white_pawns;
	board white_knights;
	board white_bishops;
	board white_rooks;
	board white_queen;
	board white_king;

	//Black Pieces
	board black_pawns;
	board black_knights;
	board black_bishops;
	board black_rooks;
	board black_queen;
	board black_king;

	//Other Boards
	board all_pieces;
	board all_pawns;
	board all_knights;
	board all_rooks;
	board all_bishops;
	board all_queens;
	board all_kings;
	board empty_board;
	board white_pieces;
	board black_pieces;

	//Board Value Array
	int boardValue[64]{ 5,  3,  3,  9, 100, 3,  3,  5,
						1,  1,  1,  1,  1,  1,  1,  1,
						0,  0,  0,  0,  0,  0,  0,  0,
						0,  0,  0,  0,  0,  0,  0,  0,
						0,  0,  0,  0,  0,  0,  0,  0,
						0,  0,  0,  0,  0,  0,  0,  0,
					   -1, -1, -1, -1, -1, -1, -1, -1,
					   -5, -3, -3, -9,-100,-3, -3, -5 };



	int boardSum();

	//engine color
	bool isWhite;
};


#endif
