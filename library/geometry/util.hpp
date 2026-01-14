#pragma once
double deg_to_rad(double d) { // 度数法 → 弧度法
    return d * PI / 180;
}
double rad_to_deg(double r) { // 弧度法 → 度数法
    return r * 180 / PI;
}
double arc_tan(double x, double y) { // 偏角をラジアンで返す
    return atan2(y, x);
}
