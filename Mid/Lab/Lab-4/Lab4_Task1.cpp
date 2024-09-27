#include <iostream>

using namespace std;

int main()
{
    string eqn;
    int cntOperator = 0;
    bool isBracket = false, isOperand = false, isOperator = false;
    cout << "Enter an equation: ";
    cin >> eqn;
    for (int i = 0, j = eqn.length() - 1; i < eqn.length(); i++, j--)
    {
        if (eqn[i] == '(')
        {
            if (eqn[j] == ')')
                isBracket = true;
            else
                isBracket = false;
        }
        else if (eqn[i] == '{')
        {
            if (eqn[j] == '}')
                isBracket = true;
            else
                isBracket = false;
        }
        else if (eqn[i] == '[')
        {
            if (eqn[j] == ']')
                isBracket = true;
            else
                isBracket = false;
        }
        else
        {
            if (eqn[i] > 96 && eqn[i] < 123)
                isOperand = true;
            else if (eqn[i] == '+' || eqn[i] == '-' || eqn[i] == '/' || eqn[i] == '*')
                cntOperator++;
            else if (eqn[i] == ')' || eqn[i] == '}' || eqn[i] == ']')
                continue;
            else
            {
                isOperand = false;
            }
        }
    }
    if (isBracket && isOperand && cntOperator == 1)
        cout << "valid" << endl;
    else
        cout << "Not valid" << endl;

    return 0;
}
