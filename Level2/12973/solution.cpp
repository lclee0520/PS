#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    vector<char> v;

    for (char c : s) {
        if (!v.empty() && v.back() == c)
            v.pop_back();
        else
            v.push_back(c);
    }

    return v.empty() ? 1 : 0;
}

int main() {
    cout << solution("baabaa") << " (expected 1)" << endl;
    cout << solution("cdcd") << " (expected 0)" << endl;
    cout << solution("aa") << " (expected 1)" << endl;
    cout << solution("abba") << " (expected 1)" << endl;
    return 0;
}
