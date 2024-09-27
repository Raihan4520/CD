#include <iostream>

using namespace std;

int main()
{
    string inp;
    cout << "Input: ";
    cin >> inp;
    int cnt = 0;
    for (int i = 0; i < inp.length(); i++)
    {
        if ((i != inp.length() - 1) && ((inp[i] == '+' && inp[i + 1] == '+') || (inp[i] == '-' && inp[i + 1] == '-') || (inp[i] == '+' && inp[i + 1] == '=') || (inp[i] == '-' && inp[i + 1] == '=') || (inp[i] == '*' && inp[i + 1] == '=') || (inp[i] == '/' && inp[i + 1] == '=') || (inp[i] == '%' && inp[i + 1] == '=') || (inp[i] == '=' && inp[i + 1] == '=') || (inp[i] == '!' && inp[i + 1] == '=') || (inp[i] == '>' && inp[i + 1] == '=') || (inp[i] == '<' && inp[i + 1] == '=') || (inp[i] == '&' && inp[i + 1] == '&') || (inp[i] == '|' && inp[i + 1] == '|') || (inp[i] == '<' && inp[i + 1] == '<') || (inp[i] == '>' && inp[i + 1] == '>') || (inp[i] == '?' && inp[i + 1] == ':') || (inp[i] == '-' && inp[i + 1] == '>')))
        {
            cnt++;
            cout << "Operator" << cnt << ": " << inp[i] << inp[i + 1] << endl;
            i++;
        }
        else if (inp[i] == '+' || inp[i] == '-' || inp[i] == '*' || inp[i] == '/' || inp[i] == '%' || inp[i] == '=' || inp[i] == '>' || inp[i] == '<' || inp[i] == '!' || inp[i] == '&' || inp[i] == '|' || inp[i] == '^' || inp[i] == '~' || inp[i] == '.')
        {
            cnt++;
            cout << "Operator" << cnt << ": " << inp[i] << endl;
        }
    }

    return 0;
}
