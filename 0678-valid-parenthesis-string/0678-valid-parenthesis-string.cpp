class Solution 
{
public:
    int minLeftCnt = 0; // *를 empty나 )로 간주 했을 때 왼괄호 수
    int maxLeftCnt = 0; // *를 (로 간주 했을 때 왼괄호 수
    bool checkValidString(string s) 
    {
        for (const char& c : s)
        {
            if (c == '(')
            {
                minLeftCnt++, maxLeftCnt++;
            }
            else if (c == ')')
            {
                if (maxLeftCnt == 0)
                {
                    return false;
                }
                minLeftCnt--, maxLeftCnt--;
            }
            else
            {
                minLeftCnt--, maxLeftCnt++;
            }
            minLeftCnt = max(0, minLeftCnt);
        }
        return minLeftCnt == 0;
    }
};