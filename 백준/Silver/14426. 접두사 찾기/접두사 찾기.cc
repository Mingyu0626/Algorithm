#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, result;
string s;

class Trie
{
private:
    Trie* node[26];

public:
    Trie()
    {
        for (int i = 0; i < 26; i++) node[i] = nullptr;
    }
    void insert(string& word, int idx)
    {
        int letterIdx = word[idx] - 'a';
        if (idx == word.size()) return;

        if (!node[letterIdx])
        {
            node[letterIdx] = new Trie();
        }
        node[letterIdx]->insert(word, idx + 1);
    }

    bool search(string& word, int idx)
    {
        int letterIdx = word[idx] - 'a';
        if (idx == word.size())
        {
            return true;
        }
        if (!node[letterIdx])
        {
            return false;
        }
        else
        {
            return node[letterIdx]->search(word, idx + 1);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    Trie* root = new Trie();
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        root->insert(s, 0);
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        if (root->search(s, 0)) result++;
    }
    cout << result;
    return 0;
}