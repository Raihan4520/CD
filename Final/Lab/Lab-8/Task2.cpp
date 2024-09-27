#include <iostream>

using namespace std;

int currPos = 0;
string name[100];
string val[100];

void insert()
{
    string n, v;
    cout << "Enter name to insert: ";
    cin >> n;
    for (int i = 0; i < currPos; i++)
    {
        if (name[i] == n)
        {
            cout << "Duplicate Symbol" << endl;
            return;
        }
    }
    cout << "Enter value for this name: ";
    cin >> v;
    name[currPos] = n;
    val[currPos] = v;
    currPos++;
    cout << "Inserted successfully" << endl;
}

void display()
{
    cout << "Symbol Table:" << endl;
    for (int i = 0; i < currPos; i++)
    {
        cout << "Name: " << name[i] << " ---> Value: " << val[i] << endl;
    }
}

void del()
{
    string n;
    cout << "Enter name to delete: ";
    cin >> n;
    for (int i = 0; i < currPos; i++)
    {
        if (name[i] == n)
        {
            for (int j = i; j < currPos; j++)
            {
                name[j] = name[j + 1];
                val[j] = val[j + 1];
            }
            currPos--;
            cout << "Deleted successfully" << endl;
            return;
        }
    }
    cout << "Label Not found" << endl;
}

int main()
{
    bool run = true;
    int option;
    do
    {
        cout << "1. Insert\n2. Display\n3. Delete\n4. Exit" << endl;
        cout << "Choose option: ";
        cin >> option;
        if (option == 1)
            insert();
        else if (option == 2)
            display();
        else if (option == 3)
            del();
        else if (option == 4)
            run = false;
        else
            cout << "Wrong option" << endl;
    } while (run);

    return 0;
}
