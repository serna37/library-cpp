#pragma once
/**
 * @file const.hpp
 * @brief 定数
 */
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
const int INF_INT = 1e9; // 基本long longを使用
const long long INF = 1e18;
const long long MOD = 998244353;
const long long MOD7 = 1000000007;
const long double EPS = 1e-14;
const int MAX_INT = 2e6;  // 基本long longを使用
const long long MAX = 2e6;
const double PI = acos(-1);
// 下右上左 DRUL
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
// 8方向
const vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};
