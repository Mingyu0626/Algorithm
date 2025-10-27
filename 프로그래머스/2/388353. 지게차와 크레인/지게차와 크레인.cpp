#include <string>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<string> v;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void forkLift(char target);
void crane(char target);

int solution(vector<string> s, vector<string> requests) 
{
    n = s.size(), m = s[0].size(), v = s;
    for (int i = 0; i < requests.size(); ++i)
    {
        if (requests[i].length() == 1)
        {
            forkLift(requests[i][0]);
        }
        else
        {
            crane(requests[i][0]);
        }
    }
    
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result += (v[i][j] != '0') ? 1 : 0;
        }
    }
    return result;
}

void forkLift(char target)
{
    queue<pii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((i == 0 || i == n - 1) || (j == 0 || j == m - 1))
            {
                if (v[i][j] == target)
                {
                    v[i][j] = '0';
                }
                else if (v[i][j] == '0')
                {
                    q.push({i, j});
                }
                visited[i][j] = true;
            }
        }
    }
    
    while (!q.empty())
    {
        int curX = q.front().first, curY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (0 <= newX && newX < n && 0 <= newY && newY < m && !visited[newX][newY])
            {
                if (v[newX][newY] == '0')
                {
                    q.push({newX, newY});
                }
                else if (v[newX][newY] == target)
                {
                    v[newX][newY] = '0';
                }
                visited[newX][newY] = true;
            }
        }
    }
}

void crane(char target)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] == target)
            {
                v[i][j] = '0';
            }
        }
    }
}
