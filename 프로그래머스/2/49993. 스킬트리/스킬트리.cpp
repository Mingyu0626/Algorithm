#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skillTrees) {
    unordered_set<char> us;
    for (const auto& a : skill) {
        us.insert(a);
    }
    
    int n = skillTrees.size();
    vector<string> newSkillTrees;
    for (int i = 0; i < n; ++i) {
        string cur = skillTrees[i], newStr;
        for (int j = 0; j < cur.length(); ++j) {
            if (us.find(cur[j]) != us.end()) {
                newStr.push_back(cur[j]);
            }
        }
        newSkillTrees.emplace_back(newStr);
    }
    
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += (skill.find(newSkillTrees[i]) == 0) ? 1 : 0;
    }
    return result;
}