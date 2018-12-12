#include <iostream>
#include <string>

class BitboardController{
public:
	BitboardController();
	BitboardController(int value);

	void newBoard();

	void printBoard();

	long long findMoves(short piece, bool white);
	BitboardController selectMove(bool white, int depth, BitboardController board);

	void executeMove(std::string move, int col1 = 0, int row1 = 0, int col2 = 0, int row2 = 0);

	void setColor(bool White) { isWhite = White; }
	bool getColor(){return isWhite;}

	int boardSum();

	std::string getRecentMove();

	std::string getMove(int depth);

private:
	typedef long long board;

	void updateBoardSets();

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


	//engine color
	bool isWhite;

	//most recent move set (row col to row col)
	int recentMove[4]{0,0,0,0};

	std::string moveHistory = "";
};
