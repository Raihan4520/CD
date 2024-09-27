#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string preprocessors[] = {"include", "define", "undef", "if", "elif", "endif", "ifdef", "ifndef", "else", "error", "line", "pragma"};
string variablesFound[50], preprocessorsFound[50];
int noOfVariables = 0, noOfPreprocessors = 0;
bool isMain = false;

bool isKeyword(string var)
{
    char keywords[38][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while", "max", "min", "using", "namespace", "std", "cout"};
    for (int i = 0; i < 38; ++i)
    {
        if (strcmp(keywords[i], var.c_str()) == 0)
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
    string word = "", varName = "";
    for (int i = 0; i < line.length(); i++)
    {
        while (line[i] != ' ' && line[i] != ',' && line[i] != '=' && line[i] != ';' && line[i] != '\0')
        {
            word += line[i];
            i++;
        }
        if (strstr(word.c_str(), "main"))
            isMain = true;

        if (isMain && isIdentifier(word) && !isKeyword(word))
        {
            if (isNotAdded(word, variablesFound, noOfVariables))
                variablesFound[noOfVariables++] = word;
        }

        word = "";
    }
}

void findPreprocessor(string line)
{
    string word = "", preprocessorName = "";
    for (int i = 0; i < line.length(); i++)
    {
        while (line[i] != ' ' && line[i] != ',' && line[i] != '=' && line[i] != ';' && line[i] != '\0')
        {
            word += line[i];
            i++;
        }

        if (word[0] == '#')
        {
            for (string preprocessor : preprocessors)
            {
                if (strstr(word.c_str(), preprocessor.c_str()))
                    preprocessorName = preprocessor;
            }
            if (isNotAdded(preprocessorName, preprocessors, noOfPreprocessors))
                preprocessorsFound[noOfPreprocessors++] = preprocessorName;
        }

        preprocessorName = word = "";
    }
}

int main()
{
    string line;
    ifstream input("program.cpp");
    while (getline(input, line, '\n'))
    {
        isVariable(line);
        findPreprocessor(line);
    }
    input.close();

    for (int i = 0; i < noOfVariables; i++)
    {
        cout << "Variable-" << i + 1 << ": " << variablesFound[i] << endl;
    }
    cout << "Total number of the variables: " << noOfVariables << endl;

    for (int i = 0; i < noOfPreprocessors; i++)
    {
        cout << "Operator-" << i + 1 << ": " << preprocessorsFound[i] << endl;
    }
    cout << "Total number of preprocessor: " << noOfPreprocessors << endl;

    return 0;
}
