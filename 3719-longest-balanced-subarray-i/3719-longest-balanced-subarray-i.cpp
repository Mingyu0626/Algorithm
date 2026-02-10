class Solution {
private:
    int n, result;
    vector<int> v; // {numOfEvens, numOfOdds}
    unordered_set<int> us;
public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size(), result = 0;
        v.assign(2, 0);
        for (int i = 0; i < n; ++i) {
            v[0] = 0, v[1] = 0; 
            us.clear();
            for (int j = i; j < n; ++j) {
                int cur = nums[j];
                if (us.find(cur) == us.end()) {
                    us.insert(cur);
                    v[cur % 2]++;
                }
                result = (v[0] == v[1]) ? max(result, j - i + 1) : result;
            }
        }
        return result;
    }
};