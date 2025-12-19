#pragma once
// 割り下げ（負の場合0側へ丸めない）
auto divCeil = []<class T>(T a, T b) {
    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
};
// 割り上げ（負の場合0側へ丸めない）
auto divFloor = []<class T>(T a, T b) {
    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
};
// TODO 数値系 modとか階乗、素数、約数とか
