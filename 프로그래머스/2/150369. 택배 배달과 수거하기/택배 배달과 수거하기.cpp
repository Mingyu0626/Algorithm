#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int cap, int n, vector<int> d, vector<int> p) 
{
    long long result = 0;
    int curD = 0, curP = 0;
    for (int i = n - 1; 0 <= i; --i)
    {
        curD += d[i], curP += p[i];
        int numOfRound = 0;
        while (0 < curD || 0 < curP)
        {
            curD -= cap, curP -= cap;
            numOfRound++;
        }
        result += numOfRound * 2 * (i + 1);
    }
    return result;
}