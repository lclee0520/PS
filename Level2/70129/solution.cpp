#include <bits/stdc++.h>
using namespace std;

string toBinary(int n) {
    string result = "";
    while (n > 0) {
        result += ('0' + n % 2); // 아스키 코드 더하기
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    int count_while = 0;
    int count_0 = 0;

    while (s != "1") {
        count_0 += count(s.begin(), s.end(), '0');
        int count_1 = count(s.begin(), s.end(), '1');
        s = toBinary(count_1);
        count_while++;
    }

    return {count_while, count_0};
}

int main(){
    string s = "110010101001";
    vector<int> result = solution(s);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
}
