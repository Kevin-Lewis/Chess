#include <iostream>
#include <string>
#include <fstream>
#include "bitboard.h"

int main()
{
	BitBoard Board;
	Board.NewBoard();
	std::string Line;
	std::ofstream cmdLog;
	std::ofstream boardOutput;
	cmdLog.open("C:/Users/Kevin/Desktop/log.txt");
	boardOutput.open("C:/Users/Kevin/Desktop/output.txt");
	
	std::cout.setf(std::ios::unitbuf); //Makes sure that the outputs are sent immediately to the GUI
	
	while (std::getline(std::cin, Line)) {
		//Write to Files
		cmdLog << Line << std::endl;
		if (Line == "uci") {
			std::cout << "Zip Engine" << std::endl; //Engine Name
			std::cout << "Kevin Lewis" << std::endl; //Author Name
			std::cout << "uciok" << std::endl; //Enables UCI
		}
		else if (Line == "quit") {
			std::cout << "Game Over" << std::endl;
			break;
		}
		else if (Line == "isready") {
			std::cout << "readyok" << std::endl;
		}
		else if (Line == "ucinewgame") {
			Board.NewBoard();
		}

		if (Line.substr(0, 24) == "position startpos moves ") {
			std::string moveW = Line.substr(Line.size() - 4);
			std::string moveB = Line.substr(Line.size() - 9, 4);
			Board.ExecuteMove(moveB);
			Board.PrintBoard(boardOutput);
			Board.ExecuteMove(moveW);
			Board.PrintBoard(boardOutput);
		}
		else if (Line == "startpos" || Line == "position startpos") {
			Board.setColor(true);
		}
		else if (Line == "stop") {
			; // nothing
		}
		else if (Line.substr(0, 3) == "go ") {
			std::string move = Board.SelectMove();
			cmdLog << "best move: " << move << std::endl;
			std::cout << "bestmove " << move << std::endl;
		}
	}
	cmdLog.close();
	boardOutput.close();
	return 0;
}