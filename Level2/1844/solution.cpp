#include <bits/stdc++.h>
using namespace std;
int count_total = 0;

int bfs(int start, vector<vector<int>> maps, vector<vector<bool>> visit){
    queue<pair<int, int>> q;
    int n = maps.size(), m = maps[0].size();
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    q.push({0, 0});
    visit[0][0] = true;

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = row + dr[d], nc = col + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            if (maps[nr][nc] == 0) {
                continue;
            }
            if (visit[nr][nc]) {
                continue;
            }

            visit[nr][nc] = true;
            maps[nr][nc] = maps[row][col] + 1;
            q.push({nr, nc});
        }
    }

    return maps[n - 1][m - 1];
}

int solution(vector<vector<int>> maps) {
    int answer = -1;
    vector<vector<bool>> visit(maps.size());
    for(int i = 0; i < maps.size(); i++){
        visit[i].resize(maps[i].size());
    }
    answer = bfs(maps[0][0], maps, visit);

    if(answer == 1){
        return -1;
    }

    return answer;
}

int main() {
    cout << solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}}) << " (expected 11)" << endl;
    cout << solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}}) << " (expected -1)" << endl;
    return 0;
}
