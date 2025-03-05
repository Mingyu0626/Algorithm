#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template<typename T>
using Dim2Vec = vector<vector<T>>;

int k, v, e;
bool isBipartiteGraph;

void bfs(const Dim2Vec<int>& adj, vector<int>& visited, int& startNode);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k;
    while (k--)
    {
        cin >> v >> e;
        Dim2Vec<int> adj(v + 1);
        vector<int> visited(v + 1, -1);
        isBipartiteGraph = true;


        int start, dist;
        for (int i = 0; i < e; i++)
        {
            cin >> start >> dist;
            adj[start].emplace_back(dist);
            adj[dist].emplace_back(start);
        }

        for (int i = 1; i < visited.size(); i++)
        {
            if (visited[i] == -1)
            {
                bfs(adj, visited, i);
            }
        }

        if (isBipartiteGraph) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

void bfs(const Dim2Vec<int>& adj, vector<int>& visited, int& startNode)
{
    queue<int> q;
    q.push(startNode);
    int level = 0;
    visited[startNode] = level;
    while (!q.empty())
    {
        level++;
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            int curLevel = visited[cur];
            q.pop();

            for (int j = 0; j < adj[cur].size(); j++)
            {
                int next = adj[cur][j];
                if (visited[next] == curLevel)
                {
                    isBipartiteGraph = false;
                    break;
                }
                else if (visited[next] == -1)
                {
                    visited[next] = level % 2;
                    q.push(next);
                }
            }
        }
    }
}