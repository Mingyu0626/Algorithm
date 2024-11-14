#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;
int idx;
vector<string> word;
bool isCppInput = true;

void checkIsCppInput(string& curWord);
void checkIsJavaInput(string& curWord);
void changeCppToJava();
void changeJavaToCpp();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;

    string temp;
    while (s[idx] != '_' && 90 < s[idx])
    {
        temp += s[idx];
        idx++;
    }
    if (temp.size() == 0)
    {
        cout << "Error!";
        return 0;
    }

    word.push_back(temp);
    temp.clear();
    if (65 <= s[idx] && s[idx] <= 90)
    {
        isCppInput = false;
        temp += s[idx];
    }
    
    if (isCppInput)
    {
        if (idx == s.size() - 1)
        {
            cout << "Error!";
            return 0;
        }
        checkIsCppInput(temp);
        changeCppToJava();
    }
    else
    {
        checkIsJavaInput(temp);
        changeJavaToCpp();
    }

    for (int i = 0; i < word.size(); i++) cout << word[i];
    return 0;
}

void checkIsCppInput(string& curWord)
{
    for (int i = idx + 1; i < s.size(); i++)
    {
        char cur = s[i];
        if (cur == '_')
        {
            if (curWord.size() == 0 || i == s.size() - 1)
            {
                cout << "Error!";
                exit(0);
            }
            word.push_back(curWord);
            curWord.clear();
        }
        else if (65 <= cur && cur <= 90)
        {
            cout << "Error!";
            exit(0);
        }
        else curWord += cur;
    }
    word.push_back(curWord);
}

void checkIsJavaInput(string& curWord)
{
    for (int i = idx + 1; i < s.size(); i++)
    {
        char cur = s[i];
        if (cur == '_')
        {
            cout << "Error!";
            exit(0);
        }
        else if (65 <= cur && cur <= 90)
        {
            if (curWord.size() == 0)
            {
                cout << "Error!";
                exit(0);
            }
            word.push_back(curWord);
            curWord.clear();
            curWord += cur;
        }
        else curWord += cur;
    }
    word.push_back(curWord);
}

void changeCppToJava()
{
    for (int i = 1; i < word.size(); i++)
    {
        word[i][0] -= 32;
    }
}

void changeJavaToCpp()
{
    word[0] += '_';
    for (int i = 1; i < word.size(); i++)
    {
        word[i][0] += 32;
        if (i != word.size() - 1) word[i] += '_';
    }
}