#include <iostream>

using namespace std;

int main()
{
    string inp;
    cout << "Input: ";
    cin >> inp;
    if (inp[0] == '/' && inp[1] == '/')
    {
        cout << "This is a single line comment" << endl;
    }
    else if (inp[0] == '/' && inp[1] == '*' && inp[inp.length() - 1] == '/' && inp[inp.length() - 2] == '*')
    {
        cout << "This is a multiple line comment" << endl;
    }
    else
    {
        cout << "This is not a comment" << endl;
    }

    return 0;
}
