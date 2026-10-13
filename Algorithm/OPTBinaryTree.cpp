#include <bits/stdc++.h>
using namespace std;

struct Node {
    string key;
    Node* left;
    Node* right;
};

int n;
vector<string> key;              // key[1..n]
vector<double> p;                // p[1..n]
vector<vector<double>> A;        // A[1..n+1][0..n]
vector<vector<int>> R;           // R[1..n+1][0..n]

void optsearchtree() {
    A.assign(n + 2, vector<double>(n + 1, 0));
    R.assign(n + 2, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        A[i][i - 1] = 0; A[i][i] = p[i];          // 빈 트리와 키 하나짜리 트리
        R[i][i - 1] = 0; R[i][i] = i;
    }
    A[n + 1][n] = 0; R[n + 1][n] = 0;              // k = n일 때 오른쪽 빈 트리

    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i + diagonal <= n; i++) {
            int j = i + diagonal;
            double sum = 0;
            for (int m = i; m <= j; m++) sum += p[m];   // p_i + ... + p_j

            A[i][j] = DBL_MAX;
            for (int k = i; k <= j; k++) {              // k를 루트로 시도
                double cost = A[i][k - 1] + A[k + 1][j];
                if (cost < A[i][j]) { 
                    A[i][j] = cost;
                    R[i][j] = k; 
                }
            }
            A[i][j] += sum;                             // 확률 합은 min 밖에서 더함
        }
}

Node* tree(int i, int j) {                         // R로 실제 트리 구성
    int k = R[i][j];
    if (k == 0) return nullptr;                    // 빈 트리
    Node* p = new Node{key[k], nullptr, nullptr};
    p->left  = tree(i, k - 1);
    p->right = tree(k + 1, j);
    return p;
}

void print(Node* t, int depth) {                   // 오른쪽이 위로 오게 옆으로 출력
    if (!t) return;
    print(t->right, depth + 1);
    cout << string(depth * 6, ' ') << t->key << "\n";
    print(t->left, depth + 1);
}

int main() {
    n = 4;
    key = {"", "Don", "Isabelle", "Ralph", "Wally"};
    p   = {0, 3.0 / 8, 3.0 / 8, 1.0 / 8, 1.0 / 8};

    optsearchtree();

    cout << "A (x8)\n";
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++)
            if (j >= i - 1) printf("%5.0f", A[i][j] * 8); else printf("%5s", "");
        cout << "\n";
    }
    cout << "R\n";
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++)
            if (j >= i - 1) printf("%5d", R[i][j]); else printf("%5s", "");
        cout << "\n";
    }
    printf("minavg = %.4f (= %.0f/8)\n", A[1][n], A[1][n] * 8);
    cout << "tree\n";
    print(tree(1, n), 0);
}