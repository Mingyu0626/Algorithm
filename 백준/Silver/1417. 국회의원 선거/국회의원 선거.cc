#include <iostream>
#include <queue>

using namespace std;

int n, votes, candidate, result;
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> votes;
    for (int i = 1; i < n; i++)
    {
        cin >> candidate;
        pq.push(candidate);
    }

    while (!pq.empty() && votes <= pq.top())
    {
        int curTopVotes = pq.top();
        pq.pop();
        pq.push(curTopVotes - 1);
        votes++, result++;
    }

    cout << result;
    return 0;
}