#define PROBLEM "https://yukicoder.me/problems/no/430"
#include "template/template.hpp"
#include "library/string/aho_corasick.hpp"
/**
 * @brief Aho Corasickのテスト
 */
void solve() {
    string S;
    cin >> S;
    int M;
    cin >> M;
    AhoCorasick<26, 'A'> ac;
    for (int i = 0; i < M; ++i) {
        string C;
        cin >> C;
        ac.add(C, i);
    }
    ac.build();
    long long ans = ac.count_all(S);
    print(ans);
}
