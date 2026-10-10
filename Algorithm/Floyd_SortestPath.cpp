#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
int W[101][101], D[101][101], P[101][101];

void floyd2() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            P[i][j] = 0;                                  // 처음엔 중간 정점 없음
            D[i][j] = W[i][j];                            // D(0) = W
        }
    for (int k = 1; k <= n; k++)                          // v_k 경유 허용
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (D[i][k] == INF || D[k][j] == INF) continue;   // 오버플로 방지
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;                          // 거쳐간 정점 기록
                }
            }
}

void path(int q, int r) {                                 // q와 r 사이 중간 정점 출력
    if (P[q][r] != 0) {
        path(q, P[q][r]);                                 // 앞 구간
        cout << " v" << P[q][r];                          // 중간 정점
        path(P[q][r], r);                                 // 뒤 구간
    }
}

void printPath(int q, int r) {                            // 시작과 끝까지 포함해서 출력
    if (D[q][r] == INF) { cout << "v" << q << " -> v" << r << " : 경로 없음\n"; return; }
    cout << "v" << q;
    path(q, r);
    cout << " v" << r << "  (길이 " << D[q][r] << ")\n";
}

int main() {
    n = 5;
    int w[6][6] = {
        {0,   0,   0,   0,   0,   0},
        {0,   0,   1, INF,   1,   5},
        {0,   9,   0,   3,   2, INF},
        {0, INF, INF,   0,   4, INF},
        {0, INF, INF,   2,   0,   3},
        {0,   3, INF, INF, INF,   0}};
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) W[i][j] = w[i][j];

    floyd2();
    printPath(5, 3);
    printPath(3, 2);
    printPath(2, 1);
}