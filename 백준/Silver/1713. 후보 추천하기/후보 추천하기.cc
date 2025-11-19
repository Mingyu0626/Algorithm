#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, num;
vector<int> recommend, frames;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    recommend.assign(101, 1001);
    for (int i = 0; i < m; ++i)
    {
        cin >> num;
        if (recommend[num] == 1001)
        {
            if (frames.size() == n)
            {
                int minRecommend = *min_element(recommend.begin(), recommend.end());
                for (int i = 0; i < n; ++i)
                {
                    int student = frames[i];
                    if (recommend[student] == minRecommend)
                    {
                        recommend[student] = 1001;
                        frames.erase(frames.begin() + i);
                        break;
                    }
                }
            }
            recommend[num] = 1;
            frames.emplace_back(num);
        }
        else
        {
            recommend[num]++;
        }
    }

    sort(frames.begin(), frames.end());
    for (const int& num : frames)
    {
        cout << num << ' ';
    }
    return 0;
}