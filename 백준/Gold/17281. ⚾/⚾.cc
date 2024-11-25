#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct BaseInformation
{
    int first = 0;
    int second = 0;
    int third = 0;
};

class BaseBallManager
{
public:
    int makeLineup(const vector<vector<int>>& atBatInfo)
    {
        int result = 0;
        do
        {
            int idx = 0;
            for (int i = 1; i <= 9; i++)
            {
                if (i == 4) continue;
                lineup[i] = permu[idx];
                idx++;
            }
            result = max(result, playBall(atBatInfo));
        } while (next_permutation(permu.begin(), permu.end()));
        return result;
    }

    int playBall(const vector<vector<int>>& atBatInfo)
    {
        int score = 0, curBatter = 1;
        for (int i = 1; i <= n; i++) // i회 공격
        {
            int outCount = 0;
            initBase();
            while (outCount < 3)
            {
                int curPlayer = lineup[curBatter];
                int atBatResult = atBatInfo[curPlayer][i];
                if (atBatResult == 0)
                {
                    outCount++;
                }
                else
                {
                    score += checkHomeIn(atBatResult);
                }
                curBatter = (curBatter == 9) ? 1 : curBatter + 1;
            }
        }
        return score;
    }

    int checkHomeIn(int baseHit)
    {
        int scorableRunner = 0;
        if (baseHit == 1)
        {
            scorableRunner = baseInfo.third;
            baseInfo.third = (baseInfo.second == 1) ? 1 : 0;
            baseInfo.second = (baseInfo.first == 1) ? 1 : 0;
            baseInfo.first = 1;
        }
        else if (baseHit == 2)
        {
            scorableRunner = baseInfo.second + baseInfo.third;
            baseInfo.third = (baseInfo.first == 1) ? 1 : 0;
            baseInfo.first = 0, baseInfo.second = 1;
        }
        else if (baseHit == 3)
        {
            scorableRunner = baseInfo.first + baseInfo.second + baseInfo.third;
            baseInfo.first = baseInfo.second = 0, baseInfo.third = 1;
        }
        else
        {
            scorableRunner = baseInfo.first + baseInfo.second + baseInfo.third + 1;
            initBase();
        }
        return scorableRunner;
    }

    void initBase()
    {
        baseInfo.first = baseInfo.second = baseInfo.third = 0;
    }

private:
    int lineup[10] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };
    vector<int> permu = { 2, 3, 4, 5, 6, 7, 8, 9 };
    BaseInformation baseInfo;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    BaseBallManager bm;
    vector<vector<int>> atBat(10, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> atBat[j][i];
        }
    }
    cout << bm.makeLineup(atBat);
    return 0;
}