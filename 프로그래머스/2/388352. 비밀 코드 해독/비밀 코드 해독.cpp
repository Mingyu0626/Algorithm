#include <vector>
#include <unordered_set>

using namespace std;

int m, n;
vector<unordered_set<int>> q;
vector<int> ans;

void initHashSet(const vector<vector<int>>& Q);
void makeCombination(vector<int>& cur, int& result, int maxNum);
bool validation(const vector<int>& cur);

int solution(int N, vector<vector<int>> Q, vector<int> Ans) {
    m = Q.size(), n = N, ans = Ans;
    initHashSet(Q);
    int result = 0;
    vector<int> cur;
    makeCombination(cur, result, 0);
    return result;
}

void initHashSet(const vector<vector<int>>& Q) {
    unordered_set<int> us;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 5; ++j) {
            us.insert(Q[i][j]);
        }
        q.push_back(us);
        us.clear();
    }
}

void makeCombination(vector<int>& cur, int& result, int maxNum) {
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
    for (int i = 0; i < m; ++i) {
        int sameNum = 0;
        for (int j = 0; j < 5; ++j) {
            sameNum += (q[i].find(cur[j]) != q[i].end()) ? 1 : 0;
        }
        if (sameNum != ans[i]) {
            return false;
        }
    }
    return true;
}
