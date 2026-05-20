class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> result(n, 0);
        unordered_set<int> us;
        for (int i = 0; i < n; ++i) {
            if (0 < i) {
                result[i] = result[i - 1];
            }

            if (us.find(a[i]) == us.end()) {
                us.insert(a[i]);
            }
            else {
                result[i]++;
            }

            if (us.find(b[i]) == us.end()) {
                us.insert(b[i]);
            }
            else {
                result[i]++;
            }
        }
        return result;
    }
};