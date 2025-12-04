#include <iostream>
#include <vector>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, edge;
Dim2Vec<int> adjMatrix;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    adjMatrix.assign(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> edge;
            if (edge == 0) {
                continue;
            }
            adjMatrix[i][j] = edge;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j]) {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                }
            }
        }
    }

    bool hasRoute;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            hasRoute = (adjMatrix[i][j] == 1e9) ? false : true;
            cout << hasRoute << ' ';
        }
        cout << '\n';
    }
    return 0;
}