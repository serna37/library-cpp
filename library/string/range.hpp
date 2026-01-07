#pragma once
string range(const string &S, int A, int B) {
    if (A > B or A >= (int)S.size()) return "";
    return S.substr(A, B - A + 1);
}
