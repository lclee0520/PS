#include <bits/stdc++.h>
using namespace std;

int toBeat(int n){
    string s = "";
    while (n > 0){
        s += '0' + n%2;
        n /= 2;
    }
    cout << s <<'\n';
    return count(s.begin(),s.end(), '1');
}

int solution(int n) {
    int answer = 0;
    int number = toBeat(n);
    int count_1 = n + 1;
    while (answer != number){
        answer = toBeat(count_1);
        count_1++;
    }
    

    return --count_1;
}

int main() {
    cout << solution(78) << " (expected 83)" << endl;
    cout << solution(15) << " (expected 23)" << endl;
    return 0;
}
