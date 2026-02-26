#include <iostream>
#include <vector>

using namespace std;

string s;
vector<int> pSumRCount, pSumKCount;

void makePrefixSum();
int getLongestKKRKK();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    if (s.length() == 0) {
        cout << '0';
        return 0;
    }
    makePrefixSum();
    cout << getLongestKKRKK();
    return 0;
}

void makePrefixSum()
{
    pSumRCount.assign(s.length(), 0);
    pSumRCount[0] = s[0] == 'R' ? 1 : 0;
    pSumKCount.assign(s.length(), 0);
    pSumKCount[0] = s[0] == 'K' ? 1 : 0;
    for (int i = 1; i < s.length(); ++i) {
        pSumRCount[i] = (s[i] == 'R') ? pSumRCount[i - 1] + 1 : pSumRCount[i - 1];
        pSumKCount[i] = (s[i] == 'K') ? pSumKCount[i - 1] + 1 : pSumKCount[i - 1];
    }
}

int getLongestKKRKK()
{
    int l = 0, r = s.length() - 1, maxLength = 0;
    while (l <= r) {
        int leftKCount = (l != 0) ? pSumKCount[l - 1] : 0;
        int rightKCount = pSumKCount[s.length() - 1] - pSumKCount[r];
        int rCount = (l != 0) ? pSumRCount[r] - pSumRCount[l - 1] : pSumRCount[r];
        if (rCount != 0) {
            maxLength = max(maxLength, rCount + min(leftKCount, rightKCount) * 2);
        }

        if (leftKCount < rightKCount) {
            l++;
        }
        else {
            r--;
        }
    }
    return maxLength;
}