#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233"
#include "template/template.hpp"
#include "library/number/base_convert.hpp"
/**
 * @brief 進数変換のテスト
 */
void solve() {
    while (1) {
        int x;
        cin >> x;
        if (x == 0) break;
        vector<int> cvt = base_convert(x, -10);
        for (auto &&v : cvt) {
            cout << v;
        }
        cout << endl;
    }
}
