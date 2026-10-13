#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n = 4;
int W[5][5] = {
    {0, 0,   0,   0,   0},
    {0, 0,   2,   9,   INF},
    {0, 1,   0,   6,   4},
    {0, INF, 7,   0,   8},
    {0, 6,   3,   INF, 0}};

int memo[5][32];      // memo[i][A] = D[vi][A], -1이면 아직 안 구함
int nxt[5][32];       // 경로 복원용 (슬라이드의 P)

// D[vi][A] : vi에서 출발해서 A에 있는 도시를 전부 들르고 v1로 가는 최단 거리
int D(int i, int A) {
    if (A == 0) return W[i][1];                    // 남은 도시 없음 -> 바로 v1로
    if (memo[i][A] != -1) return memo[i][A];       // 이미 구했으면 재사용

    int best = INF;
    for (int j = 2; j <= n; j++) {
        if (!(A & (1 << j))) continue;             // vj가 A에 없으면 건너뜀
        if (W[i][j] == INF) continue;              // 길이 없으면 건너뜀
        int rest = D(j, A & ~(1 << j));            // vj로 가고 A에서 vj를 뺀다
        if (rest == INF) continue;
        if (W[i][j] + rest < best) {
            best = W[i][j] + rest;
            nxt[i][A] = j;
        }
    }
    return memo[i][A] = best;
}

int main() {
    memset(memo, -1, sizeof(memo));
    int all = (1 << 2) | (1 << 3) | (1 << 4);      // {v2, v3, v4}
    printf("minlength = %d\n", D(1, all));

    printf("tour: v1");
    int i = 1, A = all;
    while (A != 0) {
        int j = nxt[i][A];
        printf(" -> v%d", j);
        A = A & ~(1 << j);
        i = j;
    }
    printf(" -> v1\n");
}