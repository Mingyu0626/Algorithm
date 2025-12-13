struct Coupon {
    string code;
    string businessLine;
    bool isActive;
};

class Solution {
private:
    unordered_set<string> validCategories = {"electronics", "grocery", "pharmacy", "restaurant"};

    vector<Coupon> packCoupons(const vector<string>& code, const vector<string>& businessLine, const vector<bool>& isActive) {
        int numOfCoupons = code.size();
        vector<Coupon> coupons;
        for (int i = 0; i < numOfCoupons; ++i) {
            coupons.push_back({code[i], businessLine[i], isActive[i]});
        }
        return coupons;
    }

    vector<string> extractValidCouponCodes(const vector<Coupon>& coupons) {
        vector<string> validCodes;
        for (const auto& coupon : coupons) {
            if (!isValidCoupon(coupon)) {
                continue;
            }
            validCodes.push_back(coupon.code);
        }
        return validCodes;
    }

    bool isValidCoupon(const Coupon& coupon) {
        return isValidCode(coupon.code) && isValidCategory(coupon.businessLine) && coupon.isActive;
    }

    bool isValidCode(const string& code) {
        if (code.empty()) return false;
        for (char c : code) {
            if (!isValidChar(c)) return false;
        }
        return true;
    }

    bool isValidChar(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_';
    }

    bool isValidCategory(const string& category) {
        return validCategories.find(category) != validCategories.end();
    }


public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<Coupon> coupons = packCoupons(code, businessLine, isActive);
        sort(coupons.begin(), coupons.end(), [](const Coupon& a, const Coupon& b) {
            if (a.businessLine == b.businessLine) {
                return a.code < b.code;
            }
            return a.businessLine < b.businessLine;
        });
        return extractValidCouponCodes(coupons);
    }
};