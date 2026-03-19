class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (const auto& a : tasks) {
            counts[a]++;
        }

        priority_queue<pair<int, char>> pq;
        for (const auto& a : counts) {
            pq.push({a.second, a.first});
        }

        int result = 0;
        while (!pq.empty())
        {
            vector<pair<int, char>> v;
            int cycle = n + 1, doTaskCount = 0;
            while (!pq.empty() && 0 < cycle--)
            {
                pair<int, char> cur = pq.top();
                pq.pop();
                if (0 < cur.first - 1) {
                    v.push_back({cur.first - 1, cur.second});
                }
                doTaskCount++;
            }

            for (const auto& a : v) {
                pq.push(a);
            }
            result += (!pq.empty()) ? n + 1 : doTaskCount;
        }
        return result;
    }
};