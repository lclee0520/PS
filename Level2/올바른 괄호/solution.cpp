#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<char> v;
    for(int i=0;i < s.length();i++){
        if(v.empty() && (s[i] == '{' || s[i] == '(')){
            v.push_back(s[i]);
            continue;
        } else if (v.empty() && (s[i] == '}' || s[i] == ')')){
            return false;
        }
        if(s[i] == '{' || s[i] == '('){
            v.push_back(s[i]);
        } else if (s[i] == '}'){
            if(v.back() == '{'){
                v.pop_back();
                continue;
            } else {
                return false;
            }
        } else if (s[i] == ')'){
            if(v.back() == '('){
                v.pop_back();
                continue;
            } else {
                return false;
            }
        }
    }
    if(v.empty()){
        return answer;
    }

    return false;
}
