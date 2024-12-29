#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

int k;
vector<char> v(9);
bool used[10], isMax = true, isMin = true;
string result;

void dfsMax(int cur, int val);
void dfsMin(int cur, int val);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    result.assign(k + 1, ' ');
    for (int i = 0; i < k; i++) cin >> v[i];
    for (int i = 9; i >= 0; i--)
    {
        used[i] = true;
        dfsMax(0, i);
        used[i] = false;
    }
    for (int i = 0; i <= 9; i++)
    {
        used[i] = true;
        dfsMin(0, i);
        used[i] = false;
    }
    return 0;
}

void dfsMax(int cur, int val)
{
    result[cur] = val + '0';
    if (cur == k)
    {
        if (isMax)
        {
            cout << result << '\n';
            isMax = false;
        }
        return;
    }

    if (v[cur] == '<')
    {
        for (int i = 9; i >= 0; i--)
        {
            if (!used[i] && result[cur] - '0' < i)
            {
                used[i] = true;
                dfsMax(cur + 1, i);
                used[i] = false;
            }
        }
        return;
    }
    else
    {
        for (int i = 9; i >= 0; i--)
        {
            if (!used[i] && result[cur] - '0' > i)
            {
                used[i] = true;
                dfsMax(cur + 1, i);
                used[i] = false;
            }
        }
        return;
    }
}

void dfsMin(int cur, int val)
{
    result[cur] = val + '0';
    if (cur == k)
    {
        if (isMin)
        {
            cout << result << '\n';
            isMin = false;
        }
        return;
    }

    if (v[cur] == '<')
    {
        for (int i = 0; i <= 9; i++)
        {
            if (!used[i] && result[cur] - '0' < i)
            {
                used[i] = true;
                dfsMin(cur + 1, i);
                used[i] = false;
            }
        }
        return;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if (!used[i] && result[cur] - '0' > i)
            {
                used[i] = true;
                dfsMin(cur + 1, i);
                used[i] = false;
            }
        }
        return;
    }
}