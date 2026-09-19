#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        v[i] = i + 1;
    }
    int pin = 0;
    for (int w = 0; w < q; w++){
        int rank, num;
        cin >> rank >> num;
        if(rank == 1){
            pin = (pin - num + n) % n;
        }else if (rank == 2){
            pin = (pin + num) % n;
        } else if (rank == 3){
            cout << v[(pin + num - 1) % n] << '\n';
        }
    }

    return 0;
}