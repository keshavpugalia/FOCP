/*  Q3) WAP to input a string and check wheather it is a palindrome,
and also count the frequency of every alphabet and 
then replace the vowel with special character(i have used $ here). */

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
void countFrequency(string str);
void replaceVowels(string &str);

int main() {
    string input;
    cout << "Enter a string (Without spaces): ";
    cin >> input;
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    countFrequency(input);
    replaceVowels(input);
    cout << "String after replacing vowels with '$': " << input << endl;
    return 0;
}


// This part is to check if a string is a palindrome
bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false; }
        left++;
        right--;
    }
    return true;
}

// This part is to count and display frequency of each alphabet
void countFrequency(string str) {
    int freq[26] = {0};

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++; 
        } else if (ch >= 'A' && ch <= 'Z') {
            freq[ch - 'A']++;
        }
    }
    cout << "Character frequencies:" << endl;
        for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char(i + 'a') << ": " << freq[i] << endl;
        }
    }
}

// This part will replace vowels with '$'
void replaceVowels(string &str) {
    for (char &ch : str) {
        char lowerCh = (ch >= 'A' && ch <= 'Z') ? (ch + ('a' - 'A')) : ch;  // Convert to lowercase for checking
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            ch = '$';
        }
    }
}
