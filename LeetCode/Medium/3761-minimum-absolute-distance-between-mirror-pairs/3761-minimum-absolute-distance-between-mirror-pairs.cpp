class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), result = n;
        unordered_map<int, int> um;
        for (int i = n - 1; 0 <= i; --i) {
            int origin = nums[i];
            while (origin % 10 == 0) {
                origin /= 10;
            }
            if (um.find(origin) != um.end()) {
                result = min(result, um[origin] - i);
            }     

            if (nums[i] % 10 != 0) {
                string s = to_string(origin);
                reverse(s.begin(), s.end());
                um[stoi(s)] = i;
            }
        }
        return result == n ? -1 : result;
    }
};