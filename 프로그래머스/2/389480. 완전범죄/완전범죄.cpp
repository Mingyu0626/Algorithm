#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int solution(vector<vector<int>> info, int n, int m) {
    int numOfItems = info.size();
    Dim2Vec<int> dp(numOfItems, vector<int>(m));
    
    for (int j = 0; j < m; ++j) {
        dp[0][j] = (j < info[0][1]) ? info[0][0] : 0; 
    }
    
    for (int i = 1; i < numOfItems; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < info[i][1]) {
                dp[i][j] = dp[i - 1][j] + info[i][0];
            }
            else {
                dp[i][j] = min(dp[i - 1][j] + info[i][0], dp[i - 1][j - info[i][1]]);
            }
        }
    }
    
    int result = (dp[numOfItems - 1][m - 1] < n) ? dp[numOfItems - 1][m - 1] : -1;
    return result;
}