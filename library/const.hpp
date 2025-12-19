#pragma once
/**
 * @file const.hpp
 * @brief 定数
 */
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
constexpr int INF_INT = 1e9; // 基本long longを使用
constexpr long long INF = 1e18;
constexpr long long MOD = 998244353;
constexpr long long MOD7 = 1000000007;
constexpr long double EPS = 1e-14;
constexpr int MAX_INT = 2e6;  // 基本long longを使用
constexpr long long MAX = 2e6;
constexpr double PI = acos(-1);
// 下右上左 DRUL
constexpr vector<int> dx = {0, 1, 0, -1};
constexpr vector<int> dy = {1, 0, -1, 0};
// 8方向
constexpr vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};
constexpr vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};
