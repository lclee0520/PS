long long solution(int a, int b) {
    long long min = a < b ? a : b;
    long long max = a > b ? a : b;
    return (min + max) * (max - min + 1) / 2;
}
