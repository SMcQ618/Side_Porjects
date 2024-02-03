#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//A funcition that generates a random character
char getRandomChar(const string& charSet) {
    return charSet[rand() % charSet.length()];
}

//Generates a random password based off the user's choices
string generatePass(int length, bool includeUC, bool includeNums, bool includeSymb) {
    string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numberChars = "01234567889";
    string symbolChars = "!@#$%^&*()_-+=<>?/;:[]{}";

    string allChars = lowercaseChars;

    if (includeUC)
        allChars += uppercaseChars;
    if (includeNums)
        allChars += numberChars;
    if (includeSymb)
        allChars += symbolChars;
    if (includeUC)
        allChars += uppercaseChars;

    if (allChars.empty()) {
        cerr << "Error: No character set selected.\n";
        return "";
    }

    string password;
    for(int i = 0; i < length; ++i) {
        password += getRandomChar(allChars);
    }

    return password;
}

int main(){
    //seed the random number with the current time
    srand(time(0));

    //get the user's options
    int length;
    bool includeUC, includeNums,includeSymb;

    cout << "Password Length: ";
    cin >> length;
    cout << "Inlcude Uppercase? (1 or 0): ";
    cin >> includeUC;
    cout << "Include Numbers? (1 or 0): ";
    cin >> includeNums;
    cout << "Include any Symbols? (1 or 0): ";
    cin >> includeSymb;

    //generate the password and show it
    string password = generatePass(length, includeUC, includeNums, includeSymb);

    if(!password.empty()) {
        cout << "\nGenerated Password: " << password << "\n";
    }

    return 0;
}
