#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if(s[0] <= 'z' && s[0] >= 'a'){
        answer += toupper(s[0]);
    } else {
        answer += s[0];
    }

    for(int i = 1;i<s.length() ;i++){
        if(s[i] == ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z'){
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
