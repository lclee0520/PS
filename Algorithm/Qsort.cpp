#include <bits/stdc++.h>
using namespace std;

vector<int> S;                                     // 1-indexed 전역 배열

void partition(int low, int high, int& pivotpoint) {
    int pivotitem = S[low];                        // 첫 원소를 pivot으로
    int j = low;                                   // j: pivot보다 작은 구간의 끝
    for (int i = low + 1; i <= high; i++) {
        if (S[i] < pivotitem) {                    // 작은 값 발견
            j++;                                   // 작은 구간 한 칸 확장
            swap(S[i], S[j]);                      // 그 자리로 옮김
        }
    }
    swap(S[low], S[j]);                   // pivot을 경계에 놓음
    pivotpoint = j;                                // pivot의 최종 위치
}

void quicksort(int low, int high) {
    if (high > low) {
        int pivotpoint;
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint - 1);            // pivot 왼쪽
        quicksort(pivotpoint + 1, high);           // pivot 오른쪽
    }
}


// 추가적인 qsort의 n^2방지 보진 말자
// void introsort(int low, int high, int depth) {
//     if (high - low + 1 <= 16) return;               // 작은 구간은 나중에 삽입정렬로 처리
//     if (depth == 0) {                               // 허용 깊이 소진
//         heapsort(low, high);                        // 이 구간만 힙정렬로 O(m lg m) 보장
//         return;
//     }
//     int pivotpoint;
//     partition(low, high, pivotpoint);               // 강의의 partition 그대로
//     introsort(low, pivotpoint - 1, depth - 1);      // 내려갈 때마다 1 감소
//     introsort(pivotpoint + 1, high, depth - 1);
// }

// void mysort(int n) {
//     introsort(1, n, 2 * __lg(n));                   // 시작 시 허용 깊이 설정
//     insertion_sort(1, n);                           // 거의 정렬된 상태라 빠르게 마무리
// }

int main() {
    int n = 8;
    S = {0, 15, 22, 13, 27, 12, 10, 20, 25};       // S[0]은 미사용
    quicksort(1, n);
    for (int i = 1; i <= n; i++) cout << S[i] << ' ';   // 10 12 13 15 20 22 25 27
}