#pragma once
char int_to_char(int x) { return (char)(x + '0'); }
char int_to_alph(int x) { return (char)(x + 'a'); }
int char_to_int(char c) { return (int)(c - '0'); }
string int_to_string(long long x) { return to_string(x); }
long long string_to_int(const string &s) { return stoll(s); }
