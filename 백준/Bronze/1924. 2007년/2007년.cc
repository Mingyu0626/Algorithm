#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int x, y;
vector<int> v;
int month[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
string result[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x >> y;
    int day = (month[x - 1] + y) % 7;
    cout << result[day];
    return 0;
}