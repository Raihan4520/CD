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

bool is_abc(string s)
{
    if (s.length() != 3)
        return false;

    if (s[0] == 'a' && s[1] == 'b' && s[2] == 'c')
        return true;

    return false;
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

bool is_a_bcPlus(string s)
{
    if (s[0] != 'a')
        return false;
    cout << s << endl;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != 'b' || s[i + 1] != 'c')
            return false;

        i++;
    }

    return true;
}

bool is_a_bcQuestion(string s)
{
    if (s == "a" || s == "abc")
        return true;

    return false;
}

bool is_a_b_c(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] == 'a' || s[0] == 'b' || s[0] == 'c')
        return true;

    return false;
}

bool is_aToz(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] >= 'a' && s[0] <= 'z')
        return true;

    return false;
}

bool is_a_minus_z(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] == 'a' || s[0] == '-' || s[0] == 'z')
        return true;

    return false;
}

bool is_minus_a_z(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] == '-' || s[0] == 'a' || s[0] == 'z')
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

bool is_whitespace(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
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

bool is_a_XOR_b(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] == 'a' || s[0] == '^' || s[0] == 'b')
        return true;

    return false;
}

bool is_a_OR_b(string s)
{
    if (s.length() != 1)
        return false;

    if (s[0] == 'a' || s[0] == '|' || s[0] == 'b')
        return true;

    return false;
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

    if (regX == "a*")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_aStar(s))
            cout << s << " matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "abc")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_abc(s))
            cout << s << " matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "abc*")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_abcStar(s))
            cout << s << " matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "abc+")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_abcPlus(s))
            cout << s << " matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "a(bc)+")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_a_bcPlus(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "a(bc)?")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_a_bcQuestion(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[abc]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_a_b_c(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[a-z]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_aToz(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[a\\-z]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_a_minus_z(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[-az]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_minus_a_z(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[A-Za-z0-9]+")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_alphanumericPlus(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[ \\t\\n]+")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_whitespace(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[^ab]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_notab(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[a^b]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_a_XOR_b(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "[a|b]")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_a_OR_b(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else if (regX == "a|b")
    {
        cout << "Enter string: ";
        getline(cin, s);
        if (is_aOrb(s))
            cout << s << " ---> matches with regX: " << regX << "\nValid" << endl;
        else
            cout << s << " ---> does not match with regX: " << regX << "\nInvalid" << endl;
    }
    else
        cout << regX << " ---> regX is invalid" << endl;

    return 0;
}
