#include <bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    int count_metch = 0;

    while (true){
        if (a == b){
            return count_metch;
        }

        a = (a + 1) / 2;
        b = (b + 1) / 2;
        count_metch++; 
    }

    return answer;
}

int main() {
    cout << solution(8, 4, 7) << " (expected 3)" << endl;
    return 0;
}
