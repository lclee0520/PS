#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> s;

    vector<int> arr = elements; // 원형 수열 → 길이 2n으로 이어붙이기
    arr.insert(arr.end(), elements.begin(), elements.end());

    for (int len = 1; len <= n; len++) {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += arr[i];// 시작점 0에서의 첫 윈도우 합
        }
        s.insert(sum);

        for (int i = 1; i < n; i++) {// 시작점 1..n-1 으로 슬라이딩
            sum += arr[i + len - 1] - arr[i - 1];
            s.insert(sum);
        }
    }
    return s.size();
}

int main() {
    cout << solution({7, 9, 1, 1, 4}) << " (expected 18)" << endl;
    return 0;
}
