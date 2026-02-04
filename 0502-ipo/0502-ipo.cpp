class Solution {
public:
    using pii = pair<int, int>;

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pii> v;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(capital[i], profits[i]);
        }
        sort(v.begin(), v.end());
        
        int idx = 0;
        priority_queue<int> pq;
        while (idx < n && v[idx].first <= w) {
            pq.push(v[idx].second);
            idx++;
        }
        
        while (0 < k-- && !pq.empty()) {
            w += pq.top();
            pq.pop();
            while (idx < n && v[idx].first <= w) {
                pq.push(v[idx].second);
                idx++;
            }
        }
        return w;
    }
};