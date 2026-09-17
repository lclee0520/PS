#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int count_times = n, count_turns = 1;
    vector<string> s;

    for (int i = 0; i < (int)words.size(); i++) {
        count_times--;
        int person = n - count_times;
        
        if (i != 0) {
            if (words[i - 1].back() != words[i].front()) {
                return {person, count_turns};
            }
        }

        if (find(s.begin(), s.end(), words[i]) != s.end()) {
            return {person, count_turns};
        }
        s.push_back(words[i]);

        if (count_times == 0) {
            count_times = n;
            count_turns++;
        }
    }

    return {0, 0};
}

int main() {
    auto p = [](vector<int> v){ cout << "[" << v[0] << ", " << v[1] << "]\n"; };
    p(solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})); // expected [3, 3]
    p(solution(2, {"hello", "one", "even", "never", "now", "world", "draw"}));                     // expected [1, 3]
    return 0;
}
