#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    // 덱의 원소 (s, w): 고도가 0이 된 마지막 위치가 s인 방법이 w가지. 현재 고도 = x - s.
    deque<pair<int, long long>> dq;
    dq.push_back({0, 1});
    long long sum = 1;

    for (int x = 0; x < n; x++) {
        long long total = sum;  // 이 위치에서 리셋을 선택할 수 있는 모든 방법

        // 고도가 M이 된 상태는 반드시 리셋해야 하므로 리셋 안 한 상태로는 못 남는다
        while (!dq.empty() && x - dq.front().first >= m) {
            sum = (sum - dq.front().second + MOD) % MOD;
            dq.pop_front();
        }
        // 리셋 안 했을 때 고도 x - s 가 h[x] 미만이면 장애물을 못 넘는다
        while (!dq.empty() && x - dq.back().first < h[x]) {
            sum = (sum - dq.back().second + MOD) % MOD;
            dq.pop_back();
        }
        // 리셋하면 고도 0이므로 h[x] == 0 일 때만 가능 (x=0은 이미 고도 0이라 리셋해도 같은 경우)
        if (x > 0 && h[x] == 0) {
            dq.push_back({x, total});
            sum = (sum + total) % MOD;
        }
    }

    cout << sum % MOD << '\n';
    return 0;
}
