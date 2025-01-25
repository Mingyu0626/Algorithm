#include <iostream>
#include <vector>

using namespace std; 

struct point{ int x, y; };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<point> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i].x >> v[i].y;
    
    point a = { v[1].x - v[0].x, v[1].y - v[0].y };
    point b = { v[2].x - v[1].x, v[2].y - v[1].y };

    int cp = (a.x * b.y) - (a.y * b.x);
    if (cp > 0) cout << 1;
    else if (cp == 0) cout << 0;
    else cout << -1;
    return 0;
}