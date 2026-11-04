#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // 1) 인접 리스트: 무방향이라 양쪽에 다 넣음
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});
        }

        // 2) prob[i] = start_node에서 i까지의 최대 확률
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        // 3) 최대 힙 {확률, 정점}: 확률이 가장 큰 정점이 먼저 나옴
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node}); // {가중치 , 현재 위치한 노드}

        while (!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();

            if (u == end_node) return p;       // 도착점이 처음 나오면 그게 최대 확률
            if (p < prob[u]) continue;         // 이미 더 좋은 확률로 처리된 낡은 항목은 건너뜀

            // 4) u를 거쳐 가는 경로로 이웃 v의 확률을 갱신
            for (auto& [v, w] : adj[u]) {
                double np = p * w;             // 합이 아니라 곱
                if (np > prob[v]) {            // 더 크면 갱신하고 힙에 넣음
                    prob[v] = np;
                    pq.push({np, v});
                }
            }
        }
        return 0.0;                            // 도착점에 못 가면 0
    }
};

int main() {
    Solution s;
    vector<vector<int>> e1 = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> p1 = {0.5, 0.5, 0.2};
    vector<double> p2 = {0.5, 0.5, 0.3};
    vector<vector<int>> e3 = {{0, 1}};
    vector<double> p3 = {0.5};
    cout << fixed << setprecision(5);
    cout << s.maxProbability(3, e1, p1, 0, 2) << " (expected 0.25000)" << '\n';
    cout << s.maxProbability(3, e1, p2, 0, 2) << " (expected 0.30000)" << '\n';
    cout << s.maxProbability(3, e3, p3, 0, 2) << " (expected 0.00000)" << '\n';
    return 0;
}
