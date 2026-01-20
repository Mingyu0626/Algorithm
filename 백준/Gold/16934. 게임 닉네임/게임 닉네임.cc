#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string s;

struct Node {
    Node* children[26];
    bool isEnd;
    Node() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* root;
    unordered_map<string, int> nameTable;

    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* node = root;
        string alias;
        bool hasPrefix = false;
        for (const auto& c : s) {
            if (!hasPrefix) {
                alias.push_back(c);
            }

            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Node();
                hasPrefix = true;
            }
            node = node->children[idx];
        }
        node->isEnd = true;
        addNickName(s, alias);
    }

    void addNickName(string& nickName, string& alias) {
        string x;
        if (nameTable.find(nickName) != nameTable.end()) {
            x = to_string(nameTable[nickName] + 1);
        }
        cout << alias << x << '\n';
        nameTable[nickName]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Trie* trie = new Trie();
    for (int i = 0; i < n; ++i) {
        cin >> s;
        trie->insert(s);
    }
    return 0;
}