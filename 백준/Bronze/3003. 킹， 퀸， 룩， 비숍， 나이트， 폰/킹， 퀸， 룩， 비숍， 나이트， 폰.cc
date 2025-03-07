#include <iostream>

using namespace std;

int chessArray[6] = { 1, 1, 2, 2, 2, 8 };
int cur;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 6; i++)
    {
        cin >> cur;
        cout << chessArray[i] - cur << ' ';
    }
    return 0;
}