#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class BabyShark
{
public:
    int getSize() { return size; }
    int getXPos() { return xPos; }
    int getYPos() { return yPos; }

    void increaseNumOfEatenFish() { numOfEatenFish++; }
    void setXPos(const int& val) { xPos = val; }
    void setYPos(const int& val) { yPos = val; }

    void trySizeUp()
    {
        if (size == numOfEatenFish)
        {
            size++;
            numOfEatenFish = 0;
        }
    }

private:
    int size = 2;
    int numOfEatenFish = 0;
    int xPos = 0;
    int yPos = 0;
};

class GameManager
{
public:
    void init()
    {
        cin >> n;
        map.assign(n, vector<int>(n));
        fishCounter.assign(7, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 9)
                {
                    bs.setXPos(i);
                    bs.setYPos(j);
                }
                else if (map[i][j] != 0)
                {
                    fishCounter[map[i][j]]++;
                }
            }
        }
    }

    void play()
    {
        while (checkCanContinue())
        {
            visited.assign(n, vector<bool>(n, false));
            if (!bfs(bs.getXPos(), bs.getYPos()))
            {
                break;
            }
        }
        cout << currentTime;
    }

    bool checkCanContinue()
    {
        int startIdx = bs.getSize() <= 7 ? bs.getSize() - 1 : 6;
        for (int i = startIdx; i >= 1; i--)
        {
            if (0 < fishCounter[i])
            {
                return true;
            }
        }
        return false;
    }

    bool bfs(const int& startX, const int& startY)
    {
        queue<pair<int, int>> q;
        q.push({ startX, startY });
        visited[startX][startY] = true;
        vector<pair<int, int>> eatableFishPos;

        int t = currentTime;

        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                int curX = q.front().first;
                int curY = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int newX = curX + dx[j];
                    int newY = curY + dy[j];
                    if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;
                    if (!visited[newX][newY] && map[newX][newY] <= bs.getSize())
                    {
                        visited[newX][newY] = true;
                        if (map[newX][newY] != 0 && map[newX][newY] < bs.getSize())
                        {
                            eatableFishPos.emplace_back(newX, newY);
                        }
                        else
                        {
                            q.push({ newX, newY });
                        }
                    }
                }
            }
            if (eatableFishPos.size() != 0)
            {
                sort(eatableFishPos.begin(), eatableFishPos.end(),
                    [](const pair<int, int>& a, const pair<int, int>& b)
                    {
                        if (a.first == b.first) return a.second < b.second;
                        else return a.first < b.first;
                    });
                eatFishAndUpdateMap(eatableFishPos[0].first, eatableFishPos[0].second);
                currentTime = t + 1;
                return true;
            }
            t++;
        }
        return false;
    }

    void eatFishAndUpdateMap(const int& x, const int& y)
    {
        fishCounter[map[x][y]]--;
        map[bs.getXPos()][bs.getYPos()] = 0;
        map[x][y] = 9;
        bs.setXPos(x);
        bs.setYPos(y);
        bs.increaseNumOfEatenFish();
        bs.trySizeUp();
    }

private:
    vector<vector<int>> map;
    vector<vector<bool>> visited;
    vector<int> fishCounter;
    BabyShark bs;
    int n = 0, currentTime = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    GameManager gm;
    gm.init();
    gm.play();
    return 0;
}