#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) {
    int start = lcm(arr[0], arr[1]);
    for(int i = 2;i < arr.size() ; i++){
        start = lcm(start, arr[i]);
    }
    return start;
}

int main() {
    vector<int> arr1 = {2, 6, 8, 14};
    cout << solution(arr1) << " (expect 168)" << endl;

    vector<int> arr2 = {1, 2, 3};
    cout << solution(arr2) << " (expect 6)" << endl;
}