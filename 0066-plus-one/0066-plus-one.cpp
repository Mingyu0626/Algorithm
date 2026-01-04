class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        for (int i = digits.size() - 1; i > 0; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1]++;
            }
        }

        vector<int> result;
        if (digits[0] == 10) {
            digits[0] = 0;
            result.emplace_back(1);
        }
        for (const auto& d : digits) {
            result.emplace_back(d);
        }
        return result;
    }
};