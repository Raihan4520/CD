#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream input("split_text.txt");
    string line;
    while (getline(input, line, ';'))
    {
        cout << line << '\n';
    }
    return 0;
}