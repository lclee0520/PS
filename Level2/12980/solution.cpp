#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    while (n > 0){
        if (n % 2 == 0){
            n /= 2;
            continue;
        } else{
            n--;
            answer++;
        }
    }
    return answer;
}

int main() {
    cout << solution(5) << " (expected 2)" << endl;
    cout << solution(6) << " (expected 2)" << endl;
    cout << solution(2) << " (expected 1)" << endl;
    return 0;
}
