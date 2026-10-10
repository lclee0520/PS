#include <bits/stdc++.h>
using namespace std;
vector<int> S;                                    // 정렬 대상은 전역 하나

void merge2(int low, int mid, int high) {
    vector<int> U(high - low + 1);
    int i = low, j = mid + 1;
    for (int k = 0; k <= high - low; k++) {                  // U를 정확히 high-low+1칸 채움
        if (j > high || (i <= mid && S[i] < S[j])) {
            U[k] = S[i++];   // 왼쪽에서 가져옴
        }
        else {
            U[k] = S[j++];   // 오른쪽에서 가져옴
        }
    }
    for (int t = 0; t <= high - low; t++) {
        S[low + t] = U[t];  // U를 S로 되돌림
    }
}                                              // 함수가 끝나면 U는 해제

void mergesort2(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid);                     // 복사 없이 구간만 넘김
        mergesort2(mid + 1, high);
        merge2(low, mid, high);                   // 재귀가 다 끝난 뒤에 U 생성
    }
}

int main(){
    ;
}