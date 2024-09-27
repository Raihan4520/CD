#include <iostream>

using namespace std;

int main()
{
    string inp;
    cout << "Input: ";
    cin >> inp;
    for (char val : inp)
    {
        if (val < '0' || val > '9')
        {
            cout << "Not numeric" << endl;
            return 0;
        }
    }
    cout << "Numeric constant" << endl;

    return 0;
}
