class Solution {
public:
    int binaryGap(int n) {
        int result = 0, last1Idx = -1, curIdx = 0;
        while (0 < n) {
            result = (last1Idx != -1 && n % 2 == 1)
            ? max(curIdx - last1Idx, result) : result;
            last1Idx = (n % 2 == 1) ? curIdx : last1Idx;
            curIdx++;
            n = n >> 1;
        }
        return result;
    }
};