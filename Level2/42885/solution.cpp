#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int low = 0, high = people.size() - 1;
    sort(people.begin(), people.end());

    while (low <= high){
        int sum = people[low] + people[high];
        if(sum > limit){
            high--;
            answer++;
        }else if (sum <= limit){
            answer++;
            low++;
            high--;
        }
    }

    return answer;
}

int main() {
    cout << solution({70, 50, 80, 50}, 100) << " (expected 3)" << endl;
    cout << solution({70, 80, 50}, 100) << " (expected 3)" << endl;
    cout << solution({40, 40, 40}, 100) << " (expected 2)" << endl;
    return 0;
}
