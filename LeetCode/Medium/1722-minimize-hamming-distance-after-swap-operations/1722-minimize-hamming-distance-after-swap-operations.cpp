class Solution {
private:
    vector<int> parents;
    int n;

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        n = source.size();
        parents.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < allowedSwaps.size(); ++i) {
            tryUnion(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        unordered_map<int, unordered_map<int, int>> groupCounts;
        for (int i = 0; i < n; ++i) {
            int root = getRoot(i);
            groupCounts[root][source[i]]++;
        }

        int hammingDist = 0;
        for (int i = 0; i < n; ++i) {
            int root = getRoot(i);
            if (groupCounts[root][target[i]] > 0) {
                groupCounts[root][target[i]]--;
            } else {
                hammingDist++;
            }
        }
        
        return hammingDist;
    }

    int getRoot(int a) {
        return (parents[a] == a) ? a : parents[a] = getRoot(parents[a]);
    }
    
    bool tryUnion(int a, int b) {
        a = getRoot(a);
        b = getRoot(b);
        if (a == b) {
            return false;
        }
        parents[b] = a;
        return true;
    }
};