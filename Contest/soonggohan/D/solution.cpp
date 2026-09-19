#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;

    for (int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        if(s[l - 1] == 'T' || s[r - 1] == 'M'){
            cout << "NO" << '\n';
        }else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}