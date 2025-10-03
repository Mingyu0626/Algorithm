#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, q, w, l;
Dim2Vec<int> v, temp;

pii dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void DivideGrid(const int& l);

void RotateGrid(int startX, int startY, const int& powL);

void DecreaseIce();

int BFS(const int& startX, const int& startY, bool isDecrease, Dim2Vec<int>& visited);

int GetSumOfIces();

int GetBiggestChunkSize();

void Print();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    w = pow(2, n);
    v.assign(w, vector<int>(w)), temp.assign(w, vector<int>(w));
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> l;
        DivideGrid(pow(2, l));
        DecreaseIce();
    }

    cout << GetSumOfIces() << '\n';
    cout << GetBiggestChunkSize() << '\n';
    return 0;
}

void DivideGrid(const int& powL)
{
    for (int i = 0; i < w; i += powL)
    {
        for (int j = 0; j < w; j += powL)
        {
            RotateGrid(i, j, powL);
        }
    }
}

void RotateGrid(int startY, int startX, const int& powL)
{
    for (int i = 0; i < powL; ++i)
    {
        for (int j = 0; j < powL; ++j)
        {
            temp[j][powL - i - 1] = v[startY + i][startX + j];
        }
    }

    for (int i = 0; i < powL; ++i)
    {
        for (int j = 0; j < powL; ++j)
        {
            v[startY + i][startX + j] = temp[i][j];
        }
    }
}

void DecreaseIce()
{
    Dim2Vec<int> visited(w, vector<int>(w, 0));
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (!visited[i][j])
            {
                BFS(i, j, true, visited);
            }
        }
    }

    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (visited[i][j] == -1)
            {
                v[i][j] -= 1;
            }
        }
    }
}

int BFS(const int& startX, const int& startY, bool isDecrease, Dim2Vec<int>& visited)
{
    visited[startX][startY] = 1;
    queue<pii> q;
    q.push({ startX, startY });
    int chunkSize = 0;
    while (!q.empty())
    {
        int curX = q.front().first, curY = q.front().second;
        chunkSize++;
        q.pop();

        int adjCnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + dir[i].first, newY = curY + dir[i].second;
            if (newX < 0 || w <= newX || newY < 0 || w <= newY)
            {
                continue;
            }
            if (visited[newX][newY] == 0 && 0 < v[newX][newY])
            {
                q.push({ newX, newY });
                visited[newX][newY] = 1;
            }
            if (0 < v[newX][newY])
            {
                adjCnt++;
            }
        }
        
        if (isDecrease && adjCnt < 3 && 0 < v[curX][curY])
        {
            visited[curX][curY] = -1;
        }
    }
    return chunkSize;
}

int GetSumOfIces()
{
    int sum = 0;
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            sum += v[i][j];
        }
    }
    return sum;
}

int GetBiggestChunkSize()
{
    Dim2Vec<int> visited(w, vector<int>(w, 0));
    int biggestChunkSize = 0;
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (!visited[i][j] && v[i][j])
            {
                biggestChunkSize = max(biggestChunkSize, BFS(i, j, false, visited));
            }
        }
    }
    return biggestChunkSize;
}

void Print()
{
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}