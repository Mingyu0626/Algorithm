#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m;
vector<int> indegree, result;
Dim2Vec<int> edges;
queue<int> q;

void getInput();
void topologySort();
void initQueue();
void printResult();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getInput();
    topologySort();
    printResult();
    return 0;
}

void getInput()
{
    cin >> n >> m;
    indegree.assign(n + 1, 0), edges.assign(n + 1, vector<int>());
    int numOfSingers;
    for (int i = 0; i < m; ++i)
    {
        cin >> numOfSingers;
        int s = 0, e = 0;
        for (int j = 0; j < numOfSingers; ++j)
        {
            s = e;
            cin >> e;
            if (j == 0)
            {
                continue;
            }
            edges[s].emplace_back(e);
            indegree[e]++;
        }
    }
}

void topologySort()
{
    initQueue();

    while (!q.empty())
    {
        int curSinger = q.front();
        result.emplace_back(curSinger);
        q.pop();

        for (int i = 0; i < edges[curSinger].size(); ++i)
        {
            int nextSinger = edges[curSinger][i];
            if (--indegree[nextSinger] == 0)
            {
                q.push(nextSinger);
            }
        }
    }
}

void initQueue()
{
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
}

void printResult()
{
    if (result.size() < n)
    {
        cout << 0;
    }
    else
    {
        for (const auto& a : result)
        {
            cout << a << '\n';
        }
    }
}