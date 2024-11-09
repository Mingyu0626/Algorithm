#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std; 

int t, f;
int parent[200001], numOfFriends[200001];
unordered_map<string, int> um;
string s1, s2;

int GetRoot(int a);
void Union(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> f;
        um.clear();
        for (int i = 1; i <= 200000; i++)
        {
            parent[i] = i, numOfFriends[i] = 1;
        }

        int friendNumber = 0, a = 0, b = 0;
        for (int i = 0; i < f; i++)
        {
            cin >> s1 >> s2;
            if (um.find(s1) == um.end())
            {
                friendNumber++;
                um.insert({ s1, friendNumber });
                a = friendNumber;
            }
            else a = um[s1];

            if (um.find(s2) == um.end())
            {
                friendNumber++;
                um.insert({ s2, friendNumber });
                b = friendNumber;
            }
            else b = um[s2];

            Union(a, b);
            cout << numOfFriends[GetRoot(a)] << '\n';
        }
        t--;
    }
    return 0;
}

int GetRoot(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = GetRoot(parent[a]);
}

void Union(int a, int b)
{
    a = GetRoot(a);
    b = GetRoot(b);
    if (a != b)
    {
        parent[a] = b;
        numOfFriends[b] += numOfFriends[a];
    }
}