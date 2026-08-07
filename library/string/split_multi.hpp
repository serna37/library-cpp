#pragma once
vector<string> split_multi(const string &S, const string &seps) {
  vector<string> res = {""};
  for (auto &&v : S) {
    if (count(seps.begin(), seps.end(), v)) {
      res.emplace_back("");
    } else {
      res.back() += v;
    }
  }
  return res;
}
