#pragma once
int digit_sum(int N, int base_number = 10) {
    int res = 0;
    while (N != 0) {
        res += N % base_number;
        N /= base_number;
    }
    return res;
}