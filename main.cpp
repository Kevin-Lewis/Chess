#include <iostream>
#include <string>
#include <fstream>
#include "bitboard.h"

int main(){

	BitboardController controller;
	controller.newBoard();
	std::string line;
	std::string path(getenv("HOME"));
	std::string path2 = path;
	path += "/Desktop/log.txt";
	path2 += "/Desktop/output.txt";
	std::ofstream cmdLog;
	std::ofstream boardOutput;
	cmdLog.open(path);
	boardOutput.open(path2);
	
	std::cout.setf(std::ios::unitbuf); //Makes sure that the outputs are sent immediately to the GUI
	
	while (std::getline(std::cin, line)) {
		//Write to Files
		cmdLog << line << std::endl;
		if (line == "uci") {
			std::cout << "Zip Engine" << std::endl; //Engine Name
			std::cout << "Kevin Lewis" << std::endl; //Author Name
			std::cout << "uciok" << std::endl; //Enables UCI
		}
		else if (line == "quit") {
			std::cout << "Game Over" << std::endl;
			break;
		}
		else if (line == "isready") {
			std::cout << "readyok" << std::endl;
		}
		else if (line == "ucinewgame") {
			controller.newBoard();
		}

		if (line.substr(0, 24) == "position startpos moves ") {
			std::string moveW = line.substr(line.size() - 4);
			std::string moveB = line.substr(line.size() - 9, 4);
			controller.executeMove(moveB);
			controller.printBoard(boardOutput);
			controller.executeMove(moveW);
			controller.printBoard(boardOutput);
		}
		else if (line == "startpos" || line == "position startpos") {
			controller.setColor(true);
			std::string move = controller.selectMove();
			cmdLog << "best move: " << move << std::endl;
			std::cout << "bestmove " << move << std::endl;
			cmdLog.close();
			boardOutput.close();
		}
		else if (line == "stop") {
			; // nothing
		}
		else if (line.substr(0, 3) == "go ") {
			std::string move = controller.selectMove();
			cmdLog << "best move: " << move << std::endl;
			std::cout << "bestmove " << move << std::endl;
		}
	}
	cmdLog.close();
	boardOutput.close();
	return 0;
}
