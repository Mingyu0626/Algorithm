#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n;
vector<int> parents;

void getInput();
void init();
int getRoot(int a);
void Union(int a, int b);
void compressPath();
void print();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getInput();
    compressPath();
    print();
    return 0;
}

void getInput() {
    cin >> n;
    init();
    int a, b;
    for (int i = 0; i < n - 2; ++i) {
        cin >> a >> b;
        Union(a, b);
    }
}

void init()
{
    parents.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
    }
}

int getRoot(int a)
{
    if (parents[a] == a) {
        return a;
    }
    return parents[a] = getRoot(parents[a]);
}

void Union(int a, int b)
{
    a = getRoot(a), b = getRoot(b);
    if (a < b) {
        parents[b] = a;
    }
    else {
        parents[a] = b;
    }
}

void compressPath()
{
    for (int i = 1; i <= n; ++i) {
        getRoot(i);
    }
}

void print() {
    unordered_set<int> us;
    for (int i = 1; i <= n; ++i) {
        if (us.find(parents[i]) == us.end()) {
            cout << parents[i] << ' ';
            us.insert(parents[i]);
        }
    }
}