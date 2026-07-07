class Solution {
public:
    long long sumAndMultiply(int n) {
        long long result = 0, sum = 0;
        int digit = 0;
        while (0 < n) {
            int remainder = n % 10;
            result += remainder * pow(10, digit);
            sum += remainder;
            n /= 10;
            digit += (remainder != 0) ? 1 : 0;
        }
        return result * sum;
    }
};