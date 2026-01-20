#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>
using namespace std;
#include "template/debug.hpp"
/**
 * @brief debugのテスト
 */
int main() {
    cout << "Hello World" << endl;
    int a = 1ll;
    char c = 'c';
    string S = "sss";
    pair<int, string> p = {a, S};
    tuple<int, char, string> t = {a, c, S};
    vector<int> A = {a};
    vector<vector<string>> G = {{S, S}, {S, S}};
    debug(a);
    debug(c);
    debug(S);
    debug(p);
    debug(t);
    debug(A);
    debug(G);
}
