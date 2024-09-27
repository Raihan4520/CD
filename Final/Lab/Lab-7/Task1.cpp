#include <iostream>

using namespace std;

void isSubString(string s1, string s2)
{
    bool valid = false;
    for (int i = 0; i <= (s1.length() - s2.length()); i++)
    {
        if (s1[i] == s2[0])
        {
            for (int j = 0; j < s2.length(); j++)
            {
                if (s1[i] == s2[j])
                {
                    valid = true;
                    i++;
                }
                else
                {
                    valid = false;
                }
            }
            if (valid)
            {
                cout << "Position: " << i - s2.length() << endl;
                return;
            }
        }
    }
    cout << "Position: " << -1 << endl;
}

int main()
{
    string s1, s2;
    cout << "Enter string 1: ";
    getline(cin, s1);
    cout << "Enter string 2: ";
    getline(cin, s2);

    isSubString(s1, s2);

    return 0;
}
