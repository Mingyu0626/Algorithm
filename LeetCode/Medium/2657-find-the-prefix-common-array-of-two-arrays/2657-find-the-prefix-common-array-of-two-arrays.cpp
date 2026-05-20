class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> result(n, 0), freq(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
            result[i] += (freq[a[i]] == 2) ? 1 : 0;
            freq[b[i]]++;
            result[i] += (freq[b[i]] == 2) ? 1 : 0;

            if (0 < i) {
                result[i] += result[i - 1];
            }
        }
        return result;
    }
};