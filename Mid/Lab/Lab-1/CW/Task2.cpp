#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char name[] = "Raihan Ahmed";
    cout << "Length of name is " << strlen(name) << endl;

    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    cout << strcmp(str1, str2) << endl;
    cout << strcmp(str1, str3) << endl;
    cout << strcmp(str2, str3) << endl;

    return 0;
}
