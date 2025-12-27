
/** ======================================= */
/**               幾何                      */
/** ======================================= */
#pragma once
class Geometry {
  public:
    // 度数法 → 弧度法
    double deg_to_rad(double d) {
        return d * PI / 180;
    }
    // 弧度法 → 度数法
    double rad_to_deg(double r) {
        return r * 180 / PI;
    }
    // 偏角をラジアンで返す
    double arc_tan(double x, double y) {
        return atan2(y, x);
    }
    /**
     * 三角形の面積
     * doubleは桁数表現11bitを除き、52bit程度の精度
     * 18桁使うなら2で割らずlong longで返すこと
     */
    template <typename T>
    double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {
        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;
    }
    /**
     * 四角形の面積
     * doubleは桁数表現11bitを除き、52bit程度の精度
     * 18桁使うなら2で割らずlong longで返すこと
     */
    template <typename T>
    double area_square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
        return hypot(x1 - x3, y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;
    }
};
