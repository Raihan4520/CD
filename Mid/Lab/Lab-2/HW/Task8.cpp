#include <iostream>

using namespace std;

int main()
{
    string inp;
    cout << "Input: ";
    cin >> inp;
    bool flag = false;
    if (inp[0] >= 'A' && inp[0] <= 'Z' || (inp[0] >= 'a' && inp[0] <= 'z') || inp[0] == '_')
    {
        for (char val : inp)
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
        cout << "Identifier" << endl;
    else
        cout << "Not Identifier" << endl;

    return 0;
}
