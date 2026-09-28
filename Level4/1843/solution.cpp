#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> arr) {
    vector<int> num;
    vector<string> ops;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == "+"){
            num.push_back(stoi(arr[++i]));
            ops.push_back("+");
        } else if (arr[i] == "-"){
            num.push_back(stoi(arr[++i]));
            ops.push_back("-");
        } else {
            num.push_back(stoi(arr[i]));
        }
    }

    int n = num.size();
    vector<vector<int>> mx(n, vector<int>(n, INT_MIN));
    vector<vector<int>> mn(n, vector<int>(n, INT_MAX));

    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                mx[i][j] = num[i];
                mn[i][j] = num[i];
            } else {
                for(int k = i; k < j; k++){
                    int a = mx[i][k], b = mn[i][k];
                    int c = mx[k+1][j], d = mn[k+1][j];

                    if(ops[k] == "+"){
                        mx[i][j] = max({mx[i][j], a + c, a + d, b + c, b + d});
                        mn[i][j] = min({mn[i][j], a + c, a + d, b + c, b + d});
                    } else {
                        mx[i][j] = max({mx[i][j], a - c, a - d, b - c, b - d});
                        mn[i][j] = min({mn[i][j], a - c, a - d, b - c, b - d});
                    }
                }
            
            }
        }
    }
    return mx[0][n-1];
}

int main() {
    cout << solution({"1", "-", "3", "+", "5", "-", "8"}) << " (expect 1)" << endl;
    cout << solution({"5", "-", "3", "+", "1", "+", "2", "-", "4"}) << " (expect 3)" << endl;
    return 0;
}
