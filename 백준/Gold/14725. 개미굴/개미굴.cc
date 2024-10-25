#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <limits.h>

using namespace std;

struct Trie
{
    map<string, Trie*> child;
    bool isEnd;

    Trie()
    {
        isEnd = false;
    }

    void insert(vector<string>& v, int idx)
    {
        if (idx == v.size()) return;

        if (child.find(v[idx]) == child.end())
        {
            Trie* trie = new Trie;
            child.insert({ v[idx], new Trie() });
        }
        child[v[idx]]->insert(v, idx + 1);
    }

    void dfs(int d)
    {
        for (auto& i : child)
        {
            for (int j = 0; j < d; j++)
            {
                cout << "--";
            }
            cout << i.first << '\n';
            i.second->dfs(d + 1);
        }
    }
};

int n, k;
string temp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Trie* root = new Trie();
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vector<string> v(k);
        for (int j = 0; j < k; j++)
        {
            cin >> v[j];
        }
        root->insert(v, 0);
    }
    root->dfs(0);
    delete root;
    return 0;
}