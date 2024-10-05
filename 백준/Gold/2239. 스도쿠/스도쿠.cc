#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[10][10];

void go(int r, int c);
bool check(int r, int c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }

    go(1, 1);
    return 0;
}

void go(int r, int c)
{
    if (r == 10)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << map[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        exit(0);
    }
    if (c == 10)
    {
        go(r + 1, 1);
        return;
    }

    if (map[r][c] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            map[r][c] = i;
            if (check(r, c)) go(r, c + 1);
        }
        map[r][c] = 0;
    }
    else go(r, c + 1);
}

bool check(int r, int c)
{
    for (int i = 1; i <= 9; i++)
    {
        if (map[r][c] == map[r][i] && c != i) return false;
        if (map[r][c] == map[i][c] && r != i) return false;
    }

    int startR = ((r - 1) / 3) * 3 + 1;
    int startC = ((c - 1) / 3) * 3 + 1;
    
    for (int i = startR; i < startR + 3; i++)
    {
        for (int j = startC; j < startC + 3; j++)
        {
            if (r == i && c == j) continue;
            if (map[r][c] == map[i][j]) return false;
        }
    }
    return true;
}
