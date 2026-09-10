#include <bits/stdc++.h>
using namespace std;
int mod = 1234567;
vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b);

vector<vector<long long>> pow(vector<vector<long long>> m, int n){
    vector<vector<long long>> r = {{1 , 0},{0 , 1}};
    while (n > 0){
        if (n & 1){
            r = mul(r ,m);
        }
        m = mul(m, m);
        n >>= 1;
    }
    return r;
}

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b){
    vector<vector<long long>> c{{0,0},{0,0}};
    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    return c;
}

long long solution(int n) {
    vector<vector<long long>> v = {{1,1},{1,0}};
    return pow(v, n)[0][0];
}

int main() {
    cout << solution(4) << " (expect 5)" << endl;
    cout << solution(3) << " (expect 3)" << endl;
}
