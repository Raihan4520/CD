#include <iostream>
#include <fstream>

using namespace std;

char operators[] = {'+', '-', '*', '/', '='};
string userDefFuncsFound[50], operatorsFound[50];
int noOfUserDefFuncs = 0, noOfOperators = 0;

bool isNotAdded(string str, string arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == str)
            return false;
    }
    return true;
}

void isVariable(string line)
{
    string word = "", funcName = "";
    for (int i = 0; i < line.length(); i++)
    {
        while (line[i] != ' ' && line[i] != '\0')
        {
            word += line[i];
            i++;
        }
        // cout << word << endl;
        for (int j = 0; j < word.length(); j++)
        {
            if (word[j] == '(' && j < line.length())
            {
                for (int k = 0; k < j; k++)
                {
                    funcName += word[k];
                }

                if (isNotAdded(funcName, userDefFuncsFound, noOfUserDefFuncs) && funcName != "main")
                    userDefFuncsFound[noOfUserDefFuncs++] = funcName;
            }
        }
        funcName = word = "";
    }
}

void findOperators(string line)
{
    string operatorName = "";
    for (int i = 0; i < line.length(); i++)
    {
        for (char op : operators)
        {
            if (line[i] == op)
            {
                if (op == '+')
                    operatorName = "addition";
                else if (op == '-')
                    operatorName = "subtraction";
                else if (op == '*')
                    operatorName = "multiplication";
                else if (op == '/')
                    operatorName = "division";
                else if (op == '=')
                    operatorName = "assignment";

                if (isNotAdded(operatorName, operatorsFound, noOfOperators))
                    operatorsFound[noOfOperators++] = operatorName;
            }
        }
    }
}

int main()
{
    string line;
    ifstream input("program.cpp");
    while (getline(input, line, '\n'))
    {
        isVariable(line);
        findOperators(line);
    }
    input.close();

    for (int i = 0; i < noOfUserDefFuncs; i++)
    {
        cout << "Function-" << i + 1 << ": " << userDefFuncsFound[i] << endl;
    }
    cout << "Total number of the user defined function: " << noOfUserDefFuncs << endl;

    for (int i = 0; i < noOfOperators; i++)
    {
        cout << "Operator-" << i + 1 << ": " << operatorsFound[i] << endl;
    }
    cout << "Total number of the operators: " << noOfOperators << endl;

    return 0;
}
