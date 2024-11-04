#include <iostream>
using namespace std;

bool checkPalindrome(string text, int i) {
    int n = text.length();
    if (i >= n/2) {
        return true;
    }
    if (text[i] != text[n - i - 1]) {
        return false;
    }
    return checkPalindrome(text, i + 1);
}

int main() {
    string text;
    cout << "Enter the text to check for Palindrome : ";
    cin >> text;
    if (checkPalindrome(text, 0)) {
        cout << "Yes, It is a Palindrome." << endl;
    }
    else {
        cout << "No, it is not a Palindrome." << endl;
    }

    return 0;
}