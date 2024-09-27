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
            FILE *fptr;
            fptr = fopen("Valid_Keyword.txt", "a");
            if (fptr == NULL)
            {
                cout << "Error!" << endl;
                return 1;
            }
            if (val == inp)
            {
                fputs(val.c_str(), fptr);
                fputs("\n", fptr);
            }
            fclose(fptr);
        }
    }

    return 0;
}
