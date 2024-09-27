#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of rules in CFG: ";
    cin >> n;
    string inp[n], res[n], terminals = "abcd+-*ε()";
    char parents[n];
    cout << "Enter CFG: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        parents[i] = inp[i][0];
        for (int j = 0; j < inp[i].length(); j++)
        {
            bool isTerminal = false;
            if (inp[i][j] == '>' || inp[i][j] == '|')
            {
                for (char terminal : terminals)
                {
                    if (inp[i][j + 1] == terminal)
                    {
                        res[i] += inp[i][j + 1];
                        res[i] += ", ";
                        isTerminal = true;
                        break;
                    }
                }
                if (!isTerminal)
                {
                    for (int k = n - 1; k >= 0; k--)
                    {
                        if (inp[i][j + 1] == parents[k])
                        {
                            res[i] += res[k];
                        }
                    }
                }
            }
        }
    }

    cout << "~~~~~~~FIRST~~~~~~~" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "FIRST(" << parents[i] << ") = {" << res[i] << "}" << endl;
    }

    return 0;
}
