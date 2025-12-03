#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    stack<int> s;
    int n = order.size(), result = 0, mainBoxCount = 1;

    for (int i = 0; i < n; ++i) {
        int target = order[i];
        
        if (target < mainBoxCount && !s.empty() && s.top() == target) {
            result++, s.pop();
        }
        else if (mainBoxCount <= target) {
            while (mainBoxCount < target) {
                s.push(mainBoxCount++);
            }
            result++, mainBoxCount++;
        }
        else break;
    }
    return result;
}