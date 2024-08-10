// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector<vector<int>> v;
vector<bool> visited;
vector<int> result;
queue<int> q;

void bfs(int a);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> x;

    v.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
    }

    bfs(x);

    if (result.size() == 0) 
        cout << -1;

    else {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) 
            cout << result[i] << "\n";
    }

    return 0;
}

void bfs(int a) {
    q.push(x);
    visited[x] = true;
    int distance = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)  {
            int cityNum = q.front();
            q.pop();
            if (distance == k)  result.push_back(cityNum);
            
            for (int j = 0; j < v[cityNum].size(); j++) {
                int connectedCity = v[cityNum][j];
                if (!visited[connectedCity]) {
                    q.push(connectedCity);
                    visited[connectedCity] = true;
                }
            }
        }
        distance++;
    }
    return;
}