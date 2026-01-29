class Solution {
public:
    int n, sum;
    vector<int> nums;

    int maxSumDivThree(vector<int>& numbers) {
        initialize(numbers);
        sortAsc();
        calculateSum();
        return calculateMaxSumDivisibleByTree();
    }

    void initialize(vector<int>& numbers) {
        n = numbers.size();
        nums = numbers;
    }

    void sortAsc() {
        sort(nums.begin(), nums.end());
    }

    int calculateMaxSumDivisibleByTree() {
        if (sum % 3 == 0) {
            return sum;
        }
        if (sum % 3 == 1) {
            return getMaxSumOnRemainIs1();
        }
        if (sum % 3 == 2) {
            return getMaxSumOnRemainIs2();
        }
        return -1;
    }

    void calculateSum() {
        sum = accumulate(nums.begin(), nums.end(), 0);
    }

    int getMaxSumOnRemainIs1() {
        int remainOne = 1e9;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 3 == 1) {
                remainOne = nums[i]; break;
            }
        }

        int remainTwos = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 3 == 2) {
                remainTwos += nums[i], cnt++;
            }
            if (cnt == 2) {
                break;
            }
        }
        remainTwos = (cnt == 2) ? remainTwos : 1e9;
        return sum - min(remainOne, remainTwos);
    }

    int getMaxSumOnRemainIs2() {
        int remainTwo = 1e9;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 3 == 2) {
                remainTwo = nums[i]; break;
            }
        }

        int remainOnes = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 3 == 1) {
                remainOnes += nums[i], cnt++;
            }
            if (cnt == 2) {
                break;
            }
        }
        remainOnes = (cnt == 2) ? remainOnes : 1e9;
        return sum - min(remainTwo, remainOnes);
    }
};