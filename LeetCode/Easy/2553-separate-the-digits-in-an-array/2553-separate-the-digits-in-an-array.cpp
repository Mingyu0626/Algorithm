class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (const int& a : nums) {
            string s = to_string(a);
            for (const char& c : s) {
                result.emplace_back(c - '0');
            } 
        }
        return result;
    }
};