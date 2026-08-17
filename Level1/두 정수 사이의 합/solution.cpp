#include <algorithm>

long long solution(int a, int b) {
    long long min_val = std::min(a, b);
    long long max_val = std::max(a, b);
    return (min_val + max_val) * (max_val - min_val + 1) / 2;
}
