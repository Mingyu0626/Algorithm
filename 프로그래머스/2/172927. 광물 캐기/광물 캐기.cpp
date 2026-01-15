#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct mineralInfo { int d = 0, i = 0, s = 0; };

bool compare(const mineralInfo& a, const mineralInfo& b) {
    if (a.d == b.d) {
        if (a.i == b.i) {
            return a.s > b.s;
        }
        return a.i > b.i;
    }
    return a.d > b.d;
}

int solution(vector<int> picks, vector<string> minerals) {
    int n = minerals.size();
    vector<mineralInfo> v;
    
    int numOfPicks = picks[0] + picks[1] + picks[2];
    int pickableMinerals = min(numOfPicks * 5, n);
    
    mineralInfo curInfo;
    for (int i = 1; i <= pickableMinerals; ++i) {
        string cur = minerals[i - 1];
        curInfo.d += (cur == "diamond") ? 1 : 0;
        curInfo.i += (cur == "iron") ? 1 : 0;
        curInfo.s += (cur == "stone") ? 1 : 0;
        if (i % 5 == 0 || i == pickableMinerals) {
            v.push_back(curInfo);
            curInfo = {};
        }
    }
    
    int result = 0;
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < v.size(); ++i) {
        int diamond = v[i].d, iron = v[i].i, stone = v[i].s;    
        if (0 < picks[0]) {
            result += diamond + iron + stone; picks[0]--;
        } else if (0 < picks[1]) {
            result += (diamond * 5) + iron + stone; picks[1]--;
        } else if (0 < picks[2]) {
            result += (diamond * 25) + (iron * 5) + stone; picks[2]--;
        } else {
            return result;
        }
    } 
    return result;
}