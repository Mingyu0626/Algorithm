#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited;

int dfs(int curBox, int curScore, const vector<int>& cards);

int solution(vector<int> cards) {
    int n = cards.size();
    visited.assign(n, false);
    vector<int> scores;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            scores.emplace_back(dfs(i, 0, cards));
        }
    }
    
    sort(scores.rbegin(), scores.rend());
    return (2 <= scores.size()) ? scores[0] * scores[1] : 0;
}

int dfs(int curBox, int curScore, const vector<int>& cards) {
    visited[curBox] = true, curScore++;
    int cardNum = cards[curBox] - 1;
    return (visited[cardNum]) ? curScore : dfs(cardNum, curScore, cards);
}