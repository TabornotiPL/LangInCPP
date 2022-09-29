#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(string pstri)
{
    if (pstri != "" || pstri != " ")
    {
        cout << pstri << endl;
    }

}

bool getFileContentW(std::string fileName, std::vector<std::string>& vecOfStrs)
{
    std::ifstream in(fileName.c_str());
    if (!in)
    {
        std::cerr << "Walbyy: Cannot Open File: " << fileName << std::endl;
        return false;
    }
    std::string str;
    while (std::getline(in, str))
    {
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    in.close();
    return true;
}