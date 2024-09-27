#include <iostream>

using namespace std;

int main()
{
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
    string inp;
    cout << "Enter a word to check: ";
    cin >> inp;
    for (string val : keywords)
    {
        if (inp == val)
        {
            cout << "This is a keyword" << endl;
            return 0;
        }
    }
    cout << "This is not a keyword" << endl;

    return 0;
}
