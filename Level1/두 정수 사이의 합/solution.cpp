#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    long long min_val = min(a, b);
    long long max_val = max(a, b);
    return (min_val + max_val) * (max_val - min_val + 1) / 2;
}
