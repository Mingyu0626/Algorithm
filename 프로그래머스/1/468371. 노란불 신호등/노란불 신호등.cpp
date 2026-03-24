#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) {
    int lcm = 1;
    for (int i = 0; i < signals.size(); ++i) {
        lcm *= (signals[i][0] + signals[i][1] + signals[i][2]);
    }
    
    for (int t = 1; t <= lcm; ++t) {
        int yellowCnt = 0;
        for (int i = 0; i < signals.size(); ++i) {
            int g = signals[i][0], y = signals[i][1], r = signals[i][2];
            int cycle = g + y + r, timeInCycle = t % cycle;
            yellowCnt += (g < timeInCycle && timeInCycle <= g + y) ? 1 : 0; 
        }
        if (yellowCnt == signals.size()) {
            return t;
        }
    }
    return -1;
}