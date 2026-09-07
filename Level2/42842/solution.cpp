#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for(int hight = 1;hight * hight <= total ;hight++){
        if (total % hight != 0){
            continue;
        } else{
            int wide = total / hight;
            if(2 * (hight + wide) - 4 == brown){
                answer = {wide,hight};
                return answer;
            }
        }

    }
    return answer;
}

int main() {
    auto p = [](vector<int> v){ cout << "[" << v[0] << ", " << v[1] << "]\n"; };
    p(solution(10, 2));   // expected [4, 3]
    p(solution(8, 1));    // expected [3, 3]
    p(solution(24, 24));  // expected [8, 6]
    return 0;
}
