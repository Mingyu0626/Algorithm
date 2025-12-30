#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> q;
vector<int> ans;
int m, n;

void makeCombination(vector<int> cur, int& result, int maxNum);
bool validation(const vector<int>& cur);


int solution(int N, vector<vector<int>> Q, vector<int> Ans) {
    q = Q, ans = Ans, m = q.size(), n = N;
    int result = 0;
    makeCombination(vector<int>(), result, 0);
    return result;
}

void makeCombination(vector<int> cur, int& result, int maxNum) {
    if (cur.size() == 5) {
        result += (validation(cur)) ? 1 : 0;
        return;
    }
    for (int i = maxNum + 1; i <= n; ++i) {
        cur.emplace_back(i);
        makeCombination(cur, result, i);
        cur.pop_back();
    }
}

bool validation(const vector<int>& cur) {
    unordered_set<int> us;
    for (const auto& num : cur) {
        us.insert(num);
    }
    
    for (int i = 0; i < m; ++i) {
        int sameNum = 0;
        for (int j = 0; j < 5; ++j) {
            sameNum += (us.find(q[i][j]) != us.end()) ? 1 : 0;
        }
        if (sameNum != ans[i]) {
            return false;
        }
    }
    return true;
}