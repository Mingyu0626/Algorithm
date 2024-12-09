#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int t, k, n;
char c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t)
    {
        unordered_map<int, int> um;
        priority_queue<int> pqMax;
        priority_queue<int, vector<int>, greater<int>> pqMin;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> c >> n;
            if (c == 'I')
            {
                pqMax.push(n);
                pqMin.push(n);
                um[n]++;
            }
            else
            {
                if (n == 1 && !pqMax.empty())
                {
                    um[pqMax.top()]--;
                    pqMax.pop();
                }
                if (n == -1 && !pqMin.empty())
                {
                    um[pqMin.top()]--;
                    pqMin.pop();
                }

                while (!pqMax.empty() && um[pqMax.top()] == 0)
                {
                    pqMax.pop();
                }
                while (!pqMin.empty() && um[pqMin.top()] == 0)
                {
                    pqMin.pop();
                }
            }
        }
        
        if (!pqMax.empty() && !pqMin.empty())
        {
            cout << pqMax.top() << ' ' << pqMin.top() << '\n';
        }
        else
        {
            cout << "EMPTY\n";
        }
        t--;
    }
    return 0;
}