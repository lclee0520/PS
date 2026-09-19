#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int times = 0;
    string s;
    cin >> times;

    for (int q = 0;q < times; q++){    
        vector<int> v;
        cin >> s;
        v.push_back(1);
        for(int i = 0;i < s.size(); i++){
            if(s[i] == 'O'){
                v.push_back(0);
            }else if (s[i] == 'I'){
                v.push_back(1);
            }
        }

        long long sum = 0;
        long long squ = 1;

        for (int i = v.size() - 1;i >= 0; i--){
            sum += squ * v[i];
            squ *= 2;
        }
        cout << sum << '\n';
    }

    return 0;
}