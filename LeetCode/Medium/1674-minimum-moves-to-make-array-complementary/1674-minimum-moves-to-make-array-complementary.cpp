class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(limit * 2 + 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - 1 - i];
            if (b < a) {
                swap(a, b);
            }
            diff[2] += 2;
            diff[a + 1] -= 2;

            diff[a + 1] += 1;
            diff[a + b] -= 1;

            diff[a + b + 1] += 1;
            diff[b + limit + 1] -= 1;

            diff[b + limit + 1] += 2;
        }

        int result = n, minMove = 0;
        for (int i = 2; i <= limit * 2; ++i) {
            minMove += diff[i];
            result = min(result, minMove);
        }
        return result;
    }
};