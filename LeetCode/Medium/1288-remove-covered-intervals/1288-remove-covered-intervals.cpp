class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int curL = intervals[0][0], curR = intervals[0][1], removed = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][1] <= curR) {
                removed++;
            }
            curL = intervals[i][0], curR = max(curR, intervals[i][1]);
        }
        return intervals.size() - removed;
    }
};