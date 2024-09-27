#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of rules in CFG: ";
    cin >> n;
    string inp[n], first[n], follow[n], terminals = "abcdefgh+-*ε()";
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
            if (inp[i][j] == '>' || inp[i][j] == '|')
            {
                bool isTerminal = false;
                for (char terminal : terminals)
                {
                    if (inp[i][j + 1] == terminal)
                    {
                        first[i] += inp[i][j + 1];
                        first[i] += ", ";
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
                            first[i] += first[k];
                        }
                    }
                }
            }
        }
    }

    follow[0] = "$, ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 1; k < inp[j].length(); k++)
            {
                if (inp[j][k] == parents[i])
                {
                    bool isTerminal = false;
                    for (char terminal : terminals)
                    {
                        if (inp[j][k + 1] == terminal)
                        {
                            follow[i] += terminal;
                            follow[i] += ", ";
                            isTerminal = true;
                            break;
                        }
                    }
                    if (!isTerminal)
                    {
                        if (inp[j][k + 1] >= 'A' && inp[j][k + 1] <= 'Z')
                        {
                            for (int l = 0; l < n; l++)
                            {
                                if (inp[j][k + 1] == parents[l])
                                {
                                    follow[i] += first[l];
                                }
                            }
                        }
                        else
                        {
                            follow[i] += follow[j];
                        }
                    }
                }
            }
        }
    }

    cout << "~~~~~~~FIRST~~~~~~~" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "FIRST(" << parents[i] << ") = {" << first[i] << "}" << endl;
    }

    cout << "~~~~~~~FOLLOW~~~~~~~" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "FOLLOW(" << parents[i] << ") = {" << follow[i] << "}" << endl;
    }

    return 0;
}
