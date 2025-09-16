#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> um;

int solution(vector<int> nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        um[nums[i]]++;
    }
    return min(nums.size() / 2, um.size());
}