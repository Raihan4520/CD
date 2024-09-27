#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string keywords[] = {"auto",
                     "double",
                     "int",
                     "struct",
                     "break",
                     "else",
                     "long",
                     "switch",
                     "case",
                     "enum",
                     "register",
                     "typedef",
                     "char",
                     "extern",
                     "return",
                     "union",
                     "const",
                     "float",
                     "short",
                     "unsigned",
                     "continue",
                     "for",
                     "signed",
                     "void",
                     "default",
                     "goto",
                     "sizeof",
                     "voltile",
                     "do",
                     "if",
                     "static",
                     "while"};

bool isKeyword(string s)
{
    for (auto &&val : keywords)
    {
        if (s == val)
        {
            return true;
        }
    }
    return false;
}

bool isOperator(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((i != s.length() - 1) && ((s[i] == '+' && s[i + 1] == '+') || (s[i] == '-' && s[i + 1] == '-') || (s[i] == '+' && s[i + 1] == '=') || (s[i] == '-' && s[i + 1] == '=') || (s[i] == '*' && s[i + 1] == '=') || (s[i] == '/' && s[i + 1] == '=') || (s[i] == '%' && s[i + 1] == '=') || (s[i] == '=' && s[i + 1] == '=') || (s[i] == '!' && s[i + 1] == '=') || (s[i] == '>' && s[i + 1] == '=') || (s[i] == '<' && s[i + 1] == '=') || (s[i] == '&' && s[i + 1] == '&') || (s[i] == '|' && s[i + 1] == '|') || (s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '>') || (s[i] == '?' && s[i + 1] == ':') || (s[i] == '-' && s[i + 1] == '>')))
        {
            return true;
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '=' || s[i] == '>' || s[i] == '<' || s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '^' || s[i] == '~' || s[i] == '.')
        {
            return true;
        }
    }
    return false;
}

bool isIdentifier(string s)
{
    bool flag = false;
    if (s[0] >= 'A' && s[0] <= 'Z' || (s[0] >= 'a' && s[0] <= 'z') || s[0] == '_')
    {
        for (char val : s)
        {
            if ((val >= 'A' && val <= 'Z') || (val >= 'a' && val <= 'z') || val == '_' || (val >= '0' && val <= '9'))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        flag = false;
    }

    if (flag)
        return true;
    else
        return false;
}

int main()
{
    ifstream input("program.txt");
    string line, word;
    int cntOp = 0, cntKy = 0, cntId = 0;
    while (getline(input, line, ' '))
    {
        if (isOperator(line))
        {
            cntOp++;
            cout << "Operator " << cntOp << ": " << line << endl;
        }
        if (isKeyword(line))
        {
            cntKy++;
            cout << "Keyword " << cntKy << ": " << line << endl;
        }
        else if (isIdentifier(line))
        {
            cntId++;
            cout << "Identifier " << cntId << ": " << line << endl;
        }
        else
        {
            cout << "Invalid identifier: " << line << endl;
        }
    }

    return 0;
}
