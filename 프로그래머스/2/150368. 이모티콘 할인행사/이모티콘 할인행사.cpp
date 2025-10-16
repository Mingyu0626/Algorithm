#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;

pii recursion(const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& discount);
pii calculate(const vector<vector<int>>& users, const vector<int>& emoticons, const vector<int>& discount);

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    n = users.size(), m = emoticons.size();
    
    vector<int> discount;
    pii result = recursion(users, emoticons, discount);

    vector<int> answer(2, 0);
    answer[0] = result.first, answer[1] = result.second; 
    return answer;
}

pii recursion(const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& discount)
{
    if (discount.size() == m)
    {
        return calculate(users, emoticons, discount);
    }
    
    pii result = {0, 0};
    for (int i = 1; i <= 4; ++i)
    {
        discount.emplace_back(i * 10);
        pii curResult = recursion(users, emoticons, discount);
        if ((result.first < curResult.first) || 
            (result.first == curResult.first && result.second < curResult.second))
        {
            result = curResult;
        }
        discount.pop_back();
    }
    return result;
}

pii calculate(const vector<vector<int>>& users, const vector<int>& emoticons, const vector<int>& discount)
{
    int member = 0, profit = 0;
    for (int i = 0; i < n; ++i)
    {
        int userDiscount = users[i][0], limit = users[i][1];
        int current = 0;
        for (int j = 0; j < m; ++j)
        {
            if (userDiscount <= discount[j])
            {
                current += (emoticons[j] / 100 * (100 - discount[j]));
                if (limit <= current)
                {
                    member++, current = 0;
                    j = m;
                }
            }
        }
        profit += current;
    }
    return {member, profit};
}

