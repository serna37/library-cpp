#pragma once
string base_convert(const string &S, int from, int to) {
    long long base_10_number = 0ll;
    for (auto &&v : S) base_10_number = base_10_number * from + (int)(v - '0');
    if (base_10_number == 0) return "0";
    string res = "";
    while (base_10_number) {
        res = (char)(base_10_number % to + '0') + res;
        base_10_number /= to;
    }
    return res;
}