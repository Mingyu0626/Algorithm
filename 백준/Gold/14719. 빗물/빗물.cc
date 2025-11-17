#include <iostream>
#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int h, w, curH, result;
Dim2Vec<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> h >> w;
    v.assign(h, vector<int>(w));
    for (int i = 0; i < w; ++i)
    {
        cin >> curH;
        for (int j = h - 1; j >= h - curH; --j)
        {
            v[j][i] = 1;
        }
    }

    for (int i = 0; i < h; ++i)
    {
        bool isBlocked = false;
        int curArea = 0;
        for (int j = 0; j < w; ++j)
        {
            if (v[i][j] == 1)
            {
                if (!isBlocked)
                {
                    isBlocked = true;
                }
                else
                {
                    result += curArea;
                }
                curArea = 0;
            }
            else
            {
                curArea++;
            }
        }
    }
    cout << result;
    return 0;
}