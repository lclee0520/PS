#include <bits/stdc++.h>
using namespace std;

long long calls = 0;
long long bin(int n, int k) {                          // 분할정복 버전
    calls++;
    if (k == 0 || k == n) return 1;
    return bin(n - 1, k - 1) + bin(n - 1, k);
}

long long bin2(int n, int k) {                         // 동적계획 2차원 버전
    vector<vector<long long>> B(n + 1, vector<long long>(k + 1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i) B[i][j] = 1;
            else B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
    return B[n][k];
}

long long bin3(int n, int k) {                         // 1차원 + 대칭 개선 버전
    if (k > n - k) k = n - k;                          // C(n,k) = C(n,n-k)
    vector<long long> B(k + 1, 0);
    for (int i = 0; i <= n; i++)
        for (int j = min(i, k); j >= 0; j--)           // 큰 쪽부터
            B[j] = (j == 0 || j == i) ? 1 : B[j - 1] + B[j];
    return B[k];
}

int main() {
    printf("C(4,2): bin=%lld bin2=%lld bin3=%lld\n", bin(4, 2), bin2(4, 2), bin3(4, 2));
    printf("bin(4,2) calls=%lld (2*C-1=%lld)\n", calls, 2 * bin2(4, 2) - 1);

    for (int n : {20, 25, 30}) {
        int k = n / 2;
        calls = 0;
        auto t0 = chrono::steady_clock::now();
        long long a = bin(n, k);
        auto t1 = chrono::steady_clock::now();
        printf("n=%d k=%d value=%lld same=%d calls=%lld recursive %.1f ms\n",
               n, k, a, a == bin2(n, k) && a == bin3(n, k), calls,
               chrono::duration<double, milli>(t1 - t0).count());
    }
    printf("C(60,30)=%lld\n", bin3(60, 30));
}