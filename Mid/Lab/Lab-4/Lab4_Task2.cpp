#include <iostream>

using namespace std;

bool isCorrect(string s)
{
    bool isValid = false;
    if (s[0] == ' ' || s[s.length() - 1] != '.')
        return isValid;
    else if (s[0] >= 'A' && s[0] <= 'Z')
        isValid = true;
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == ' ')
        {
            if ((s[i + 1] >= 'A' && s[i + 1] <= 'Z') || (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
            {
                isValid = true;
                i++;
            }
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
            isValid = true;
        else
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}

int main()
{
    string s = "I am coding.";
    if (isCorrect(s))
        cout
            << s << " : Valid" << endl;
    else
        cout << s << " : Invalid" << endl;

    return 0;
}
