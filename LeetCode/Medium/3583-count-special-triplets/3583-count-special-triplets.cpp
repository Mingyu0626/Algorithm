class Solution {
public:
    const long long modulo = 1e9 + 7;
    long long specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> l, r;
        for (int i = 0; i < n; ++i) {
            l[nums[i]]++;
        }

        long long result = 0;
        for (int j = n - 1; 0 <= j; --j) {
            int cur = nums[j], target = nums[j] * 2;
            l[cur]--;
            long long leftCount = l[target], rightCount = r[target];
            result += (leftCount * rightCount) % modulo;
            result %= modulo;
            r[cur]++;
        }
        return result;
    }
};