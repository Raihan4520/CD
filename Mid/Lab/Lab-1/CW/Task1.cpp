#include <iostream>

using namespace std;

int factorial_cal(int n)
{
    int factorial = 1;
    if (n < 0)
    {
        cout << "Factorial of negative number is a complex. Please enter a positive number";
        return -1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            factorial *= i;
        return factorial;
    }
}

int main()
{
    int input, res;
    cout << "Enter a positive number: ";
    cin >> input;
    res = factorial_cal(input);
    if (res >= 0)
        cout << "Factorial of " << input << " is " << res << endl;

    return 0;
}
