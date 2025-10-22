#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(string& str)
{
    long long num = stoll(str);
    str = "";
    if (num < 2)
    {
        return false;
    }
    for (long long i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) 
{
    string kDigit = "";
    while (n != 0)
    {
        kDigit += (n % k) + '0';
        n /= k;
    }
    reverse(kDigit.begin(), kDigit.end());
    
    int result = 0;
    string cur = "";
    for (const auto& c : kDigit)
    {
        if (c == '0')
        {
            if (cur.length() == 0)
            {
                continue;
            }
            if (isPrime(cur))
            {
                result++;
            }
        }
        else
        {
            cur += c;
        }
    }
    
    if (0 < cur.length() && isPrime(cur))
    {
        result++;
    }
    return result;
}