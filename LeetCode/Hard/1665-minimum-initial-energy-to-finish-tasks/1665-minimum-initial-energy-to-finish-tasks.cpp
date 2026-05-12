class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[1] - a[0] < b[1] - b[0]; 
        });

        int result = tasks[0][1];
        for (int i = 1; i < tasks.size(); ++i) {
            result = max(result + tasks[i][0], tasks[i][1]);
        }
        return result;
    }
};