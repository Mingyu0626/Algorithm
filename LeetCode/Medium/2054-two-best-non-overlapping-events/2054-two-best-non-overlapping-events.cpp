class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(), result = 0;
        vector<pair<int, int>> dp(n, {0, 0});
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        
        dp[0] = {events[0][1], events[0][2]};
        for (int i = 1; i < n; ++i) {
            dp[i] = {events[i][1], max(dp[i - 1].second, events[i][2])};
        }

        for (int i = 0; i < n; ++i) {
            int s = events[i][0], v = events[i][2];
            result = max(result, v);

            auto it = lower_bound(dp.begin(), dp.end(), make_pair(s, 0), 
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            });

            if (it != dp.begin()) {
                --it;
                result = max(result, v + it->second);
            }
        }
        return result;
    }
};