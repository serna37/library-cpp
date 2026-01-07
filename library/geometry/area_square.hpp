#pragma once
template <typename T>
double area_square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
    return hypot(x1 - x3, y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;
}
