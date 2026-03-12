#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

unordered_set<string> words;
vector<vector<int>> spoilerRanges;
vector<vector<string>> candidates;

void splitMessage(string message);
void categorizeWord(int s, int e, string word);
int judgeImportant();

int solution(string message, vector<vector<int>> spoiler_ranges) {
    spoilerRanges = spoiler_ranges;
    splitMessage(message);
    return judgeImportant();
}

void splitMessage(string message) {
    stringstream ss(message);
    string word;
    candidates.assign(spoilerRanges.size(), vector<string>());
    while (ss >> word) {
        int curPos = ss.tellg();
        curPos = (curPos == -1) ? message.length() : curPos;
        int s = curPos - word.length(), e = curPos - 1;
        categorizeWord(s, e, word);
    }
}

void categorizeWord(int s, int e, string word) {
    bool isInSpoilerRange = false;
    for (int i = 0; i < spoilerRanges.size(); ++i) {
        if (!(e < spoilerRanges[i][0] || spoilerRanges[i][1] < s)) {
            candidates[i].emplace_back(word);
            isInSpoilerRange = true;
            i = spoilerRanges.size();
        }
    }
    if (!isInSpoilerRange) {
        words.insert(word);
    }
}

int judgeImportant() {
    int numOfImportant = 0;
    for (int i = 0; i < candidates.size(); ++i) {
        for (int j = 0; j < candidates[i].size(); ++j) {
            string word = candidates[i][j];
            if (words.find(word) == words.end()) {
                numOfImportant++;
                words.insert(word);
            }
        }
    }
    return numOfImportant;
}

