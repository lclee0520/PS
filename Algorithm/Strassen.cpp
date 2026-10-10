#include <bits/stdc++.h>
using namespace std;
using Mat = vector<vector<long long>>;

const int THRESHOLD = 64;                         // 이 크기 이하는 표준 곱셈

Mat newMat(int n) { return Mat(n, vector<long long>(n, 0)); }

Mat add(const Mat& A, const Mat& B) {             // A + B : n^2
    int n = A.size(); Mat C = newMat(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
    return C;
}
Mat sub(const Mat& A, const Mat& B) {             // A - B : n^2
    int n = A.size(); Mat C = newMat(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = A[i][j] - B[i][j];
    return C;
}

Mat standard(const Mat& A, const Mat& B) {        // 표준 곱셈 : n^3
    int n = A.size(); Mat C = newMat(n);
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Mat strassen(const Mat& A, const Mat& B) {
    int n = A.size();
    if (n <= THRESHOLD) return standard(A, B);    // 작은 블록은 표준이 더 빠름

    int h = n / 2;                                // 1. Divide: 4개 블록으로 나눔
    Mat A11 = newMat(h), A12 = newMat(h), A21 = newMat(h), A22 = newMat(h);
    Mat B11 = newMat(h), B12 = newMat(h), B21 = newMat(h), B22 = newMat(h);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++) {
            A11[i][j] = A[i][j];     A12[i][j] = A[i][j + h];
            A21[i][j] = A[i + h][j]; A22[i][j] = A[i + h][j + h];
            B11[i][j] = B[i][j];     B12[i][j] = B[i][j + h];
            B21[i][j] = B[i + h][j]; B22[i][j] = B[i + h][j + h];
        }

    // 2. Conquer: 블록 곱셈 7번 (각각 재귀)
    Mat M1 = strassen(add(A11, A22), add(B11, B22));
    Mat M2 = strassen(add(A21, A22), B11);
    Mat M3 = strassen(A11, sub(B12, B22));
    Mat M4 = strassen(A22, sub(B21, B11));
    Mat M5 = strassen(add(A11, A12), B22);
    Mat M6 = strassen(sub(A21, A11), add(B11, B12));
    Mat M7 = strassen(sub(A12, A22), add(B21, B22));

    // 3. Combine: 블록 덧셈/뺄셈으로 C 조립
    Mat C11 = add(sub(add(M1, M4), M5), M7);
    Mat C12 = add(M3, M5);
    Mat C21 = add(M2, M4);
    Mat C22 = add(add(sub(M1, M2), M3), M6);

    Mat C = newMat(n);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++) {
            C[i][j] = C11[i][j];     C[i][j + h] = C12[i][j];
            C[i + h][j] = C21[i][j]; C[i + h][j + h] = C22[i][j];
        }
    return C;
}