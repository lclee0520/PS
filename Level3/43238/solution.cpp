#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long low = 1, high = (long long)n * (*min_element(times.begin(), times.end()));
    long long answer = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long num = 0;
        for (auto t : times) {
            num += mid / t;
        }

        if (num >= n) {
            answer = mid;      
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    cout << solution(6, {7, 10}) << " (expected 28)" << endl;
    return 0;
}
