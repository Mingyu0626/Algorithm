class Solution {
public:
    string source, target;
    vector<vector<long long>> minCosts;
    vector<vector<pair<int, int>>> edges;

    long long minimumCost(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        initialize(s, t, original, changed, cost);
        updateMinCosts();
        return calculateMinCost();
    }

    void initialize(string s, string t, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        source = s, target = t;
        minCosts.assign(26, vector<long long>(26, LLONG_MAX));
        edges.assign(26, vector<pair<int, int>>());
        for (int i = 0; i < original.size(); ++i) {
            int start = original[i] - 'a', dest = changed[i] - 'a', dist = cost[i];
            edges[start].emplace_back(dist, dest); 
        }
    }

    void updateMinCosts() {
        for (int i = 0; i < 26; ++i) {
            updateMinCost(i);
        }
    }

    void updateMinCost(int start) {
        priority_queue<pair<int, int>> pq;

        minCosts[start][start] = 0;
        for (int i = 0; i < edges[start].size(); ++i) {
            int dist = edges[start][i].first, dest = edges[start][i].second;
            if (dist < minCosts[start][dest]) {
                pq.push({-dist, dest});
                minCosts[start][dest] = dist;
            }
        }

        while (!pq.empty()) {
            int curDist = -pq.top().first, curNode = pq.top().second;
            pq.pop();

            if (minCosts[start][curNode] < curDist) {
                continue;
            }

            for (int i = 0; i < edges[curNode].size(); ++i) {
                int dest = edges[curNode][i].second;
                int nextDist = curDist + edges[curNode][i].first;
                if (nextDist < minCosts[start][dest]) {
                    pq.push({-nextDist, dest});
                    minCosts[start][dest] = nextDist;
                }
            }
        }
    }

    long long calculateMinCost() {
        long long result = 0;
        for (int i = 0; i < source.length(); ++i) {
            int start = source[i] - 'a', dest = target[i] - 'a';
            if (minCosts[start][dest] == LLONG_MAX) {
                return -1;
            }
            result += minCosts[start][dest];
        }
        return result;
    }
};