#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int n, k;
long long result;
string str;
queue<int> q;
unordered_map<int, long long> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int curSize = str.length();
        if (q.size() == k + 1)
        {
            int deletedSize = q.front();
            q.pop();
            um[deletedSize]--;
        }
        q.push(curSize);
        result += um[curSize];
        um[curSize]++;
    }

    cout << result;
    return 0;
}