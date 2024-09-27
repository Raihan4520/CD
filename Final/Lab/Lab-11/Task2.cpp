#include <iostream>

using namespace std;

string parseTree[4][8] = {{"FIRST", "FOLLOW", "NT", "a", "b", "c", "d", "$"},
                          {"a", "$", "S", "S->aABb", "", "", "", ""},
                          {"ce", "db", "A", "", "A->e", "A->c", "A->e", ""},
                          {"de", "b", "B", "", "B->e", "", "B->d", ""}};

char stack[100], n = 100, top = -1;
void push(char val)
{
    if (top >= n - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
{
    if (top <= -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty" << endl;
}

int main()
{
    string inp;
    cout << "Enter a string to test: ";
    cin >> inp;
    cout << endl;
    inp += '$';
    push('$');
    push('S');
    cout << "~~~~~~~~~~~~Initial Stack and Input string~~~~~~~~~~~~" << endl;
    display();
    for (char c : inp)
    {
        cout << c << ' ';
    }

    cout << "\n\n";
    // display();
    int inpPos = 0;
    while (stack[top] != '$' && inp[inpPos] != '$')
    {
        int parseRow = -1, parseCol = -1;
        for (int i = 3; i < 8; i++)
        {
            if (inp[inpPos] == parseTree[0][i][0])
            {
                parseCol = i;
                break;
            }
        }
        //cout << parseCol << endl;

        if (stack[top] == 'S')
        {
            parseRow = 1;
        }
        else if (stack[top] == 'A')
        {
            parseRow = 2;
        }
        else if (stack[top] == 'B')
        {
            parseRow = 3;
        }

        if (!(stack[top] >= 'A' && stack[top] <= 'Z'))
        {
            if (stack[top] == inp[inpPos])
            {
                pop();
                inpPos++;
            }
        }
        else
        {
            string move = parseTree[parseRow][parseCol];
            pop();
            for (int i = move.length() - 1; i >= 0; i--)
            {
                if (move[i] != '>')
                {
                    push(move[i]);
                }
                else
                {
                    break;
                }
            }
        }
        cout << "~~~~~~~~~~~~Stack and Input string~~~~~~~~~~~~" << endl;
        display();
        cout << "Input: ";
        for (int i = inpPos; i < inp.length(); i++)
        {
            cout << inp[i] << ' ';
        }
        cout << "\n\n";
    }
    cout << "Accepted" << endl;

    return 0;
}
