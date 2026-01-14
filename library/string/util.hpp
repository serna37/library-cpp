#pragma once
string string_to_lower(string s) {
    std::transform(all(s), s.begin(), ::tolower);
    return s;
}
string string_to_upper(string s) {
    std::transform(all(s), s.begin(), ::toupper);
    return s;
}
bool char_is_lower(char c) { // boolで返す
    return islower(c) != 0;
}
bool char_is_upper(char c) { // boolで返す
    return isupper(c) != 0;
}
