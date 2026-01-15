#pragma once
map<int, int> prime_fact(int N) {
    map<int, int> P;
    for (int i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            ++P[i];
            N /= i;
        }
    }
    if (N > 1) ++P[N];
    return P;
}
