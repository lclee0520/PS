#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if(s[0] <= 'z' && s[0] >= 'a'){ // 사실 이거 필요없음
        answer += toupper(s[0]);
    } else {
        answer += s[0];
    }

    for(int i = 1;i<s.length() ;i++){
        if(s[i] == ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z'){// 다음꺼 비교하지말고 그냥 toupper바로 하면 알아서 구분됨
            answer += s[i];
            answer += toupper(s[i + 1]);
            i++;
            continue;
        }
        answer += s[i];
    }
    
    return answer;
}

int main(){
    string s = "hello mr my yesterday";
    cout << solution(s);
}
