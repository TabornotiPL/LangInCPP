#include "easylang.h"
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	// zmienne
	map<string, string> vars = {};
	string varame = "";
	string varval = "";
	list<string> listOfVars = {};

	// ccritical
	string tok;
	int state = 0;
	int state2 = 0;
	string status = "";
	string status2 = "";
	int linen = 0;

	// IO
	string printString;
	string lastInput;

	std::vector<std::string> vecOfStr;
	bool result = getFileContentW("test.haja", vecOfStr);
	if (result)
	{
		for (string& line : vecOfStr)
		{
			linen++;
			for (int i = 0;i != line.length();i++)
			{
			start:
				tok += line[i];

				if (state == 0)
				{
					if (tok == " ")
					{
						tok = "";
					}
				}

				//jezyk


				//find print
				if (tok == "print:")
				{
					tok = "";
					status = "print";
				}

				if (status == "print" || status == "printing")
				{
					if (tok == "\"")
					{
						if (state == 0)
						{
							tok = "";
							state = 1;
							status = "printing";
							state2 = 1;
							status = "";
							goto start;
						}
					}

					
				}

				if (state2 == 1)
				{
					if (line[i] == '\"')
					{
						tok.pop_back();
						if (tok != "\n" && tok != "" && tok != " " && tok != "\"")
						{
							print("\b" + tok);
							tok = "";
							state = 0;
							state2 = 0;
							status = "";
						}
					}
				}
			}
		}
	}

}