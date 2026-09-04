#include <bits/stdc++.h>
using namespace std;



int solution(int n) {
    const int MOD = 1234567;
    vector<long long> v(n);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < n; i++)
        v[i] = (v[i - 1] + v[i - 2]) % MOD;
    return (int)v[n - 1];
}

int main() {
    cout << solution(3) << " (expected 2)" << endl;
    cout << solution(5) << " (expected 5)" << endl;
    return 0;
}
