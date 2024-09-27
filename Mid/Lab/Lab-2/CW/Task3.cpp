#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    FILE *fptr;
    fptr = fopen("Hello_World.txt", "a");
    if (fptr == NULL)
    {
        cout << "Error!" << endl;
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        fputs("Hello World;", fptr);
    }
    fclose(fptr);

    fstream input("Hello_World.txt");
    string line;
    while (getline(input, line, ';'))
        cout << line << endl;

    return 0;
}
