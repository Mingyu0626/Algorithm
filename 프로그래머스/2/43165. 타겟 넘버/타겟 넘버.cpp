#include <string>
#include <vector>

using namespace std;

int result = 0, n;

void search(const vector<int>& numbers, const int target, int curIdx, int curSum);

int solution(vector<int> numbers, int target) 
{
    n = numbers.size();
    search(numbers, target, 0, 0);
    return result;
}

void search(const vector<int>& numbers, const int target, int curIdx, int curSum)
{
    if (curIdx == n)
    {
        if (curSum == target)
        {
            result++;
        }
        return;
    }
    search(numbers, target, curIdx + 1, curSum - numbers[curIdx]);
    search(numbers, target, curIdx + 1, curSum + numbers[curIdx]);
}