#include <iostream>

using namespace std;

int main()
{
    char name[50];
    int marks, num;
    cout << "Enter number of students: ";
    cin >> num;

    FILE *fptr;
    fptr = fopen("Student.txt", "w");
    if (fptr == NULL)
    {
        cout << "Error!" << endl;
        exit(1);
    }
    for (int i = 0; i < num; i++)
    {
        cout << "For student " << i + 1 << "\nEnter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
        fputs("Name: ", fptr);
        fputs(name, fptr);
        fputs("\nMarks: ", fptr);
        fputs((to_string(marks)).c_str(), fptr);
        fputs("\n\n", fptr);
    }
    fclose(fptr);

    FILE *fp;
    char data[100];
    cout << "Opening the file Student.txt in read mode" << endl;
    fp = fopen("Student.txt", "r");
    if (fp == NULL)
    {
        cout << "Could not open file Student.txt" << endl;
        return 1;
    }
    cout << "Reading the file Student.txt" << endl;
    while (fgets(data, 50, fp) != NULL)
        cout << data;
    cout << "Closing the file Student.txt" << endl;
    fclose(fp);

    return 0;
}
