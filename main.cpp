#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "bitboard.h"


int main(){

	BitboardController controller;
	controller.newBoard();
	std::string line;

	std::cout.setf(std::ios::unitbuf); //Makes sure that the outputs are sent immediately to the GUI
	
	while (std::getline(std::cin, line)) {
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
			controller.executeMove(moveW);
		}
		else if (line == "startpos" || line == "position startpos") {
			controller.setColor(true);
		}
		else if (line == "stop") {
			; // nothing
		}
		else if (line.substr(0, 3) == "go ") {
			BitboardController b = controller.selectMove(controller.getColor(), 3, controller);
			std::string move = b.getMove(3);
			std::cout << "bestmove " << move << std::endl;
		}
	}
	return 0;
}
