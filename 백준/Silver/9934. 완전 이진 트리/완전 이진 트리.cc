#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int k, numOfNodes;
vector<int> v;
Dim2Vec<int> result;

void inOrder(int rootIdx, int subTreeSize, int level);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k;
    numOfNodes = pow(2, k) - 1;
    result.assign(k, vector<int>());
    v.assign(numOfNodes + 1, 0);
    for (int i = 1; i <= numOfNodes; ++i)
    {
        cin >> v[i];
    }

    inOrder(numOfNodes / 2 + 1, pow(2, k - 1), 0);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void inOrder(int rootIdx, int subTreeSize, int level)
{
    if (1 <= subTreeSize / 2)
    {
        inOrder(rootIdx - subTreeSize / 2, subTreeSize / 2, level + 1);
        inOrder(rootIdx + subTreeSize / 2, subTreeSize / 2, level + 1);
    }
    result[level].emplace_back(v[rootIdx]);
}