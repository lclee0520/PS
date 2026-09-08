#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> cnt;
    for (int i:tangerine){
        cnt[i]++;
    }

    vector<int> v;
    for(auto& i:cnt){
        v.push_back(i.second);
    }

    sort(v.begin(), v.end(), greater<int>());

    int sum = 0;
    for(int i: v){
        sum += i;
        answer++;
        if(sum >= k){
            break;
        }
    }

    return answer;
}

int main() {
    cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << " (expected 3)" << endl;
    cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << " (expected 2)" << endl;
    cout << solution(2, {1, 1, 1, 1, 2, 2, 2, 3}) << " (expected 1)" << endl;
    return 0;
}
