#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "bitboard.h"


int main(){

	BitboardController controller;
	controller.newBoard();
	std::string line;
	int depth = 5;
	int turn = 0;

	std::cout.setf(std::ios::unitbuf); //Makes sure that the outputs are sent immediately to the GUI
	
	while (std::getline(std::cin, line)) {
		if (line == "uci") {
			std::cout << "UA Chess" << std::endl; //Engine Name
			std::cout << "Kevin Lewis and Mack Blaurock" << std::endl; //Author Name
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
			turn = 0;
			controller.newBoard();
		}

		if (line.substr(0, 24) == "position startpos moves ") {
			std::string moveW = line.substr(line.size() - 4);
			std::string moveB = line.substr(line.size() - 9, 4);
			controller.executeMove(moveB);
			controller.executeMove(moveW);
			turn++;
		}
		else if (line == "startpos" || line == "position startpos") {
			controller.setColor(true);
		}
		else if (line == "stop") {
			; // nothing
		}
		else if (line.substr(0, 3) == "go ") {
			if(turn == 0){std::cout << "bestmove " << "d2d4" << std::endl; turn = 2;}
			else if(turn == 1){std::cout << "bestmove " << "e7e5" << std::endl;}
			else{
				BitboardController alpha = BitboardController(-999);
				BitboardController beta = BitboardController(999);
				BitboardController b = controller.selectMove(controller.getColor(), depth, controller, alpha, beta);
				std::string move = b.getMove(depth);
				std::cout << "bestmove " << move << std::endl;
			}
		}
	}
	return 0;
}
