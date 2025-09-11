#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string ps, s;
int n, num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ps >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        int wordLength = s.length();
        if (ps.length() < wordLength)
        {
            continue;
        }
        for (int j = 0; j <= ps.length() - wordLength; ++j)
        {
            string ss = ps.substr(j, wordLength);
            bool isIncluded = true;
            int diff = s[0] - ss[0];
            diff += diff < 0 ? 26 : 0;
            for (int k = 1; k < wordLength; ++k)
            {
                int curDiff = s[k] - ss[k];
                curDiff += curDiff < 0 ? 26 : 0;

                if (diff != curDiff)
                {
                    isIncluded = false;
                }
            }
            if (isIncluded)
            {
                num = diff;
            }
        }
    }

    for (int i = 0; i < ps.length(); ++i)
    {
        unsigned char newChar = ps[i] + num;
        newChar -= 'z' < newChar ? 26 : 0;
        cout << newChar;
    }
    return 0;
}