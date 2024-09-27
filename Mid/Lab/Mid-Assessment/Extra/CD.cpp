#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const char ops[] = {'+', '-', '*', '/', '='};
const string opNames[] = {"addition", "subtraction", "multiplication", "division", "assignment"};

string userDef[100];
int indexUserDef = -1;

string operators[100];
int indexOperators = -1;

bool isStringInArray(string str, string arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (arr[i] == str)
        {
            return true;
        }
    }
    return false;
}

bool isCharInArray(char arr[], int length, char c)
{
    for (int i = 0; i < length; ++i)
    {
        if (arr[i] == c)
        {
            return true;
        }
    }
    return false;
}

bool isOperator(char c)
{
    for (int i = 0; i < 5; ++i)
    {
        if (c == ops[i])
        {
            return true;
        }
    }
    return false;
}

string getOperatorName(char c)
{
    if (isOperator(c))
    {
        for (int i = 0; i < 5; ++i)
        {
            if (c == ops[i])
            {
                return opNames[i];
            }
        }
    }
    return "Not an operator";
}

void findOperators(string line)
{
    int length = line.length();
    for (int i = 0; i < length; ++i)
    {
        if (isOperator(line[i]))
        {
            if (!isStringInArray(getOperatorName(line[i]), operators, indexOperators + 1))
            {
                operators[++indexOperators] = getOperatorName(line[i]);
            }
        }
    }
}

void findUserDefinedFunction(string line)
{
    string word = "";
    int length = line.length();
    for (int i = 0; i < length; ++i)
    {
        if (line[i] != ' ')
        {
            word += line[i];
        }
        else
        {
            if (word.find('(') < length)
            {
                if (!isStringInArray(word.substr(0, word.find('(')), userDef, indexUserDef + 1))
                {
                    userDef[++indexUserDef] = word.substr(0, word.find('('));
                }
            }
            word = "";
        }
    }
}

int main()
{
    string myText;
    string lines[100];
    ifstream MyReadFile("program.cpp");
    int lineIndex = -1;
    while (getline(MyReadFile, myText))
    {
        lines[++lineIndex] = myText;
    }
    MyReadFile.close();
    for (auto &&i : lines)
    {
        cout << i << endl;
    }

    for (int i = 0; i <= lineIndex; ++i)
    {
        findUserDefinedFunction(lines[i]);
        findOperators(lines[i]);
    }
    for (int i = 0; i <= indexUserDef; ++i)
    {
        cout << "Function-" << i + 1 << ":" << userDef[i] << endl;
    }
    cout << "Total number of user defined function: " << indexUserDef + 1 << endl;

    for (int i = 0; i <= indexOperators; ++i)
    {
        cout << "Operator-" << i + 1 << ":" << operators[i] << endl;
    }
    cout << "Total number of the operators: " << indexOperators + 1 << endl;
    return 0;
}
