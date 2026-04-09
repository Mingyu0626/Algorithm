bool compare(const int& a, const int& b) {
    int numOfZeroA = __builtin_popcount(a);
    int numOfZeroB = __builtin_popcount(b);
    if (numOfZeroA == numOfZeroB) {
        return a < b;
    }
    return numOfZeroA < numOfZeroB;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};