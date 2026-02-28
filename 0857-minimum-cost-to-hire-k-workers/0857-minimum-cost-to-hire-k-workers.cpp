class Solution {
using pii = pair<int, int>;
private:
    int n;
    vector<pii> v; // {quality, wage}
    priority_queue<int, vector<int>, less<int>> pq;
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        n = quality.size();
        for (int i = 0; i < n; ++i) {
            v.emplace_back(quality[i], wage[i]);
        }
        sort(v.begin(), v.end(), compare);

        double result = DBL_MAX, ratio;
        int qSum = 0;
        for (int i = 0; i < n; ++i) {
            int curQ = v[i].first, curW = v[i].second;
            ratio = (double)curW / curQ;
            pq.push(curQ);
            qSum += curQ;

            if (k < pq.size()) {
                int lowestQ = pq.top();
                pq.pop();
                qSum -= lowestQ;
            }
            result = (k <= i + 1) ? min(result, qSum * ratio) : DBL_MAX;
        }
        return result;
    }
    static bool compare(const pii& a, const pii& b) {
        return (double)a.second / a.first < (double)b.second / b.first;  
    }
};