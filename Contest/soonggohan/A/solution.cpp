#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int times = 0;
    cin >> times;

    for(int i = 0;i < times;i++){
        int temp;
        cin >> temp;
        cout << 3 * temp * temp << '\n';
    }

    return 0;
}