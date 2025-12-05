#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, numOfDrawing, maxArea;
Dim2Vec<int> v;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void getInput();
void countDrawing();
void bfs(const int& startX, const int& startY);
bool isValid(const int& x, const int& y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getInput();
    countDrawing();
    cout << numOfDrawing << '\n' << maxArea;
    return 0;
}

void getInput() {
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
}

void countDrawing() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 1) {
                bfs(i, j);
            }
        }
    }
}

void bfs(const int& startX, const int& startY) {
    queue<pii> q;
    q.push({ startX, startY });
    v[startX][startY] = 0;
    int area = 1;
    while (!q.empty()) {
        int curX = q.front().first, curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (!isValid(newX, newY) || v[newX][newY] == 0) {
                continue;
            }
            q.push({ newX, newY });
            v[newX][newY] = 0;
            area++;
        }
    }
    numOfDrawing++;
    maxArea = max(maxArea, area);
}

bool isValid(const int& x, const int& y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}