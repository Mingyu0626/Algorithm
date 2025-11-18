#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int t, n, x;
char temp;
bool isEmpty, dir;
string p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        deque<int> dq;
        cin >> p >> n;
        isEmpty = false;
        dir = true;

        cin >> temp;
        for (int i = 0; i < n * 2 - 1; i++)
        {
            if (i % 2 == 0)
            {
                cin >> x;
                dq.push_back(x);
            }
            else cin >> temp;
        }
        cin >> temp;

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R') dir = !dir;

            if (p[i] == 'D')
            {
                if (!dq.empty())
                {
                    if (dir) dq.pop_front();
                    else dq.pop_back();
                }
                else
                {
                    cout << "error\n";
                    isEmpty = true;
                    break;
                }
            }
        }

        if (!isEmpty)
        {
            cout << '[';
            if (dir)
            {
                while (!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ',';
                }
            }
            else
            {
                while (!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty()) cout << ',';
                }
            }
            cout << "]\n";
        }
        t--;
    }
    return 0;
}