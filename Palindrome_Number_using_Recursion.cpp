#include <bits/stdc++.h>
using namespace std;
int isPalindrome(int n, int temp)
{
    if (n == 0)
    {
        return temp;
    }
    temp = (temp * 10) + (n % 10);
    return isPalindrome(n / 10, temp);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n == isPalindrome(n, 0))
    {
        cout << "Palindrome." << endl;
    }
    else
    {
        cout << "Not palindrome." << endl;
    }

    return 0;
}