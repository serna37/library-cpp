#pragma once
vector<int> route_restore(const vector<int> &route, int goal) {
    vector<int> path = {goal};
    while (!!~route[path.back()]) path.push_back(route[path.back()]);
    reverse(path.begin(), path.end());
    return path;
}
