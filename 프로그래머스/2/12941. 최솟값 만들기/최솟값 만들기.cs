using System;
using System.Linq;

public class Solution 
{
    public int solution(int[] A, int[] B) 
    {
        int result = 0;
        Array.Sort(A); 
        Array.Sort(B); 
        Array.Reverse(B);
        for (int i = 0; i < A.Length; ++i)
        {
            result += A[i] * B[i];
        }
        return result;
    }
}