#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

bool isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
            return true;
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
    char ch, buffer[15], operators[] = "+-*/%=";
    ifstream fin("program.txt");
    int i, j = 0;
    if (!fin.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }

    while (!fin.eof())
    {
        ch = fin.get();
        for (i = 0; i < 6; ++i)
        {
            if (ch == operators[i])
                cout << ch << " is operator\n";
        }
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == ',' || ch == ';' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
            if (isKeyword(buffer))
                cout << buffer << " is keyword\n";
            else
            {
                if (isIdentifier(buffer))
                    cout << buffer << " is identifier\n";
                else
                    cout << buffer << " is not identifier\n";
            }
        }
    }
    fin.close();

    return 0;
}
