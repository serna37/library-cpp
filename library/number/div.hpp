#pragma once
long long div_ceil(long long a, long long b) { // 負の場合0側へ丸めない
    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
}
long long div_floor(long long a, long long b) { // 負の場合0側へ丸めない
    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
}
