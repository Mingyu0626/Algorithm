#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    vector<pair<int, int>> v;
    int n = dungeons.size();
    for (int i = 0; i < n; ++i)
    {
        v.emplace_back(dungeons[i][0], dungeons[i][1]);
    }
    
    sort(v.begin(), v.end());
    int result = 0;
    do
    {
        int curK = k, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i].first <= curK)
            {
                curK -= v[i].second;
                cnt++;
            }
            else
            {
                break;
            }
        }
        result = max(result, cnt);   
    } while (next_permutation(v.begin(), v.end()));
    
    return result;
}