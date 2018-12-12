#include <iostream>
#include <vector>
#include <fstream>
#include "bitboard.h"
#include <bitset>
#include "position_constants.h"

//Bitboard Controller Helper Functions
BitboardController minBoardValue(BitboardController b1, BitboardController b2){
	BitboardController minBoard;
	b1.boardSum() < b2.boardSum() ? minBoard = b1 : minBoard = b2;
	return minBoard;
}
BitboardController maxBoardValue(BitboardController b1, BitboardController b2){
	BitboardController maxBoard;
	b1.boardSum() > b2.boardSum() ? maxBoard = b1 : maxBoard = b2;
	return maxBoard;
}

//Creates empty board
BitboardController::BitboardController(){
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

//Allows manipulation of board value
BitboardController::BitboardController(int value){boardValue[0] = value;}


//Creates a board with all pieces in their starting positions
void BitboardController::newBoard() {
	//Place the white pieces.
	white_pawns = ROW_2;
	white_knights = POS_B1 | POS_G1;
	white_bishops = POS_C1 | POS_F1;
	white_rooks = POS_A1 | POS_H1;
	white_queen = POS_D1;
	white_king = POS_E1;

	//Place the black pieces.
	black_pawns = ROW_7;
	black_knights = POS_B8 | POS_G8;
	black_bishops =  POS_C8 | POS_F8;
	black_rooks = POS_A8 | POS_H8;
	black_queen = POS_D8;
	black_king = POS_E8;

	updateBoardSets();

	int defaultValue[64]{ 5,  3,  3,  9, 100, 3,  3,  5,
						1,  1,  1,  1,  1,  1,  1,  1,
						0,  0,  0,  0,  0,  0,  0,  0,
						0,  0,  0,  0,  0,  0,  0,  0,
						0,  0,  0,  0,  0,  0,  0,  0,
						0,  0,  0,  0,  0,  0,  0,  0,
					   -1, -1, -1, -1, -1, -1, -1, -1,
					   -5, -3, -3, -9,-100,-3, -3, -5 };
	for(int i = 0; i < 64; i++){boardValue[i] = defaultValue[i];}

	isWhite = false;
}

void BitboardController::printBoard(std::ofstream& file) {
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
void BitboardController::executeMove(std::string move, int col1, int row1, int col2, int row2){

	//parse string unless int values provided
	if(col1 == 0 && col2 == 0 && row1 == 0 && row2 == 0){
		//If there is only one move to process, return and continue (First turn as black)
		if (move.find("oves") != std::string::npos)
			return;

		//splits string move into single location parts
		std::string pos = move.substr(0, 2);
		std::string newpos = move.substr(2, 2);

		//Converts string move to integer values
		col1 = (pos[0] - 96);
		col2 = (newpos[0] - 96);
		row1 = pos[1] - 48;
		row2 = newpos[1] - 48;
	}
	
	//starting location on bitboard and ending location
	long long start = (((row1 - 1) * 8) + col1) - 1;
	long long end = (((row2 - 1) * 8) + col2) - 1;

	//updates board value array
	boardValue[end] = boardValue[start];
	boardValue[start] = 0;
	std::cout << boardSum() << std::endl;

	//Destroys piece at current end location if any
	if (white_pieces & 1LL << end) {
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
	}
	else if (black_pieces & 1LL << end) {
		if (black_pawns & 1LL << end) {
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
	if (white_pieces & 1LL << start) {
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
	}
	else if (black_pieces & 1LL << start) {
		if (black_pawns & 1LL << start) {
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
	}
	updateBoardSets();
}


//Updates the the bitboards containing multiple pieces
void BitboardController::updateBoardSets() {
	white_pieces = white_pawns | white_knights | white_bishops | white_rooks | white_queen | white_king;
	
	black_pieces = black_pawns | black_knights | black_bishops | black_rooks | black_queen | black_king;

	all_pawns = white_pawns | black_pawns;
	all_knights = white_knights | black_knights;
	all_rooks = white_rooks | black_rooks;
	all_bishops = white_bishops | black_bishops;
	all_queens = white_queen | black_queen;
	all_kings = white_king | black_king;

	all_pieces = white_pieces | black_pieces;

	empty_board = ~all_pieces & all_pieces;
}

//Finds available moves for a given piece
long long BitboardController::findMoves(short piece, bool white) {
	board movable_squares = empty_board;
	board opposite_color;
	board active_color;
	int colMod;

	//Find column and row
	int column = ((piece + 8) % 8);
	int row = (piece / 8);

	//check engine color
	white ? colMod = 1 : colMod = -1;

	//Check which color piece is being searched
	if (white_pieces & 1LL << piece) {
		active_color = white_pieces;
		opposite_color = black_pieces;
	}
	else {
		active_color = black_pieces;
		opposite_color = white_pieces; 
	}
	//pawns
	if (all_pawns & 1LL << piece) {
		movable_squares |= (1LL << (piece + (8 * colMod)) & ~(all_pieces));
		if ((1LL << (piece + 7 * colMod) & opposite_color) && !(white && (1LL << piece & COL_A)) && !(!white && (1LL << piece & COL_H))) {movable_squares |= 1LL << (piece + (7 * colMod));}
		if ((1LL << (piece + 9 * colMod) & opposite_color) && !(white && (1LL << piece & COL_H)) && !(!white && (1LL << piece & COL_A))) {movable_squares |= 1LL << (piece + (9 * colMod));}
	}

	//knights
	else if (all_knights & 1LL << piece) {
		if ((1LL << piece & ~COL_G) & (1LL << piece & ~COL_H) & (1LL << piece & ~ROW_1)) { movable_squares |= 1LL << (piece - 6);}
		if ((1LL << piece & ~COL_A) & (1LL << piece & ~COL_B) & (1LL << piece & ~ROW_8)) { movable_squares |= 1LL << (piece + 6); }
		if ((1LL << piece & ~COL_A) & (1LL << piece & ~COL_B) & (1LL << piece & ~ROW_1)) { movable_squares |= 1LL << (piece - 10); }
		if ((1LL << piece & ~COL_G) & (1LL << piece & ~COL_H) & (1LL << piece & ~ROW_8)) { movable_squares |= 1LL << (piece + 10); }
		if ((1LL << piece & ~COL_H) & (1LL << piece & ~ROW_1) & (1LL << piece & ~ROW_2)) { movable_squares |= 1LL << (piece - 15); }
		if ((1LL << piece & ~COL_A) & (1LL << piece & ~ROW_7) & (1LL << piece & ~ROW_8)) { movable_squares |= 1LL << (piece + 15); }
		if ((1LL << piece & ~COL_A) & (1LL << piece & ~ROW_1) & (1LL << piece & ~ROW_2)) { movable_squares |= 1LL << (piece - 17); }
		if ((1LL << piece & ~COL_H) & (1LL << piece & ~ROW_7) & (1LL << piece & ~ROW_8)) { movable_squares |= 1LL << (piece + 17); }
		movable_squares &= ~active_color;
	}

	//rooks
	if ((all_rooks & 1LL << piece) || (all_queens & 1LL << piece)) {
		int Rcollision = 0, Lcollision = 0, Acollision = 0, Bcollision = 0;
		//pieces to the right
		for (int i = 1; (Rcollision == 0 && (i + column) < 8); i++) {(1LL << (piece + i) & ~all_pieces) ? movable_squares |= (1LL << (piece + i)) : (Rcollision = 1) && (movable_squares |= (1LL << (piece + i))); }
		//pieces to the left
		for (int i = -1; Lcollision == 0 && ((i + column) > -1); i--) { (1LL << (piece + i) & ~all_pieces) ? movable_squares |= 1LL << (piece + i) : (Lcollision = 1) && (movable_squares |= 1LL << (piece + i)); }
		//pieces above
		for (int i = 1; Acollision == 0 && ((i + row) < 8); i++) { (1LL << (piece + (8 * i)) & ~all_pieces) ? movable_squares |= 1LL << (piece + (8 * i)) : (Acollision = 1) && (movable_squares |= 1LL << (piece + (8 * i))); }
		//pieces below
		for (int i = -1; Bcollision == 0 && ((i + row) > -1); i--) { (1LL << (piece + (8 * i)) & ~all_pieces) ? movable_squares |= 1LL << (piece + (8 * i)) : (Bcollision = 1) && (movable_squares |= 1LL << (piece + (8 * i))); }
	
		movable_squares &= ~active_color;
	}

	//bishops
	if ((all_bishops & 1LL << piece) || (all_queens & 1LL << piece)) {
		int NEcollision = 0, NWcollision = 0, SEcollision = 0, SWcollision = 0;
		//pieces NE
		for (int i=1; NEcollision == 0 && ((i+row) < 8) && ((i+column) < 8) ; i++) { (1LL << (piece + (9*i)) & ~all_pieces) ? movable_squares |= 1LL << (piece + (9*i)) : (NEcollision = 1) && (movable_squares |= 1LL << (piece+(9 * i))); }
		//pieces NW
		for (int i=1; NWcollision == 0 && ((i+row) < 8) && (((-1*i)+column) > -1); i++) { (1LL << (piece + (7*i)) & ~all_pieces) ? movable_squares |= 1LL << (piece + (7*i)) : (NWcollision = 1) && (movable_squares |= 1LL << (piece+(7 * i))); }
		//pieces SE
		for (int i=-1; SEcollision == 0 && ((i+row) > -1) && ((i+column) < 8); i--) { (1LL << (piece + (7*i)) & ~all_pieces) ? movable_squares |= 1LL << (piece + (7*i)) : (SEcollision = 1) && (movable_squares |= 1LL << (piece+(7 * i))); }
		//pieces SW
		for (int i=-1; SWcollision == 0 && ((i+row) > -1) && ((i+column) > -1); i--) { (1LL << (piece + (9*i)) & ~all_pieces) ? movable_squares |= 1LL << (piece + (9*i)) : (SWcollision = 1) && (movable_squares |= 1LL << (piece+(9 * i))); }
		movable_squares &= ~active_color;
	}

	//King
	if (all_kings & 1LL << piece) {
		if (row != 7) { movable_squares |= ((1LL << (piece + 8)) & ~(active_color));}
		if (row != 7 && column != 0) { movable_squares |= ((1LL << (piece + 7)) & ~(active_color)); }
		if (row != 7 && column != 7) { movable_squares |= ((1LL << (piece + 9)) & ~(active_color)); }
		if (row != 0) { movable_squares |= ((1LL << (piece - 8)) & ~(active_color)); }
		if (row != 0 && column != 0) { movable_squares |= ((1LL << (piece - 7)) & ~(active_color)); }
		if (row != 0 && column != 7) { movable_squares |= ((1LL << (piece - 9)) & ~(active_color)); }
		if (column != 7) { movable_squares |= ((1LL << (piece + 1)) & ~(active_color)); }
		if (column != 0) { movable_squares |= ((1LL << (piece - 1)) & ~(active_color)); }
	}

	return movable_squares;
}

//Searches for the highest value possible move

BitboardController BitboardController::selectMove(bool white, int depth, BitboardController bitboard){
	board activeColor;
	board movePool;
	white ? activeColor = white_pieces : activeColor = black_pieces;
	BitboardController bestBoard;

	//base case
	if(depth == 0){
		return bitboard;
	}

	//Generate a list of moves
	std::vector<BitboardController> moveList;
	for(int piece = 0; piece < 64; piece++){
		if(activeColor & (1LL << piece)){
			movePool = bitboard.findMoves(piece, white);
			for(int move = 0; move < 64; move++){
				if (movePool & (1LL << move)){
					BitboardController newBoard = bitboard;
					//calculate column and row
					int col1 = ((piece + 8) % 8);
					int row1 = (piece / 8);
					int col2 = ((move + 8) % 8);
					int row2 = (move / 8);
					newBoard.executeMove("", col1, row1, col2, row2);
					moveList.push_back(newBoard);
				}
			}
		}
	}
	if(white){
		bestBoard = BitboardController(-9999); //sets low boardValue
		for(int i = 0; i < moveList.size(); i++){
			bestBoard = maxBoardValue(bestBoard, bitboard.selectMove(false, depth - 1, moveList[i]));
		}
		return bestBoard;
	}
	else{
		bestBoard = BitboardController(9999); //sets low boardValue
		for(int i = 0; i < moveList.size(); i++){
			bestBoard = minBoardValue(bestBoard, bitboard.selectMove(true, depth - 1, moveList[i]));
		}
		return bestBoard;
	}

}

std::string BitboardController::selectMove2() {
	int piece = -1, startPos, best_move, advantage, new_advantage;
	board movePool;
	board activeColor;

	//check engine color
	isWhite ? activeColor = white_pieces : activeColor = black_pieces;

	//handles current board advantage
	advantage = boardSum();

	while(piece < 63){
		++piece;
		if(activeColor & (1LL << piece)){
			movePool = findMoves(piece, isWhite);
			for (int i = 0; i < 64; i++) {
				if (movePool & (1LL << i)) {
					//Update Board Values
					int temp = boardValue[piece];
					int temp2 = boardValue[i];
					boardValue[piece] = 0;
					boardValue[i] = temp;
					new_advantage = boardSum();
					//Selects a new best move if it improves the engine's board position
					if (((new_advantage >= advantage) && isWhite) || ((new_advantage <= advantage) && !isWhite)){
						best_move = i;
						startPos = piece;
						advantage = new_advantage;
					}
				//Reset board values
				boardValue[piece] = temp;
				boardValue[i] = temp2;
				}
			}
		}
	}
	//Converts integer values to ascii values
	int col1 = ((startPos + 8) % 8) + 1;
	int row1 = (startPos / 8) + 1;
	int col2 = ((best_move + 8) % 8) + 1;
	int row2 = (best_move / 8) + 1;

	char col = col1 + 96;
	char row = row1 + 48;
	char newcol = col2 + 96;
	char newrow = row2 + 48;

	//convert to string value for GUI
	std::string move;
	move += col;
	move += row;
	move += newcol;
	move += newrow;

	return move;
}

int BitboardController::boardSum(){
	int sum = 0;
	for (int i = 0; i < 64; i++)
	{
		sum += boardValue[i];
	}
	return sum;
}
