#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer;

    vector<vector<int>> v(triangle.size());
    v[0] = {triangle[0][0]};
    for(int i = 1; i < triangle.size(); i++){
        v[i].resize(triangle[i].size());
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0){
                v[i][j] = v[i - 1][j] + triangle[i][j];
            } else if(i == j){
                v[i][j] = v[i - 1][j - 1] + triangle[i][j];
            } else{
                v[i][j] = max(v[i - 1][j], v[i - 1][j - 1]) + triangle[i][j];
            }
        }
    }

    answer = *max_element(v[triangle.size() - 1].begin(),v[triangle.size() - 1].end());

    return answer;
}

int main() {
    cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << " (expected 30)" << endl;
    return 0;
}
