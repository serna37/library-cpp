#pragma once
bool prime_test(int N) {
    if (N == 2) return true;
    if (N == 1 or N % 2 == 0) return false;
    for (int i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}
