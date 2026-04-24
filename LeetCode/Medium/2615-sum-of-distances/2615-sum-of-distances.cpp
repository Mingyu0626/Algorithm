class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < n; ++i) {
            um[nums[i]].emplace_back(i);
        }

        vector<long long> result(n, 0);
        for (const auto& a : um) {
            int s = a.second.size();
            int prevIdxLeft = 0, prevIdxRight = 0;
            long long pSumLeft = 0, pSumRight = 0;
            for (int i = 0; i < s; ++i) {
                int curIdxLeft = a.second[i];
                pSumLeft += (i != 0) ? (curIdxLeft - prevIdxLeft) * i : 0;
                result[curIdxLeft] += pSumLeft;
                prevIdxLeft = curIdxLeft;

                int curIdxRight = a.second[s - i - 1];
                pSumRight += (i != 0) ? (prevIdxRight - curIdxRight) * i : 0;
                result[curIdxRight] += pSumRight;
                prevIdxRight = curIdxRight;
            }
        }
        return result;
    }
};