#pragma once
template <typename T> double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {
    return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;
}