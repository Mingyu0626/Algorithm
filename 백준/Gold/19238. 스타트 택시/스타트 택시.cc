#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

Dim2Vec<int> v;
unordered_map<int, pair<int, int>> um;

int n, m, fuel, startR, startC, endR, endC;
pair<int, int> curTaxi;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

vector<pair<int, int>> FindNearestCustomer();
void GoToDestination(const pair<int, int>& start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> fuel;
    v.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }

    cin >> curTaxi.first >> curTaxi.second;
    for (int i = 0; i < m; i++)
    {
        cin >> startR >> startC >> endR >> endC;
        um.insert({ startR * 100000 + startC, {endR, endC} });
        v[startR][startC] = 2;
    }
    for (int i = 0; i < m; i++)
    {
        vector<pair<int, int>> nearestCustomers = FindNearestCustomer();
        if (nearestCustomers.size() == 0)
        {
            cout << -1;
            exit(0);
        }
        sort(nearestCustomers.begin(), nearestCustomers.end());
        GoToDestination(nearestCustomers[0]);
    }
    cout << fuel;
    return 0;
}

vector<pair<int, int>> FindNearestCustomer()
{
    Dim2Vec<bool> visited(n + 1, vector<bool>(n + 1, false));
    queue<pair<int, int>> q;
    q.push(curTaxi);
    visited[curTaxi.first][curTaxi.second] = true;
    vector<pair<int, int>> nearestCustomers;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();

            if (fuel == 0)
            {
                return nearestCustomers;
            }
            if (v[curR][curC] == 2)
            {
                nearestCustomers.emplace_back(curR, curC);
            }

            for (int j = 0; j < 4; j++)
            {
                int newR = curR + dr[j];
                int newC = curC + dc[j];
                if (0 < newR && newR <= n && 0 < newC && newC <= n
                    && v[newR][newC] != 1 && visited[newR][newC] == false)
                {
                    q.push({ newR, newC });
                    visited[newR][newC] = true;
                }
            }
        }
        if (0 < nearestCustomers.size())
        {
            return nearestCustomers;
        }
        fuel--;
    }
    return nearestCustomers;
}

void GoToDestination(const pair<int, int>& start)
{
    Dim2Vec<bool> visited(n + 1, vector<bool>(n + 1, false));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    pair<int, int> destination = um[start.first * 100000 + start.second];
    int neededFuel = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();

            if (fuel < neededFuel)
            {
                cout << -1;
                exit(0);
            }

            if (make_pair(curR, curC) == destination)
            {
                v[start.first][start.second] = 0;
                curTaxi = make_pair(curR, curC);
                fuel += neededFuel;
                return;
            }

            for (int j = 0; j < 4; j++)
            {
                int newR = curR + dr[j];
                int newC = curC + dc[j];
                if (0 < newR && newR <= n && 0 < newC && newC <= n
                    && v[newR][newC] != 1 && visited[newR][newC] == false)
                {
                    q.push({ newR, newC });
                    visited[newR][newC] = true;
                }
            }
        }
        neededFuel++;
    }
    cout << -1;
    exit(0);
}