#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string Line;
	int flag = 0;
	std::ofstream cmdLog;
	cmdLog.open("log.txt");

	std::cout.setf(std::ios::unitbuf); //Makes sure that the outputs are sent immediately to the GUI

	while (std::getline(std::cin, Line)) {
		//Write to File
		cmdLog << Line << std::endl;

		if (Line == "uci") {
			std::cout << "Kevin-Engine" << std::endl; //Engine Name
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
			; // nothing
		}

		if (Line.substr(0, 23) == "position startpos moves ") {
			; // nothing
		}
		else if (Line == "stop") {
			; // nothing
		}
		else if (Line.substr(0, 3) == "go ") {
			// Received a command like: "go wtime 300000 btime 300000 winc 0 binc 0"
			if (flag == 0) {
				std::cout << "bestmove " << "b8c6" << std::endl;
				flag = 1;
			}
			else {
				std::cout << "bestmove " << "c6b8" << std::endl;
				flag = 0;
			}
			//Output: Moves Black Knight to C6
		}
	}
	cmdLog.close();
	return 0;
}