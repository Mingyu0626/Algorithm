public class Solution 
{
    long[,] dp = new long[2001, 3];
    
    public long solution(int n) 
    {
        dp[1, 1] = 1;
        dp[2, 1] = 1;
        dp[2, 2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            dp[i, 1] = (dp[i - 1, 1] + dp[i - 1, 2]) % 1234567;
            dp[i, 2] = (dp[i - 2, 1] + dp[i - 2, 2]) % 1234567;
        }
        
        return (dp[n, 1] + dp[n, 2]) % 1234567;
    }
}