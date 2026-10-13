#include <bits/stdc++.h>
using namespace std;

string order(vector<vector<int>>& pos, int i, int j){
    if(i == j) return string(1, 'A' + i);
    int k = pos[i][j];
    return "(" + order(pos, i, k) + " x " + order(pos, k + 1, j) + ")";
}

int solution(vector<vector<int>> matrix_sizes) {
    int num = matrix_sizes.size();
    vector<vector<int>> v(num, vector<int>(num));
    vector<vector<int>> pos(v);

    for(int i = 0; i < num; i++){
        for(int j = 0;j < num; j++){
            if(i == j){
                continue;
            }else {
                v[i][j] = INT_MAX;
            }
        }
    }

    for (int d = 1; d < num; d++) {
        for (int i = 0; i + d < num; i++) {                 // ① j가 범위 안에
            int j = i + d, min_num = INT_MAX;                // ② 처음엔 무한대
            for (int k = i; k < j; k++) {                    // ③ k는 i부터
                int cost = v[i][k] + v[k + 1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1];  // ④ 곱
                if (cost < min_num) {
                    min_num = cost;                          // ⑤ 최솟값 갱신
                    pos[i][j] = k;
                }
            }
            v[i][j] = min_num;                               // ⑤ 표에 저장
        }
    }

    cout << order(pos, 0, num - 1);
    return v[0][num - 1];
}

int main() {
    cout << solution({{5, 3}, {3, 10}, {10, 6}}) << " (expect 270)" << endl;
    return 0;
}
