#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, p, sNum, pNum, result;
vector<stack<int>> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> p;
    s.assign(7, stack<int>());
    for (int i = 0; i < n; ++i)
    {
        cin >> sNum >> pNum;
        while (!s[sNum].empty() && pNum < s[sNum].top())
        {
            s[sNum].pop();
            result++;
        }
        if (!s[sNum].empty() && pNum == s[sNum].top())
        {
            continue;
        }
        s[sNum].push(pNum);
        result++;
    }

    cout << result;
    return 0;
}