#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int l = 1, r = 100000, result = r;
    while (l <= r) {
        int m = (r - l) / 2 + l;
        long long timeSum = 0;
        timeSum += (diffs[0] <= m) ? times[0] : times[0] * (diffs[0] - m + 1);
        for (int i = 1; i < times.size(); ++i) {
            timeSum += (diffs[i] <= m) ? times[i] : (times[i] + times[i - 1]) * (diffs[i] - m) + times[i];
        }

        if (limit < timeSum) {
            l = m + 1;
        } 
        else {
            result = m;
            r = m - 1;
        }
    }
    return result;
}