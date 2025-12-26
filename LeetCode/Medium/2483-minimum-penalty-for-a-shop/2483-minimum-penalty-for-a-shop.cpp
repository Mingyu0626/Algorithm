class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> numOfY(n + 1, 0), numOfN(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            numOfY[i] = numOfY[i - 1], numOfN[i] = numOfN[i - 1];
            if (customers[i - 1] == 'Y') {
                numOfY[i] += 1;
            }
            if (customers[i - 1] == 'N') {
                numOfN[i] += 1;
            }
        }

        int minPenalty = 1e9, result = 0;
        for (int i = 1; i <= n; ++i) {
            int curPenalty = numOfY[n] - numOfY[i - 1] + numOfN[i - 1];
            if (curPenalty < minPenalty) {
                result = i - 1;
                minPenalty = curPenalty;
            }
        }
        int lastPenalty = numOfN[n];
        if (lastPenalty < minPenalty) {
            result = n;
            minPenalty = lastPenalty;
        }
        return result;
    }
};