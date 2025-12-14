class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int curSeat = 0, n = corridor.length();
        long long result = 1, cases = 1;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                if (curSeat == 2) {
                    result *= cases;
                    result %= MOD;
                    curSeat = 0, cases = 1;
                }
                curSeat++;
            }
            if (corridor[i] == 'P' && curSeat == 2) {
                cases += 1;
            }
        }

        if (curSeat != 2) {
            result = 0;
        }
        return result;
    }
};