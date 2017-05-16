#ifndef BITBOARD_H
#define BITBOARD_H
#include <iostream>
class BitBoard{
public:
	BitBoard();

	void NewBoard();

	void PrintBoard(std::ofstream& file);

	std::string SelectMove();

	void ExecuteMove(std::string move);

	void setColor(bool White) { isWhite = White; }

private:
	typedef long long board;

	void UpdateBoardSets();

	long long FindMoves(short piece);

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

	//engine color
	bool isWhite;
};


#endif