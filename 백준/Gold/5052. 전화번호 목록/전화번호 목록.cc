#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

int t, n;
string s;
bool isConsistent = true;

struct Node
{
    Node* num[10];
    bool isEnd;

    Node()
    {
        isEnd = false;
        for (int i = 0; i < 10; i++) num[i] = nullptr;
    }
};

class Trie
{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string phoneNum)
    {
        Node* node = root;
        for (char c : phoneNum)
        {
            int idx = c - '0';
            if (!node->num[idx])
            {
                node->num[idx] = new Node();
            }
            node = node->num[idx];
        }
        node->isEnd = true;
    }

    bool search(string phoneNum)
    {
        Node* node = root;
        int size = phoneNum.size();
        for (int i = 0; i < size; i++)
        {
            Node* cur = node;
            for (int j = 0; j <= i; j++)
            {
                int idx = phoneNum[j] - '0';
                if (!cur->num[idx])
                {
                    break;
                }
                cur = cur->num[idx];
                if (cur->isEnd) return true;
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        isConsistent = true;
        Trie trie;
        vector<string> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (trie.search(v[i]))
            {
                isConsistent = false;
                break;
            }
            else trie.insert(v[i]);
        }
        if (!isConsistent) cout << "NO\n";
        else cout << "YES\n";
        t--;
    }
}