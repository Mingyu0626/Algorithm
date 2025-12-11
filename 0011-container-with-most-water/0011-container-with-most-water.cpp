class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), result = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int minHeight = min(height[l],  height[r]), width = r - l;
            int waterAmount = minHeight * width;
            result = max(result, waterAmount);
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return result;
    }
};