#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    int left = 1, right = 1;
    int sum = 1;

    while (left <= n) {
        if (sum == n) {
            answer++;
            sum -= left++;
        } else if (sum < n) {
            sum += ++right;
        } else {
            sum -= left++;
        }
    }
    return answer;
}

int main() {
    cout << solution(15) << " (expected 4)" << endl;
    cout << solution(1) << " (expected 1)" << endl;
    cout << solution(6) << " (expected 2)" << endl;      // 6, 1+2+3
    cout << solution(15000) << " (expected 10)" << endl; // odd divisors of 15000
    return 0;
}
