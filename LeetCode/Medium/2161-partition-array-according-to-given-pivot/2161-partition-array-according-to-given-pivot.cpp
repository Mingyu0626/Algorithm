class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        stable_sort(nums.begin(), nums.end(), [pivot](int a, int b) {
            if ((a < pivot && b < pivot) || (pivot < a && pivot < b)) {
                return false;
            }
            return a < pivot || pivot < b;
        });
        return nums;
    }
};