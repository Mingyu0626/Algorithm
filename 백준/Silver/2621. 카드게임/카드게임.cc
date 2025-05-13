#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct cardInfo
{
    char color;
    int num;
};

bool compareCardInfo(const cardInfo& a, const cardInfo& b)
{
    if (a.num == b.num)
    {
        return a.color < b.color;
    }
    return a.num < b.num;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}

vector<cardInfo> cards(5);
unordered_map<char, pair<int, int>> umColor;
unordered_map<int, int> umNumber;
bool isStraight = true;
int biggestNum = 0;

int calculateScore();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++)
    {
        cin >> cards[i].color >> cards[i].num;
    }
    sort(cards.begin(), cards.end(), compareCardInfo);

    int prevNum = 0;
    for (int i = 0; i < 5; i++)
    {
        char curColor = cards[i].color;
        int curNum = cards[i].num;
        biggestNum = max(biggestNum, curNum);

        if (umColor.find(curColor) == umColor.end())
        {
            umColor.insert({ curColor, {1, curNum} });
        }
        else
        {
            umColor[curColor].first++;
            umColor[curColor].second = max(curNum, umColor[curColor].second);
        }
        umNumber[curNum]++;
        if (prevNum + 1 == curNum || prevNum == 0)
        {
            prevNum = curNum;
        }
        else
        {
            isStraight = false;
        }
    }
    cout << calculateScore();
}

int calculateScore()
{
    int score = 0;
    if (umColor.size() == 1) // 900 & 600
    {
        if (isStraight)
        {
            score += 900;
        }
        else
        {
            score += 600;
        }
        for (auto a : umColor)
        {
            return score + a.second.second;
        }
    }
    if (umNumber.size() == 2) // 800 & 700
    {
        vector<pair<int, int>> v;
        for (auto& a : umNumber)
        {
            v.emplace_back(a);
        }
        sort(v.begin(), v.end(), compare);
        if (v[0].second == 4)
        {
            score += 800 + v[0].first;
        }
        else
        {
            score += 700;
            score += v[0].first * 10 + v[1].first;
        }
        return score;
    }
    if (isStraight) // 500
    {
        score += 500 + biggestNum;
        return score;
    }
    if (umNumber.size() == 3) // 400, 300
    {
        vector<pair<int, int>> v;
        for (auto& a : umNumber)
        {
            v.emplace_back(a);
        }
        sort(v.begin(), v.end(), compare);
        if (v[0].second == 3)
        {
            score += 400 + v[0].first;
        }
        else
        {
            score += 300;
            score += v[0].first * 10 + v[1].first;
        }
        return score;
    }
    if (umNumber.size() == 4) // 200
    {
        int num = 0;
        for (auto& a : umNumber)
        {
            if (a.second == 2)
            {
                num = a.first;
            }
        }
        score += 200 + num;
        return score;
    }
    // 100
    score += 100 + biggestNum;
    return score;
}