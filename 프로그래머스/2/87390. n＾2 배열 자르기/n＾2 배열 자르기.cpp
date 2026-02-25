#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> result(right - left + 1, 0);
    for (int i = 0; i < result.size(); ++i) {
        int r = (left + i) / n, c = (left + i) % n;
        result[i] = (max(r , c) + 1);
    }
    return result;
}