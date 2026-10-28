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
};

int main() {
    Solution s;
    vector<vector<int>> a = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    vector<vector<int>> b = {{3, 12}, {-2, 5}, {-4, 1}};
    vector<vector<int>> c = {{0, 0}};
    cout << s.minCostConnectPoints(a) << " (expected 20)" << endl;
    cout << s.minCostConnectPoints(b) << " (expected 18)" << endl;
    cout << s.minCostConnectPoints(c) << " (expected 0, 점이 1개)" << endl;
    return 0;
}
