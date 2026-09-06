#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>& computers, vector<bool>& visit){
    visit[i] = true;
    for(int next = 0; next < computers.size();next++){
        if(computers[i][next] == 1 && visit[next] == false){
            dfs(next, computers, visit);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);

    for (int i = 0;i < n;i++){
        if(visit[i] == false){
            dfs(i ,computers ,visit);
            answer++;
        }
    }

    return answer;
}

int main() {
    int n1 = 3;
    vector<vector<int>> computers1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << solution(n1, computers1) << " (expect 2)" << endl;

    int n2 = 3;
    vector<vector<int>> computers2 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    cout << solution(n2, computers2) << " (expect 1)" << endl;

    int n3 = 3;
    vector<vector<int>> computers3 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    cout << solution(n3, computers3) << " (expect 1)" << endl;
}
