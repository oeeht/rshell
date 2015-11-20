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

//function to split the commands entered by the user

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
if (cmd != "exit")
{
	if((cmd.find("[") != string::npos) || (cmd.find("test") != string::npos))
		{
			cout << "It's a test" << endl;

			if ((cmd.find("-e") != string::npos) || (cmd.find("-f") != string::npos) || (cmd.find("-d") != string::npos))
				{
					if (cmd.find("-f") != string::npos)
						{
							int testing = system(cmd.c_str());
							if (testing == 0)
								{
									cout << "FILE EXISTS" << endl;
								}
							else
								{
									cout << "NOT A FILE OR DOES NOT EXIST" << endl;

								}

						}

						if (cmd.find("-d") != string::npos)
						{
							int testing = system(cmd.c_str());
							if (testing == 0)
								{
									cout << "DIRECTORY EXISTS" << endl;
								}
							else
								{
									cout << "NOT A DIRECTORY OR DOES NOT EXIST" << endl;

								}

						}
						if (cmd.find("-e") != string::npos)
						{
							int testing = system(cmd.c_str());
							if (testing == 0)
								{
									cout << "FILE OR DIRECTORY EXISTS" << endl;
								}
							else
								{
									cout << "FILE OR DIRECTORY DOESNT NOT EXIST" << endl;

								}
						}
					
				}
			else
				{
					size_t bracket = 2;
					size_t test = 5;
					string flag = "-e ";

					if (cmd.find("[") != string::npos)
						{
							string new_cmd;
							new_cmd = cmd.insert(bracket, flag);
							int testing = system(new_cmd.c_str());
							if (testing == 0)
								{
									cout << "FILE OR DIRECTORY EXISTS" << endl;
								}
							else
								{
									cout << "FILE OR DIRECTORY DOESNT NOT EXIST" << endl;

								}
						}
				
					else if (cmd.find("test") != string::npos)
						{
							string new_cmd;
							new_cmd = cmd.insert(test, flag);
							int testing = system(new_cmd.c_str());
							if (testing == 0)
								{
									cout << "FILE OR DIRECTORY EXISTS" << endl;
								}
							else
								{
									cout << "FILE OR DIRECTORY DOESNT NOT EXIST" << endl;

								}
						}
				}

			}

		else
		{
			system(cmd.c_str());
		}
}

}

int main()
{
	string cmd;
	vector<string> allComm;
	cout << "\n== TYPE YOUR COMMANDS ==\n'exit' to quit\n" << endl;

	while (cmd != "exit")
	{	
		//get the user username and hostname
		char user[100];
		char host[100];
		getlogin_r(user, sizeof(user)-1);
		gethostname(host, sizeof(host)-1);
		
		//print them
		cout << "[" << user << "@" << host << " ~]$ \n";
		
		//get what the user entered
		std::getline(cin, cmd);

		//divide the commands entered and execute them with the functions
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

	} 

	return 0;
}
