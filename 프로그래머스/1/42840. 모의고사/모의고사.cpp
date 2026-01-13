#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> scores(4, 0);
    vector<int> supo2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> supo3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; 
    
    for (int i = 0; i < answers.size(); i++) {
        int curAnswer = answers[i];
        scores[1] += (i % 5 + 1 == curAnswer) ? 1 : 0;
        scores[2] += (supo2[i % supo2.size()] == curAnswer) ? 1 : 0;
        scores[3] += (supo3[i % supo3.size()] == curAnswer) ? 1 : 0;
    }
    
    int highestScore = max({scores[1], scores[2], scores[3]});
    vector<int> result;
    for (int i = 1 ; i <= 3; i++) {
        if (highestScore == scores[i]) {
            result.emplace_back(i);
        }
    }
    return result;
}