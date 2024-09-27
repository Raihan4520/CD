#include <iostream>

using namespace std;

int main()
{
    FILE *fp;
    int vowel = 0, consonant = 0;
    char ch;
    char message[200];

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Source can't be opened");
        return -1;
    }

    while (!feof(fp))
    {
        fgets(message, 200, fp);
        cout << message;
    }
    cout << "'\n\n";

    fseek(fp, 0, SEEK_SET);

    while (ch != EOF)
    {
        ch = fgetc(fp);
        if ((ch == 'a') || (ch == 'A') || (ch == 'e') || (ch == 'E') || (ch == 'i') || (ch == 'I') || (ch == 'o') || (ch == 'O') || (ch == 'u') || (ch == 'U'))
        {
            vowel++;
            cout << '(' << ch << ") ";
        }
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            consonant++;
            cout << ch << ' ';
        }
    }
    fclose(fp);

    cout << "\n\nNumber of vowels are = " << vowel << endl;
    cout << "Number of consonants are = " << consonant << endl;

    return 0;
}
