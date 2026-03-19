class Solution {
private:
    vector<int> v;
    int tasksSize, maxCnt;

public:
    int leastInterval(vector<char>& tasks, int n) {
        v.assign(26, 0);
        tasksSize = tasks.size();
        for (int i = 0; i < tasksSize; ++i) {
            v[tasks[i] - 'A']++;
            maxCnt = max(maxCnt, v[tasks[i] - 'A']);
        }

        // 총 K회의 사이클을 돌았을 때, K - 1회의 사이클
        int cycle = n + 1;
        int result = (maxCnt - 1) * cycle;

        // 마지막 K번째 사이클
        for (int i = 0; i < v.size(); ++i) {
            result += (v[i] == maxCnt) ? 1 : 0;
        }
        return max(result, tasksSize);
    }
};