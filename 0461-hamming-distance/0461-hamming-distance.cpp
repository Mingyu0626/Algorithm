class Solution {
public:
    int hammingDistance(int x, int y) {
        string xBit = bitset<31>(x).to_string();
        string yBit = bitset<31>(y).to_string();
        int result = 0;
        for (int i = 0; i < xBit.length(); ++i) {
            result += (xBit[i] != yBit[i]) ? 1 : 0;
        }
        return result;
    }
};