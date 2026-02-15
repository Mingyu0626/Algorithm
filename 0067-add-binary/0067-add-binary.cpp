class Solution {
private:
    string a, b;
public:
    void moveLongerStringToA() {
        if (a.length() < b.length()) {
			string tmp = a;
			a = b;
			b = tmp;
		}
    }
	string addBinary(string A, string B) {
        a = A, b = B;
        moveLongerStringToA();

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = 0; i < b.length(); i++) {
			int na = a[i] - '0';
			int nb = b[i] - '0';

			if (1 < na + nb) {
				a[i] = ('0' + na + nb - 2);
				if (i == a.size() - 1) {
                    a += '1';
                }
				else {
                    a[i + 1]++;
                }
			}
			else {
				a[i] = ('0' + na + nb);
			}
		}

		for (int i = b.size(); i < a.size(); i++) {
			if (a[i] == '2') {
				a[i] = '0';
				if (i == a.size() - 1) {
                    a += '1';
                }
				else {
                    a[i + 1]++;
                }
			}
			else {
                break;
            }
		}
		reverse(a.begin(), a.end());
		return a;
	}
};