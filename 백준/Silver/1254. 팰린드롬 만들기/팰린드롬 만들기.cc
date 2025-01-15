#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const int& s, const int& e, const string& str);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;

    int result = s.length() - 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isPalindrome(i, s.length() - 1, s))
        {
            result = i;
        }
    }
    cout << s.length() + result;
    return 0;
}

bool isPalindrome(const int& s, const int& e, const string& str)
{
    for (int i = 0; i < e - s; i++)
    {
        if (str[s + i] != str[e - i])
        {
            return false;
        }
    }
    return true;
}