#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

vector<unordered_map<string, int>> v(11);


void makeMenu(const string& order, string cur, int num, int idx)
{
    if (cur.length() == num)
    {
        sort(cur.begin(), cur.end());
        v[cur.length()][cur]++;
        return;
    }
    if (cur.length() < num)
    {
        for (int i = idx + 1; i < order.length(); ++i)
        {
            makeMenu(order, cur + order[i], num, i);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    string str = "";
    for (int i = 0; i < orders.size(); ++i)
    {
        for (int j = 0; j < course.size(); ++j)
        {
            makeMenu(orders[i], str, course[j], -1);
        }
    }
    
    
    vector<string> result;
    for (int i = 0; i < course.size(); ++i)
    {
        vector<string> maxCourse;
        int maxNum = 0;
        for (const auto& a : v[course[i]])
        {
            if (maxNum <= a.second)
            {
                if (maxNum < a.second)
                {
                    maxCourse.clear();
                    maxNum = a.second;
                }
                maxCourse.emplace_back(a.first);
            }
        }
        if (2 <= maxNum)
        {
            for (const auto& s : maxCourse)
            {
                result.emplace_back(s);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}