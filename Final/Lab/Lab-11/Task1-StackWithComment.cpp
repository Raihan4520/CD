#include <iostream>
using namespace std;
// 100 size stack is taken and n contains the size of stack and top is pointing to -1 as the stack is empty
int stack[100], n = 100, top = -1;
void push(int val)
{
    // first check if stack is full
    if (top >= n - 1) // if top is equal or greater than last index then stack full
    {
        cout << "Stack Overflow" << endl;
    }
    // else insert value to stack top
    else
    {
        top++;            // increase top by one to point to new empty space
        stack[top] = val; // insert the parameter value into this new top position
    }
}
void pop()
{
    // first check is stack is empty
    if (top <= -1) // if top becomes -1 or less then stack is empty
    {
        cout << "Stack Underflow" << endl;
    }
    // else pop an element from stack top
    else
    {
        cout << "The popped element is " << stack[top] << endl; // printing the top element
        top--;                                                  // decreasing the value of top by one to point to the previous element to delete current top element
    }
}
void display()
{
    // first check if stack is not empty
    if (top >= 0) // if top is 0 or greater then stack has some value to print
    {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--) // printing elements from stack top to 0 th index using loop
            cout << stack[i] << " ";
        cout << endl;
    }
    else // else if stack is empty then print stack is empty
        cout << "Stack is empty" << endl;
}
int main()
{
    // ch taken for option and val is taken for taking value for inserting into the stack
    int ch, val;
    // outputting options
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    // using do while loop to execute atleast once and run until selecting exit option
    do
    {
        // taking input for option
        cout << "Enter choice: " << endl;
        cin >> ch;
        // using switch case to execute selected option
        switch (ch)
        {
        // if ch value is 1 for option then take value as input and call push function
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        // if ch value is 2 for option then take call pop function
        case 2:
        {
            pop();
            break;
        }
        // if ch value is 3 for option then take call display function
        case 3:
        {
            display();
            break;
        }
        // if ch value is 4 for option then print Exit and break while loop
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        // if ch value is anything exceprt 1,2,3,4 for option then print Invalid Choice
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4); // if ch value is 4 for option then break while loop
    return 0;
}