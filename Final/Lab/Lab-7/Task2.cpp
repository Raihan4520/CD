#include <iostream>

using namespace std;

bool is_aStar(string s)
{
    if (s == "ε")
        return true;

    for (char c : s)
    {
        if (c != 'a')
            return false;
    }

    return true;
}

bool is_abcStar(string s)
{
    if (s[0] != 'a' || s[1] != 'b')
        return false;

    if (s == "abε")
        return true;

    for (int i = 2; i < s.length(); i++)
    {
        if (s[i] != 'c')
            return false;
    }

    return true;
}

bool is_abcPlus(string s)
{
    if (s[0] != 'a' || s[1] != 'b' || s[2] != 'c')
        return false;

    for (int i = 3; i < s.length(); i++)
    {
        if (s[i] != 'c')
            return false;
    }

    return true;
}

bool is_aToz(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] >= 'a' && s[0] <= 'z')
        return true;

    return false;
}

bool is_alphanumericPlus(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9'))
            return false;
    }

    return true;
}

bool is_notab(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
            return false;
    }

    return true;
}

bool is_aOrb(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] != 'a' && s[0] != 'b')
        return false;

    return true;
}

int main()
{
    string s, regX;
    cout << "Enter regX: ";
    getline(cin, regX);
    cout << "Enter string: ";
    getline(cin, s);

    if (regX == "a*")
    {
        if (is_aStar(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else if (regX == "abc*")
    {
        if (is_abcStar(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else if (regX == "abc+")
    {
        if (is_abcPlus(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[a-z]")
    {
        if (is_aToz(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[A-Za-z0-9]+")
    {
        if (is_alphanumericPlus(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[^ab]")
    {
        if (is_notab(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else if (regX == "a|b")
    {
        if (is_aOrb(s))
            cout << s << " matches with " << regX << "\nValid" << endl;
        else
            cout << s << " does not matche with " << regX << "\nInvalid" << endl;
    }
    else
        cout << regX << " : regX is invalid" << endl;

    return 0;
}
