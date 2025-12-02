class Solution 
{
public:
    unordered_map<int, int> um;

    int nextBeautifulNumber(int n) 
    {
        while (!isBeautifulNumber(++n)) {}
        return n;
    }

    bool isBeautifulNumber(int n)
    {
        um.clear();
        while (n != 0)
        {
            um[n % 10]++;
            n /= 10;
        }
        
        for (const auto& a : um)
        {
            if (a.first != a.second)
            {
                return false;
            }
        }
        return true;
    }
};