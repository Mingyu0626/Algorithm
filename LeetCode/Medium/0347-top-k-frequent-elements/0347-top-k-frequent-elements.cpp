class Solution {
using pii = pair<int, int>;
private:
    int n;
    unordered_map<int, int> um;
    vector<pii> v;
    vector<int> result;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        n = nums.size();
        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
        }
        for (const auto& a : um) {
            v.emplace_back(a.second, a.first);
        }
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < k; ++i) {
            result.emplace_back(v[i].second);
        }
        return result;
    }
};