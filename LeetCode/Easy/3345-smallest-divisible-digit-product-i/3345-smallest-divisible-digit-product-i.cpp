class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            string s = to_string(n);
            int digitP = 1;
            for (int i = 0; i < s.length(); ++i) {
                digitP *= s[i] - '0';
            }
            if (digitP % t == 0) {
                break;
            }
            n++;
        }
        return n;
    }
};