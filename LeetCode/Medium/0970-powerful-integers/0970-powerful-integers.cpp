class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int small = min(x, y), big = max(x, y);
        if (big == 1) {
            return (1 < bound) ? vector<int>(1, 2) : vector<int>();
        }

        vector<int> result;
        if (small == 1) {
            for (int i = 1; i < bound + 1; i *= big) {
                result.emplace_back(i + 1);
            }
            return result;
        }

        unordered_set<int> us;
        for (int i = 1; i < bound; i *= x) {
            for (int j = 1; j < bound; j *= y) {
                int a = i + j;
                if (bound < a) {
                    break;
                }
                if (us.find(a) == us.end()) {
                    us.insert(a);
                }
            }
        }
        for (const auto& a : us) {
            result.emplace_back(a);
        }
        return result;
    }
};