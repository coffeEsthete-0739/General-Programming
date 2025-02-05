#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    else
    {
        return (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
    }
}

int main()
{
    string s;
    cout << "Enter a word: ";
    cin >> s;
    if (isPalindrome(s, 0, s.length() - 1))
    {
        cout << "Palindrome." << endl;
    }
    else
    {
        cout << "Not palindrome." << endl;
    }

    return 0;
}
