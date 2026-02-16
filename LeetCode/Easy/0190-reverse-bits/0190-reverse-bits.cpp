class Solution {
private:
    string binaryNumber = "";
public:
    void makeBianryNumber(int n) {
        if (n == 0) {
            binaryNumber = "0";
            return;
        }
        while (0 < n) {
            binaryNumber += (n % 2 == 0) ? '0' : '1';
            n /= 2;
        }
    }

    void make32Bits() {
        while (binaryNumber.length() < 32) {
            binaryNumber += '0';
        }
    }

    int convertBinaryToInt() {
        int value = 0;
        for (int i = 0; i < 32; ++i) {
            value += (binaryNumber[i] == '1') ? pow(2, 31 - i) : 0;
        }
        return value;
    }

    int reverseBits(int n) {
        makeBianryNumber(n);
        make32Bits();
        return convertBinaryToInt();
    }
};