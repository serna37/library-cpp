#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"
#include "template/template.hpp"
#include "library/search/bi_ge_cnt.hpp"
#include "library/search/bi_gt_cnt.hpp"
#include "library/search/bi_le_cnt.hpp"
#include "library/search/bi_lt_cnt.hpp"
/**
 * @brief 二分探索 要素数のテスト
 */
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    int ans = 0;
    while (Q--) {
        int x;
        cin >> x;
        // 以上の数 - より大きい数
        int cnt_ge = bi_ge_cnt(A, x);
        int cnt_gt = bi_gt_cnt(A, x);
        int match_cnt = cnt_ge - cnt_gt;
        if (0 < match_cnt) ++ans;
        // 以下の数 - より小さい数
        int cnt_le = bi_le_cnt(A, x);
        int cnt_lt = bi_lt_cnt(A, x);
        int match_cnt2 = cnt_le - cnt_lt;
        assert(match_cnt == match_cnt2);
    }
    print(ans);
}
