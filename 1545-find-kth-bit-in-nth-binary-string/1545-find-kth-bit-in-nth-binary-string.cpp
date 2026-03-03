class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        return recursion(s, 1, n, k);
    }
    char recursion(string& cur, int curN, const int& n, const int& k) {
        if (n == curN) {
            return cur[k - 1];
        }
        string prev = cur;
        cur += '1';
        for (int i = prev.length() - 1; 0 <= i; --i) {
            cur += prev[i] == '0' ? '1' : '0';
        }
        return recursion(cur, curN + 1, n, k);
    }
};