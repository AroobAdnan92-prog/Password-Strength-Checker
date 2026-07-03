#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string password;

    cout << "======================================" << endl;
    cout << "     PASSWORD STRENGTH CHECKER" << endl;
    cout << "======================================" << endl;

    cout << "\nEnter Password: ";
    cin >> password;

    // Common leaked passwords
    if (password == "123456" || password == "password" ||
        password == "admin" || password == "qwerty" ||
        password == "abc123")
    {
        cout << "\nPassword Strength : WEAK PASSWORD" << endl;
        cout << "Reason : Common leaked password." << endl;
        return 0;
    }

    int length = password.length();

    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    // Check every character
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            hasUpper = true;

        else if (islower(password[i]))
            hasLower = true;

        else if (isdigit(password[i]))
            hasNumber = true;

        else if (!isalnum(password[i]))
            hasSymbol = true;
    }

    cout << "\n========== PASSWORD ANALYSIS ==========" << endl;
    cout << "Password Length : " << length << endl;
    cout << "Uppercase       : " << (hasUpper ? "Yes" : "No") << endl;
    cout << "Lowercase       : " << (hasLower ? "Yes" : "No") << endl;
    cout << "Number          : " << (hasNumber ? "Yes" : "No") << endl;
    cout << "Special Symbol  : " << (hasSymbol ? "Yes" : "No") << endl;

    cout << "\n========== PASSWORD STRENGTH ==========" << endl;

    if (length >= 8 && hasUpper && hasLower && hasNumber && hasSymbol)
    {
        cout << "Strong Password" << endl;
    }
    else if (length >= 6 && ((hasUpper && hasLower) || hasNumber))
    {
        cout << "Medium Password" << endl;
    }
    else
    {
        cout << "Weak Password" << endl;
    }

    cout << "\nSuggestions:" << endl;

    if (length < 8)
        cout << "- Password should be at least 8 characters long." << endl;

    if (!hasUpper)
        cout << "- Add at least one uppercase letter." << endl;

    if (!hasLower)
        cout << "- Add at least one lowercase letter." << endl;

    if (!hasNumber)
        cout << "- Add at least one number." << endl;

    if (!hasSymbol)
        cout << "- Add at least one special symbol (@, #, $, %, &, etc.)." << endl;

    if (length >= 8 && hasUpper && hasLower && hasNumber && hasSymbol)
        cout << "- Excellent! Your password is secure." << endl;

    return 0;
}
