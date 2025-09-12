#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in, inPos, post;

void recursion(int inStartIdx, int inEndIdx, int postStartIdx, int postEndIdx, int root);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    in.assign(n + 1, 0), post.assign(n + 1, 0), inPos.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> in[i];
        inPos[in[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> post[i];
    }
    int root = post[n];
    recursion(1, n, 1, n, root);
    return 0;
}

void recursion(int inStartIdx, int inEndIdx, int postStartIdx, int postEndIdx, int root)
{
    cout << root << ' ';
    int rootIdx = inPos[root];

    int leftSubTreeSize = rootIdx - inStartIdx;
    int rightSubTreeSize = inEndIdx - rootIdx;
    int leftPostEndIdx = postStartIdx + leftSubTreeSize - 1;
    int rightPostEndIdx = postEndIdx - 1;
    if (0 < leftSubTreeSize)
    {
        recursion(inStartIdx, inStartIdx + leftSubTreeSize - 1, postStartIdx, leftPostEndIdx, post[leftPostEndIdx]);
    }
    if (0 < rightSubTreeSize)
    {
        recursion(rootIdx + 1, rootIdx + rightSubTreeSize, leftPostEndIdx + 1, rightPostEndIdx, post[rightPostEndIdx]);
    }
}