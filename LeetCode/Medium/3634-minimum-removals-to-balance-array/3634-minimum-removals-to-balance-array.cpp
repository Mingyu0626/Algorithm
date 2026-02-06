class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, n = nums.size(), result = n;
        long long minElement, maxElement;
        while (i <= j && j < n) {
            minElement = nums[i], maxElement = nums[j];
            if (maxElement <= minElement * k) { 
                result = min(result, n - (j - i + 1));
                j++;
            }
            else {
                i++;
            }
        }
        return result;
    }
};