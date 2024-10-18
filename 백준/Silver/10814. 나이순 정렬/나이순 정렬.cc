#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std; 

struct info
{
    int age;
    string name;
    int num;
};

int n;
vector<info> v;

bool compare(info& a, info& b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, {});
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].age >> v[i].name;
        v[i].num = i;
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 1; i <= n; i++)
    {
        cout << v[i].age << ' ' << v[i].name << '\n';
    }
    return 0;
}

bool compare(info& a, info& b)
{
    if (a.age == b.age) return a.num < b.num;
    return a.age < b.age;
}