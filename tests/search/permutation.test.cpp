#define PROBLEM "https://atcoder.jp/contests/abc425/tasks/abc425_b"
#include "template/template.hpp"
#include "library/search/permutation.hpp"
/**
 * @brief 順列全探索のテスト
 */
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<int> P(N);
    collection.sequence(P, 1ll);
    bool is_loop_break = permutation(P, [&]() {
        bool alma = collection.all_match(
            P, [&](int v, int i) { return !~A[i] or A[i] == v; });
        if (alma) {
            print("Yes");
            print(P);
        }
        return alma;
    });
    if (!is_loop_break) {
        print("No");
    }
}
