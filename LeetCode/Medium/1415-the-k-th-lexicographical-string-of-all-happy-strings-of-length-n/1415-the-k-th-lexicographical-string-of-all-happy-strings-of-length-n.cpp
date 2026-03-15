class Solution {
private:
    vector<string> v;
public:
    void makeHappyString(const int& n, string cur) {
        if (n == cur.length()) {
            v.emplace_back(cur);
            return;
        }

        char prev = cur[cur.length() - 1];
        for (int i = 0; i < 3; ++i) {
            char c = 'a' + i;
            if (prev == c) {
                continue;
            }
            makeHappyString(n, cur + c);
        }
    }
    
    string getHappyString(int n, int k) {
        for (int i = 0; i < 3; ++i) {
            char c = 'a' + i;
            string s(1, c);
            makeHappyString(n, s);
        }
        return (k <= v.size()) ? v[k - 1] : "";
    }
};