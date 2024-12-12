#include <iostream>
#include <queue>

using namespace std;

int n, m, temp;
long long result;
priority_queue<long long> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(-temp);
    }

    for (int i = 0; i < m; i++)
    {
        long long a{ -pq.top() }; 
        pq.pop();
        long long b{ -pq.top() };
        pq.pop();
        pq.push(-(a + b));
        pq.push(-(a + b));
    }

    while (!pq.empty())
    {
        result += -pq.top();
        pq.pop();
    }
    cout << result;
    return 0;
}