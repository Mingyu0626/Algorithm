#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

int m, k;
unordered_map<int, map<pii, int>> um;

int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    m = routes.size(), k = routes[0].size();
    
    for (int i = 0; i < m; ++i)
    {
        int routeIdx = routes[i][0] - 1;
        int curR = points[routeIdx][0], curC = points[routeIdx][1], curTime = 0;
        um[curTime][{curR, curC}]++;
        for (int j = 1; j < routes[i].size(); ++j)
        {
            int routeIdx = routes[i][j] - 1;
            int nextR = points[routeIdx][0], nextC = points[routeIdx][1];
            while (!((curR == nextR) && (curC == nextC)))
            {
                curTime++;
                if (curR != nextR)
                {
                    curR += (curR < nextR) ? 1 : -1;
                }
                else if (curC != nextC)
                {
                    curC += (curC < nextC) ? 1 : -1;
                }
                um[curTime][{curR, curC}]++;
            }
        }
    }
    
    int numOfCollisions = 0;
    for (const auto& a : um)
    {
        for (const auto& b : a.second)
        {
            if (1 < b.second)
            {
                numOfCollisions++;
            }
        }
    }
    return numOfCollisions;
}