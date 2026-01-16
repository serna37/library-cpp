#pragma once
#include <variant>
#include <type_traits>
#include <functional>

#include "library/segtree/dual_segment_tree.hpp"
#include "library/segtree/fenwick_tree.hpp"
#include "library/segtree/lazy_segment_tree.hpp"
#include "library/segtree/segment_tree.hpp"
#include "library/segtree/starry_sky_tree.hpp"
#include "library/various/monoid.hpp"
#include "library/various/monoid_act.hpp"

enum class RangeType { Single, Range };

template <typename ProdMonoid, typename UpdMonoid = ProdMonoid, typename Act = void>
struct UnifiedSegmentTree {
    // std::decay_t を使って const や参照を除去した純粋な型を取得する
    using T = std::decay_t<decltype(ProdMonoid::e)>;
    using U = std::decay_t<decltype(UpdMonoid::e)>;

    using VariantType = std::variant<
        std::monostate,
        SegmentTree<T>,
        DualSegmentTree<U>,
        LazySegmentTree<T, U>,
        FenwickTree,
        StarrySkyTree<true>,
        StarrySkyTree<false>
    >;

  private:
    VariantType tree;
    int N;

    // 分岐ロジック：upd_t, prod_t はコンパイル時に判定できないため、
    // if constexpr ではなく通常の if で分岐させるか、テンプレート引数に移動させる必要があります。
    // 今回は使い勝手を優先し、実行時の if 分岐で variant に代入します。
    template <typename InitData>
    void construct(int n, const InitData& data, RangeType upd_t, RangeType prod_t) {
        N = n;
        constexpr bool is_vec = !std::is_integral_v<InitData>;

        // 1. 星空木 (型判定のみなので if constexpr が使える)
        if constexpr (std::is_same_v<UpdMonoid, Monoid::Add> && std::is_same_v<ProdMonoid, Monoid::Min>) {
            if constexpr (is_vec) tree.template emplace<StarrySkyTree<true>>(data);
            else tree.template emplace<StarrySkyTree<true>>(N);
        }
        else if constexpr (std::is_same_v<UpdMonoid, Monoid::Add> && std::is_same_v<ProdMonoid, Monoid::Max>) {
            if constexpr (is_vec) tree.template emplace<StarrySkyTree<false>>(data);
            else tree.template emplace<StarrySkyTree<false>>(N);
        }
        // 2. Fenwick Tree (upd_t は実行時変数なので通常の if)
        else if (upd_t == RangeType::Single && prod_t == RangeType::Range &&
                 std::is_same_v<UpdMonoid, Monoid::Add> && std::is_same_v<ProdMonoid, Monoid::Add> && std::is_same_v<T, long long>) {
             // ユーザー環境に合わせて int/long long は調整が必要ですが、ここでは A の型に合わせます
             if constexpr (is_vec) tree.template emplace<FenwickTree>(data);
             else tree.template emplace<FenwickTree>(N);
        }
        // 3. Segment Tree (Point Update / Range Product)
        else if (upd_t == RangeType::Single && prod_t == RangeType::Range) {
            if constexpr (is_vec) tree.template emplace<SegmentTree<T>>(ProdMonoid::op, ProdMonoid::e, data);
            else tree.template emplace<SegmentTree<T>>(ProdMonoid::op, ProdMonoid::e, N);
        }
        // 4. Dual Segment Tree (Range Update / Point Get)
        else if (upd_t == RangeType::Range && prod_t == RangeType::Single) {
            if constexpr (is_vec) tree.template emplace<DualSegmentTree<U>>(UpdMonoid::op, UpdMonoid::e, data);
            else tree.template emplace<DualSegmentTree<U>>(UpdMonoid::op, UpdMonoid::e, N);
        }
        // 5. Lazy Segment Tree
        else {
            static_assert(!std::is_void_v<Act>, "LazySegmentTree requires an Act operator.");
            if constexpr (is_vec) tree.template emplace<LazySegmentTree<T, U>>(ProdMonoid::op, ProdMonoid::e, UpdMonoid::op, UpdMonoid::e, Act::op, data);
            else tree.template emplace<LazySegmentTree<T, U>>(ProdMonoid::op, ProdMonoid::e, UpdMonoid::op, UpdMonoid::e, Act::op, N);
        }
    }

  public:
    UnifiedSegmentTree(int n, RangeType upd_t, RangeType prod_t) {
        construct(n, n, upd_t, prod_t);
    }

    UnifiedSegmentTree(const std::vector<T>& a, RangeType upd_t, RangeType prod_t) {
        construct(a.size(), a, upd_t, prod_t);
    }

    void update(int l, int r, U x) {
        std::visit([&](auto&& t) {
            using VT = std::decay_t<decltype(t)>;
            if constexpr (std::is_same_v<VT, StarrySkyTree<true>> || std::is_same_v<VT, StarrySkyTree<false>> ||
                          std::is_same_v<VT, DualSegmentTree<U>> || std::is_same_v<VT, LazySegmentTree<T, U>>) {
                t.apply(l, r, x);
            } else if constexpr (std::is_same_v<VT, SegmentTree<T>>) {
                t.set(l, x);
            } else if constexpr (std::is_same_v<VT, FenwickTree>) {
                t.add(l, x);
            }
        }, tree);
    }

    T query(int l, int r) {
        return std::visit([&](auto&& t) -> T {
            using VT = std::decay_t<decltype(t)>;
            if constexpr (std::is_same_v<VT, StarrySkyTree<true>> || std::is_same_v<VT, StarrySkyTree<false>> ||
                          std::is_same_v<VT, SegmentTree<T>> || std::is_same_v<VT, LazySegmentTree<T, U>>) {
                return t.prod(l, r);
            } else if constexpr (std::is_same_v<VT, DualSegmentTree<U>>) {
                return t[l];
            } else if constexpr (std::is_same_v<VT, FenwickTree>) {
                return t.sum(r - 1) - t.sum(l - 1);
            }
            return (T)ProdMonoid::e;
        }, tree);
    }
};
