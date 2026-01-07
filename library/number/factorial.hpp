#pragma once
long long factorial(int N) {
    long long res = 1;
    while (N > 0) res *= N--;
    return res;
}