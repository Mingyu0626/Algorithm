#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int t, n, num;
bool dir;
char temp;
string s;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t--)
    {
        cin >> s >> n;
        dq.clear();
        dir = true;

        for (int i = 0; i < n * 2 + 1; ++i)
        {
            if (i % 2 == 1)
            {
                cin >> num;
                dq.emplace_back(num);
            }
            else
            {
                cin >> temp;
            }
        }
        if (n == 0)
        {
            cin >> temp;
        }

        bool errorOccured = false;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'R')
            {
                dir = !dir;
            }
            else
            {
                if (!dq.empty())
                {
                    if (dir)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
                else
                {
                    cout << "error\n";
                    errorOccured = true;
                    break;
                }
            }
        }
        
        if (!errorOccured)
        {
            cout << '[';
            while (!dq.empty())
            {
                if (dir)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }

                if (!dq.empty())
                {
                    cout << ',';
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}