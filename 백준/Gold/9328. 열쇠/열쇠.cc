#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int t, h, w, result;
Dim2Vec<char> v;
unordered_set<char> us;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void pushEdge(queue<pii>& q, Dim2Vec<bool>& visited);
bool tryBFS(bool stealDocument);
bool isValid(const int& x, const int& y);
bool tryGetKey(const char& key);
bool tryOpenDoor(const char& door);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (0 < t--)
    {
        result = 0;
        us.clear();
        cin >> h >> w;
        v.assign(h, vector<char>(w));
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> v[i][j];
            }
        }

        string keyStr;
        cin >> keyStr;
        if (keyStr != "0")
        {
            for (int i = 0; i < keyStr.length(); ++i)
            {
                us.insert(keyStr[i]);
            }
        }

        while (tryBFS(false)) {}

        tryBFS(true);
        cout << result << '\n';
    }
    return 0;
}

void pushEdge(queue<pii>& q, Dim2Vec<bool>& visited)
{
    for (int i = 0; i < h; ++i)
    {
        char target1 = v[i][0];
        if (!visited[i][0])
        {
            if ((target1 == '.' || target1 == '$'))
            {
                q.push({ i, 0 });
                visited[i][0] = true;
            }
            else if ('a' <= target1 && target1 <= 'z')
            {
                q.push({ i, 0 });
                visited[i][0] = true;
                tryGetKey(target1);
            }
            else if ('A' <= target1 && target1 <= 'Z' && tryOpenDoor(target1))
            {
                q.push({ i, 0 });
                visited[i][0] = true;
            }
        }

        char target2 = v[i][w - 1];
        if (!visited[i][w - 1])
        {
            if ((target2 == '.' || target2 == '$'))
            {
                q.push({ i, w - 1 });
                visited[i][w - 1] = true;
            }
            else if ('a' <= target2 && target2 <= 'z')
            {
                q.push({ i, w - 1 });
                visited[i][w - 1] = true;
                tryGetKey(target2);
            }
            else if ('A' <= target2 && target2 <= 'Z' && tryOpenDoor(target2))
            {
                q.push({ i, w - 1 });
                visited[i][w - 1] = true;
            }
        }
    }

    for (int i = 0; i < w; ++i)
    {
        char target1 = v[0][i];
        if (!visited[0][i])
        {
            if ((target1 == '.' || target1 == '$'))
            {
                q.push({ 0, i });
                visited[0][i] = true;
            }
            else if ('a' <= target1 && target1 <= 'z')
            {
                q.push({ 0, i });
                visited[0][i] = true;
                tryGetKey(target1);
            }
            else if ('A' <= target1 && target1 <= 'Z' && tryOpenDoor(target1))
            {
                q.push({ 0, i });
                visited[0][i] = true;
            }
        }

        char target2 = v[h - 1][i];
        if (!visited[h - 1][i])
        {
            if ((target2 == '.' || target2 == '$'))
            {
                q.push({ h - 1, i });
                visited[h - 1][i] = true;
            }
            else if ('a' <= target2 && target2 <= 'z')
            {
                q.push({ h - 1, i });
                visited[h - 1][i] = true;
                tryGetKey(target2);
            }
            else if ('A' <= target2 && target2 <= 'Z' && tryOpenDoor(target2))
            {
                q.push({ h - 1, i });
                visited[h - 1][i] = true;
            }
        }
    }
}

bool tryBFS(bool stealDocument)
{
    Dim2Vec<bool> visited(h, vector<bool>(w, false));
    queue<pii> q;
    pushEdge(q, visited);
    bool findNewKey = false;
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        if (v[curX][curY] == '$' && stealDocument)
        {
            result++;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (!isValid(newX, newY) || visited[newX][newY])
            {
                continue;
            }

            char nextGrid = v[newX][newY];
            if (nextGrid == '.' || nextGrid == '$')
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }

            if ('a' <= nextGrid && nextGrid <= 'z')
            {
                if (tryGetKey(nextGrid))
                {
                    findNewKey = true;
                }
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }

            if ('A' <= nextGrid && nextGrid <= 'Z')
            {
                if (tryOpenDoor(nextGrid))
                {
                    q.push({ newX, newY });
                    visited[newX][newY] = true;
                }
            }
            
        }
    }
    return findNewKey;
}

bool isValid(const int& x, const int& y)
{
    return 0 <= x && x < h && 0 <= y && y < w;
}

bool tryGetKey(const char& key)
{
    if (us.find(key) == us.end())
    {
        us.insert(key);
        return true;
    }
    return false;
}

bool tryOpenDoor(const char& door)
{
    return us.find(door + 32) != us.end();
}