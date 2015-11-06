#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{	
	std::string cmd;
	cout << "Write your commands here:\n'exit' to quit" << endl;

	do
	{	
		cout << "$";
		std::getline(std::cin, cmd);

		std::system(cmd.c_str());

		} while (cmd != "exit");

	return 0;
}
