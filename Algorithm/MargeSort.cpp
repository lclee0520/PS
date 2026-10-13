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

void merge(int h, int m, const vector<int>& U, const vector<int>& V, vector<int>& S) {
    int i = 0, j = 0, k = 0;
    while (i < h && j < m) {                       // 둘 다 남아 있는 동안
        if (U[i] < V[j]) S[k++] = U[i++];          // 작은 쪽을 S에 씀
        else             S[k++] = V[j++];
    }
    while (i < h) S[k++] = U[i++];                 // U 나머지
    while (j < m) S[k++] = V[j++];                 // V 나머지
}

void mergesort(int n, vector<int>& S) {
    if (n > 1) {
        int h = n / 2, m = n - h;                  // 앞 절반 h개 뒤 절반 m개
        vector<int> U(S.begin(), S.begin() + h);   // S 앞 절반을 U로 복사
        vector<int> V(S.begin() + h, S.end());     // S 뒤 절반을 V로 복사
        mergesort(h, U);                           // U 정렬
        mergesort(m, V);                           // V 정렬
        merge(h, m, U, V, S);                      // 둘을 합쳐 S에 덮어씀
    }
}