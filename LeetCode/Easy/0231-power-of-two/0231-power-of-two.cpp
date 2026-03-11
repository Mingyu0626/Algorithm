class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) {
            return false;
        }
        
        int cur = 0;
        while (cur < n - 1) {
            cur = (cur << 1) | 1;
        }
        return cur == n - 1;
    }
};