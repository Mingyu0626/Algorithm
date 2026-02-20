class Solution {
private:
    unordered_map<string, vector<string>> um;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (int i = 0; i < strs.size(); ++i) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            um[cur].emplace_back(strs[i]);
        }
        vector<vector<string>> result;
        for (const auto& a : um) {
            result.push_back(a.second);
        }
        return result;
    }
};