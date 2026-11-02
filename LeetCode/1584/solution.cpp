#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int answer = 0;
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visit(n, false);
        minDist[0] = 0;

        for (int i = 0;i < n; i++){
            int u = -1;
            for(int j = 0; j < n; j++){
                if(!(visit[j]) && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visit[u] = true;
            answer += minDist[u];

            for (int j = 0; j < n; j++){
                if(!(visit[j])){
                    int d = abs(points[u][0] - points[j][0]) + abs(points[u][1] - points[j][1]);
                    minDist[j] = min(minDist[j], d);
                }
            }
        }

        return answer;
    }

    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    int kruskal(vector<vector<int>>& points){
        int answer = 0;
        int n = points.size();

        vector<array<int , 3>> v;
        for (int i = 0;i < n; i++){
            for(int j = i + 1; j < n; j++){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back({d, i, j});
            }
        }

        sort(v.begin(),v.end());

        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        int cnt = 0;
        for (auto& v1 : v){
            int ra = find(v1[1]), rb = find (v1[2]);
            if( ra != rb){
                parent[ra] = rb;
                answer += v1[0];
                if(++cnt == n - 1){
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    vector<vector<int>> b = {{3, 12}, {-2, 5}, {-4, 1}};
    vector<vector<int>> c = {{0, 0}};
    cout << s.minCostConnectPoints(a) << " (expected 20)" << '\n';
    cout << s.minCostConnectPoints(b) << " (expected 18)" << '\n';
    cout << s.minCostConnectPoints(c) << " (expected 0, 점이 1개)" << "\n";
    cout << "\n";
    cout << s.kruskal(a) << " (expected 20)" << '\n';
    cout << s.kruskal(b) << " (expected 18)" << '\n';
    cout << s.kruskal(c) << " (expected 0, 점이 1개)" << "\n";
    return 0;
}
