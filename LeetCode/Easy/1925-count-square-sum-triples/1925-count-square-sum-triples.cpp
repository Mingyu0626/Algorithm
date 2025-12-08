class Solution {
public:
    int countTriples(int n) {
        
        int result = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int sum = a * a + b * b;
                double sqrtSum = sqrt(sum);
                if ((int)sqrtSum == sqrtSum && sqrtSum <= n) {
                    result++;
                }
            }
        }
        return result;
    }
};