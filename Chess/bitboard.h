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

	//BitBoard Getters
	long long GetAllPieces() const { return all_pieces; }
	long long GetWhitePieces() const { return white_pieces; }
	long long GetBlackPieces() const { return black_pieces; }

	long long GetWhitePawns() const { return white_pawns; }
	long long GetWhiteKnights() const { return white_knights; }
	long long GetWhiteBishops() const { return white_bishops; }
	long long GetWhiteRooks() const { return white_rooks; }
	long long GetWhiteQueen() const { return white_queen; }
	long long GetWhiteKing() const { return white_king; }

	long long GetBlackPawns() const { return black_pawns; }
	long long GetBlackKnights() const { return black_knights; }
	long long GetBlackBishops() const { return black_bishops; }
	long long GetBlackRooks() const { return black_rooks; }
	long long GetBlackQueen() const { return black_queen; }
	long long GetBlackKing() const { return black_king; }

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
	board empty_board;
	board white_pieces;
	board black_pieces;

	//engine color
	bool isWhite;
};


#endif