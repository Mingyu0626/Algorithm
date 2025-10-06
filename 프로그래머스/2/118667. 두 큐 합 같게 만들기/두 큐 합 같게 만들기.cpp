#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q1, q2;
long long sum1, sum2;

int solution(vector<int> queue1, vector<int> queue2) 
{
    for (int i = 0; i < queue1.size(); ++i)
    {
        q1.push(queue1[i]);
        sum1 += queue1[i];
    }
    
    for (int i = 0; i < queue2.size(); ++i)
    {
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    int result = 0;
    while (sum1 != sum2)
    {
        if ((queue1.size() + queue2.size()) * 2 < result)
        {
            return -1;
        }
        int cur;
        if (sum1 < sum2)
        {
            cur = q2.front();
            q2.pop();
            sum2 -= cur;
            q1.push(cur);
            sum1 += cur;
        }
        else
        {
            cur = q1.front();
            q1.pop();
            sum1 -= cur;
            q2.push(cur);
            sum2 += cur;
        }
        result++;
    }
    
    return result;
}