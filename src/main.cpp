#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <errno.h>
#include <unistd.h>
#include <algorithm>
#include <iostream>

using namespace std;

//function to delete comments
string delComm(string comment)
{
	if(comment.find('#') != string::npos)
	{
		return comment.substr(0, comment.find('#'));
	}else
		return comment;
}

//split the commands entered by the user

vector<string> split(string command)
{
	vector <string> commands;
	string nextComm;
	int numComm = count(command.begin(), command.end(), ';');

	for(int i = 0; i < numComm; i++)
	{
		nextComm = command.substr(0, command.find(';'));
		int comm = nextComm.length();
		commands.push_back(nextComm);
		command = command.erase(0, comm + 1);
	}

	return commands;
}

//function to execute a command
void doCmd(string cmd)
{
	system(cmd.c_str());
}

int main()
{
	string cmd;
	vector<string> allComm;
	cout << "\n== TYPE YOUR COMMANDS ==\n'quit' to exit\n" << endl;

	do
	{	
		//get the user username and hostname
		char user[100];
		char host[100];
		getlogin_r(user, sizeof(user)-1);
		gethostname(host, sizeof(host)-1);
		
		//print them
		cout << "[" << user << "@" << host << " ~]$ ";
		
		//get what the user entered
		std::getline(cin, cmd);

		//divide the commands entered
		if(cmd.find(';') != string::npos)
		{	
			allComm = split(cmd);

			for (vector<string>::iterator i = allComm.begin(); i != allComm.end(); i++)
			{
				doCmd(*i);
			}
		} else
		{
			doCmd(cmd);
		}
			

	} while (cmd != "quit");

	return 0;
}
