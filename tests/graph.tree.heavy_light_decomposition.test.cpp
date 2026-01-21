#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450"
#include "template/template.hpp"
#include "library/graph/tree/heavy_light_decomposition.hpp"
#include "library/segtree/lazy_segment_tree.hpp"
/**
 * @brief 木 - HLDのテスト 木上クエリ:最大連続部分列和
 */
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> S(N);
    cin >> S;
    HeavyLightDecomposition HLD(N);
    HLD.read(N - 1);
    HLD.build();
    // 載せる構造体
    struct Node {
        int ans, _all, left, right, length;
        Node() : ans(-INF), _all(0), left(-INF), right(-INF), length(0) {}
        Node(int val, int len) {
            length = len;
            _all = val * len;
            ans = left = right = (0 < val ? _all : val);
        }
        Node operator+(const Node &s) const {
            Node res;
            res.length = length + s.length;
            res.ans = max({ans, s.ans, right + s.left});
            res._all = _all + s._all;
            res.left = max(left, _all + s.left);
            res.right = max(s.right, right + s._all);
            return res;
        }
    };
    // セグ木
    vector<Node> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = {S[HLD.rev[i]], 1ll};
    }
    auto prod_op = [](const Node &x, const Node &y) -> Node { return x + y; };
    auto prod_e = Node();
    auto apply_op = [](int f, int g) { return g; };
    auto apply_e = INF;
    auto act_op = [](const Node &x, int a, int sz) -> Node {
        (void)sz;
        return {a, x.length};
    };
    LazySegmentTree<Node, int> seg(prod_op, prod_e, apply_op, apply_e, act_op,
                                   A);
    // クエリ
    while (Q--) {
        int com, u, v, cost;
        cin >> com >> u >> v >> cost;
        --u, --v;
        if (com == 1ll) {
            HLD.add(u, v, [&](int l, int r) {
                seg.apply(l, r, cost);
            });
        }
        if (com == 2ll) {
            Node res = HLD.query(u, v, Node(),
                [&](int l, int r) { return seg.prod(l, r); },
                [](const Node &a, const Node &b) { return a + b; },
                [](Node l, const Node &r) {
                    swap(l.left, l.right);
                    return l + r;
                }
            );
            print(res.ans);
        }
    }
}
