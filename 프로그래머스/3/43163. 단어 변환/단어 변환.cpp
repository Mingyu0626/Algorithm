#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int bfs(const string begin, const string target, const vector<string>& words);

int solution(string begin, string target, vector<string> words) 
{
    return bfs(begin, target, words);
}

int bfs(const string begin, const string target, const vector<string>& words)
{
    unordered_set<string> visited;
    visited.insert(begin);
    
    unordered_set<string> wordHashSet;
    for (string word : words)
    {
        wordHashSet.insert(word);
    }
    
    queue<string> q;
    q.push(begin);
    
    int level = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            string curWord = q.front();
            q.pop();
            
            if (curWord == target)
            {
                return level;
            }
            
            for (int j = 0; j < curWord.length(); ++j)
            {
                string newWord = curWord;
                char newChar = 'a';
                for (int k = 0; k <= 25; ++k)
                {
                    newWord[j] = newChar;
                    if (wordHashSet.find(newWord) != wordHashSet.end() &&
                       visited.find(newWord) == visited.end())
                    {
                        q.push(newWord);
                        visited.insert(newWord);
                    }
                    newChar += 1;
                }
            }
        }
        level++;
    }
    return 0;
}