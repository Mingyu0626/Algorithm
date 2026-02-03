#include <bits/stdc++.h>

using namespace std;
using pdd = pair<double, double>;
using pdi = pair<double, int>;

int n;
pdd start, dest;
vector<pdd> cannons;
vector<vector<double>> minTimesFromAtoB;
vector<double> minTimesFromStart;

void receiveInput();
void setTimesFromAtoB();
double getDist(const pdd& p1, const pdd& p2);
double getShortestTime(const double& dist, const bool& isCannon);
void dijkstra();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cout << fixed; cout.precision(6);
    receiveInput();
    setTimesFromAtoB();
    dijkstra();
    cout << minTimesFromStart[n + 1];
}

void receiveInput() {
    cin >> start.first >> start.second >> dest.first >> dest.second >> n;
    cannons.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> cannons[i].first >> cannons[i].second;
    }
}

void setTimesFromAtoB() {
    minTimesFromAtoB.assign(n + 2, vector<double>(n + 2, 0));

    double distFromStartToDest = getDist(start, dest);
    minTimesFromAtoB[0][n + 1] = minTimesFromAtoB[n + 1][0] 
        = getShortestTime(distFromStartToDest, false);

    for (int i = 0; i < n; ++i) {
        double distFromStartToCannon = getDist(start, cannons[i]);
        minTimesFromAtoB[0][i + 1] = minTimesFromAtoB[i + 1][0] 
            = getShortestTime(distFromStartToCannon, false);
    }

    for (int i = 0; i < n; ++i) {
        double distFromCannonToDest = getDist(cannons[i], dest);
        minTimesFromAtoB[i + 1][n + 1] = minTimesFromAtoB[n + 1][i + 1] 
            = getShortestTime(distFromCannonToDest, true);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distFromCannonToCannon = getDist(cannons[i], cannons[j]);
            minTimesFromAtoB[i + 1][j + 1] = minTimesFromAtoB[j + 1][i + 1] 
                = getShortestTime(distFromCannonToCannon, true);
        }
    }
}

double getDist(const pdd& p1, const pdd& p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double getShortestTime(const double& dist, const bool& isCannon) {
    return (isCannon) ? min(dist / 5, 2 + fabs(dist - 50) / 5) : dist / 5;
}

void dijkstra() {
    priority_queue<pdi> pq;
    pq.push({ 0, 0 });
    minTimesFromStart.assign(n + 2, 1e9);
    minTimesFromStart[0] = 0;
    while (!pq.empty()) {
        double curTime = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (minTimesFromStart[curNode] < curTime) {
            continue;
        }

        for (int newNode = 0; newNode < n + 2; ++newNode) {
            if (curNode == newNode) {
                continue;
            }

            double newTime = curTime + minTimesFromAtoB[curNode][newNode];
            if (newTime < minTimesFromStart[newNode]) {
                pq.push({ -newTime, newNode });
                minTimesFromStart[newNode] = newTime;
            }
        }
    }
}