#include <iostream>
#include <algorithm>

using namespace std;

char cur;
int frame = 1, prevThrow, result;
int multi, triple;
bool isSecond = false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> cur)
    {
        if (cur == '-')
        {
            triple = max(triple - 1, 0);
            multi = max(multi - 1, 0);

            prevThrow = 0;
            if (isSecond)
            {
                isSecond = false;
                frame = min(10, frame + 1);
            }
            else isSecond = true;
        }
        else if (cur == 'S')
        {
            if (triple > 0) result += 10 * 3;
            else if (multi > 0)
            {
                result += 10 * 2;
                if (frame != 10)
                {
                    if (multi == 2) triple = 1;
                    else multi = 2;
                }
            }
            else
            {
                result += 10;
                if (frame != 10) multi = 2;
            }

            if (frame != 10)
            {
                frame = min(10, frame + 1);
            }
            else
            {
                triple = max(triple - 1, 0);
                multi = max(multi - 1, 0);
            }
            isSecond = false;
        }

        else if (cur == 'P')
        {
            result += (10 - prevThrow) * (multi + 1);
            if (frame != 10)
            {
                triple = 0, multi = 1;
                frame = min(10, frame + 1);
            }
            else
            {
                triple = max(triple - 1, 0);
                multi = max(multi - 1, 0);
            }
            isSecond = false;
        }
        else
        {
            int curScore = cur - '0';
            if (triple > 0) result += curScore * 3;
            else if (multi > 0) result += curScore * 2;
            else result += curScore;

            triple = max(triple - 1, 0);
            multi = max(multi - 1, 0);
            prevThrow = curScore;
            if (isSecond)
            {
                isSecond = false;
                frame = min(10, frame + 1);
            }
            else isSecond = true;
        }
    }

    cout << result;
    return 0;
}