class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0;
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            diff[i] = gas[i] - cost[i];
            sum += diff[i];
        }

        if (sum < 0) {
            return -1;
        }

        int result = -1, maxGas = -INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            sum += diff[i];
            if (maxGas < sum) {
                maxGas = sum;
                result = i;
            }
        }
        return result;
    }
};