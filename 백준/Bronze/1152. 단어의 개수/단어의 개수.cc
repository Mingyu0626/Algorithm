#include <iostream>
#include <string>

using namespace std;

string s;
int result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> s)
    {
        result++;
    }
    cout << result;
    return 0;
}