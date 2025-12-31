---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "C++\u30E9\u30A4\u30D6\u30E9\u30EA\u30D0\u30F3\u30C9\u30E9\u30FC"
    links:
    - https://github.com/ZOI-dayo/cpp-bundler
  bundledCode: "#line 1 \"bundler/main.cpp\"\n/**\n * @brief C++\u30E9\u30A4\u30D6\
    \u30E9\u30EA\u30D0\u30F3\u30C9\u30E9\u30FC\n */\n// https://github.com/ZOI-dayo/cpp-bundler\n\
    // \u3092Fork\u3057\u305F\u3082\u306E\n#include <algorithm>\n#include <cassert>\n\
    #include <deque>\n#include <filesystem>\n#include <fstream>\n#include <iostream>\n\
    #include <optional>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <unistd.h>\n\nusing namespace std;\nnamespace fs = filesystem;\nusing Path =\
    \ fs::path;\n\n// \u30D8\u30C3\u30C0\u30D5\u30A1\u30A4\u30EB\u306E\u7D76\u5BFE\
    \u30D1\u30B9\u3092\u63A2\u3059\nPath lookup_header(const Path include_file, const\
    \ Path current_file, const deque<Path>& include_path) {\n  assert(include_file.is_relative());\n\
    \  assert(current_file.is_absolute());\n  assert(all_of(include_path.begin(),\
    \ include_path.end(), [](auto&& p) { return p.is_absolute(); }));\n  auto check_exist\
    \ = [&](Path p) {\n    cerr << p / include_file << endl;\n    if(fs::exists(p\
    \ / include_file)) {\n      return optional((p / include_file).lexically_normal());\n\
    \    }\n    return optional<Path>();\n  };\n  if(auto res = check_exist(current_file.parent_path());\
    \ res) return *res;\n  for(auto&& p : include_path) {\n    if(auto res = check_exist(p);\
    \ res) return *res;\n  }\n  throw runtime_error(current_file.string() + \"\u306E\
    \u51E6\u7406\u4E2D\u3001\" + include_file.string() + \"\u3068\u3044\u3046\u30D8\
    \u30C3\u30C0\u304C\u898B\u3064\u304B\u308A\u307E\u305B\u3093\u3067\u3057\u305F\
    \u3002\");\n}\n\nvoid read_file(Path file, const deque<Path>& include_path, set<Path>&\
    \ skip_target, const set<string>& default_define_set) {\n  ifstream src_file_reader(file);\n\
    \  if (!src_file_reader) {\n    throw runtime_error(\"\u5165\u529B\u30D5\u30A1\
    \u30A4\u30EB\u304C\u898B\u3064\u304B\u308A\u307E\u305B\u3093\u3067\u3057\u305F\
    \u3002\");\n  }\n\n  int line = 1;\n\n  const string include_token = \"#include\
    \ \\\"\";\n  const string define_token = \"#define \";\n  const string undef_token\
    \ = \"#undef \";\n  const string if_token = \"#if \";\n  const string ifdef_token\
    \ = \"#ifdef \";\n  const string ifndef_token = \"#ifndef \";\n  const string\
    \ endif_token = \"#endif\";\n  const string else_token = \"#else\";\n  set<string>\
    \ define_set(default_define_set);\n  stack<bool> if_stack;\n\n  while (!src_file_reader.eof())\
    \ {\n    string s;\n    getline(src_file_reader, s);\n\n    if(s.starts_with(if_token))\
    \ {\n      if_stack.push(true);\n      cout << s << \"\\n\";\n      continue;\n\
    \    } else if(s.starts_with(ifdef_token)) {\n      if_stack.push(define_set.count(s.substr(ifdef_token.size())));\n\
    \      cout << s << \"\\n\";\n      continue;\n    } else if(s.starts_with(ifndef_token))\
    \ {\n      if_stack.push(!define_set.count(s.substr(ifndef_token.size())));\n\
    \      cout << s << \"\\n\";\n      continue;\n    } else if(s.starts_with(endif_token))\
    \ {\n      if(if_stack.empty()) {\n        throw runtime_error(file.string() +\
    \ \"\u306E\u51E6\u7406\u4E2D\u3001\" + endif_token + \"\u304C\u4F59\u5206\u306B\
    \u5B58\u5728\u3057\u307E\u3059\u3002\");\n      }\n      if_stack.pop();\n   \
    \   cout << s << \"\\n\";\n      continue;\n    } else if(s.starts_with(else_token))\
    \ {\n      if(if_stack.empty()) {\n        throw runtime_error(file.string() +\
    \ \"{}\u306E\u51E6\u7406\u4E2D\u3001\" + else_token + \"\u304C\u4F59\u5206\u306B\
    \u5B58\u5728\u3057\u307E\u3059\u3002\");\n      }\n      if_stack.top() = !if_stack.top();\n\
    \      cout << s << \"\\n\";\n      continue;\n    }\n\n    if(!if_stack.empty()\
    \ && !if_stack.top()) {\n      cout << \"\\n\";\n      continue;\n    }\n\n  \
    \  if(s.starts_with(include_token)) {\n      const Path include_file = lookup_header(s.substr(include_token.size(),\
    \ s.size()-(include_token.size()+1)), file, include_path);\n      if(skip_target.count(include_file))\
    \ {\n        cout << \"\\n\";\n      } else {\n        cout << \"#line 1 \\\"\"\
    \ << include_file.string() << \"\\\"\\n\";\n        read_file(include_file, include_path,\
    \ skip_target, default_define_set);\n        cout << \"#line \" << line + 1 <<\
    \ \" \\\"\" << file.string() << \"\\\"\\n\";\n      }\n    } else if(s.starts_with(define_token))\
    \ {\n      define_set.insert(s.substr(define_token.size()));\n      cout << s\
    \ << \"\\n\";\n    } else if(s.starts_with(undef_token)) {\n      define_set.erase(s.substr(undef_token.size()));\n\
    \      cout << s << \"\\n\";\n    } else {\n      if(s.starts_with(\"#pragma once\"\
    )) {\n        skip_target.insert(file);\n        cout << \"\\n\";\n      } else\
    \ {\n        cout << s << \"\\n\";\n      }\n    }\n    line++;\n  }\n  cout <<\
    \ flush;\n}\n\nint main(int argc, char** argv) {\n  optional<Path> lib_path;\n\
    \  set<string> default_define_set;\n\n  {\n    int opt;\n    while((opt = getopt(argc,\
    \ argv, \"I:D:\")) != -1) {\n      switch(opt) {\n        case 'I':\n        \
    \  lib_path = optarg;\n          break;\n        case 'D':\n          default_define_set.insert(optarg);\n\
    \          break;\n        default:\n          throw runtime_error(\"\u4E0D\u660E\
    \u306A\u30AA\u30D7\u30B7\u30E7\u30F3\u304C\u6307\u5B9A\u3055\u308C\u307E\u3057\
    \u305F\u3002\");\n      }\n    }\n  }\n\n  const deque<Path> include_path = lib_path\
    \ ? deque<Path>{*lib_path} : deque<Path>();\n\n  if(argc <= optind) {\n    throw\
    \ runtime_error(\"\u5165\u529B\u30D5\u30A1\u30A4\u30EB\u304C\u6307\u5B9A\u3055\
    \u308C\u3066\u3044\u307E\u305B\u3093\u3002\");\n  }\n  // \u30D5\u30A1\u30A4\u30EB\
    \u8AAD\u307F\u8FBC\u307F\n  const Path src_file_name = argv[optind];\n  const\
    \ Path src_file = src_file_name.is_absolute() ? src_file_name : fs::current_path()\
    \ / src_file_name;\n  ifstream src_file_reader(src_file);\n  if (!src_file_reader)\
    \ {\n    throw runtime_error(\"\u5165\u529B\u30D5\u30A1\u30A4\u30EB\u304C\u898B\
    \u3064\u304B\u308A\u307E\u305B\u3093\u3067\u3057\u305F\u3002\");\n    return 1;\n\
    \  }\n\n  set<Path> skip_target;\n  read_file(src_file, include_path, skip_target,\
    \ default_define_set);\n}\n"
  code: "/**\n * @brief C++\u30E9\u30A4\u30D6\u30E9\u30EA\u30D0\u30F3\u30C9\u30E9\u30FC\
    \n */\n// https://github.com/ZOI-dayo/cpp-bundler\n// \u3092Fork\u3057\u305F\u3082\
    \u306E\n#include <algorithm>\n#include <cassert>\n#include <deque>\n#include <filesystem>\n\
    #include <fstream>\n#include <iostream>\n#include <optional>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unistd.h>\n\nusing namespace std;\n\
    namespace fs = filesystem;\nusing Path = fs::path;\n\n// \u30D8\u30C3\u30C0\u30D5\
    \u30A1\u30A4\u30EB\u306E\u7D76\u5BFE\u30D1\u30B9\u3092\u63A2\u3059\nPath lookup_header(const\
    \ Path include_file, const Path current_file, const deque<Path>& include_path)\
    \ {\n  assert(include_file.is_relative());\n  assert(current_file.is_absolute());\n\
    \  assert(all_of(include_path.begin(), include_path.end(), [](auto&& p) { return\
    \ p.is_absolute(); }));\n  auto check_exist = [&](Path p) {\n    cerr << p / include_file\
    \ << endl;\n    if(fs::exists(p / include_file)) {\n      return optional((p /\
    \ include_file).lexically_normal());\n    }\n    return optional<Path>();\n  };\n\
    \  if(auto res = check_exist(current_file.parent_path()); res) return *res;\n\
    \  for(auto&& p : include_path) {\n    if(auto res = check_exist(p); res) return\
    \ *res;\n  }\n  throw runtime_error(current_file.string() + \"\u306E\u51E6\u7406\
    \u4E2D\u3001\" + include_file.string() + \"\u3068\u3044\u3046\u30D8\u30C3\u30C0\
    \u304C\u898B\u3064\u304B\u308A\u307E\u305B\u3093\u3067\u3057\u305F\u3002\");\n\
    }\n\nvoid read_file(Path file, const deque<Path>& include_path, set<Path>& skip_target,\
    \ const set<string>& default_define_set) {\n  ifstream src_file_reader(file);\n\
    \  if (!src_file_reader) {\n    throw runtime_error(\"\u5165\u529B\u30D5\u30A1\
    \u30A4\u30EB\u304C\u898B\u3064\u304B\u308A\u307E\u305B\u3093\u3067\u3057\u305F\
    \u3002\");\n  }\n\n  int line = 1;\n\n  const string include_token = \"#include\
    \ \\\"\";\n  const string define_token = \"#define \";\n  const string undef_token\
    \ = \"#undef \";\n  const string if_token = \"#if \";\n  const string ifdef_token\
    \ = \"#ifdef \";\n  const string ifndef_token = \"#ifndef \";\n  const string\
    \ endif_token = \"#endif\";\n  const string else_token = \"#else\";\n  set<string>\
    \ define_set(default_define_set);\n  stack<bool> if_stack;\n\n  while (!src_file_reader.eof())\
    \ {\n    string s;\n    getline(src_file_reader, s);\n\n    if(s.starts_with(if_token))\
    \ {\n      if_stack.push(true);\n      cout << s << \"\\n\";\n      continue;\n\
    \    } else if(s.starts_with(ifdef_token)) {\n      if_stack.push(define_set.count(s.substr(ifdef_token.size())));\n\
    \      cout << s << \"\\n\";\n      continue;\n    } else if(s.starts_with(ifndef_token))\
    \ {\n      if_stack.push(!define_set.count(s.substr(ifndef_token.size())));\n\
    \      cout << s << \"\\n\";\n      continue;\n    } else if(s.starts_with(endif_token))\
    \ {\n      if(if_stack.empty()) {\n        throw runtime_error(file.string() +\
    \ \"\u306E\u51E6\u7406\u4E2D\u3001\" + endif_token + \"\u304C\u4F59\u5206\u306B\
    \u5B58\u5728\u3057\u307E\u3059\u3002\");\n      }\n      if_stack.pop();\n   \
    \   cout << s << \"\\n\";\n      continue;\n    } else if(s.starts_with(else_token))\
    \ {\n      if(if_stack.empty()) {\n        throw runtime_error(file.string() +\
    \ \"{}\u306E\u51E6\u7406\u4E2D\u3001\" + else_token + \"\u304C\u4F59\u5206\u306B\
    \u5B58\u5728\u3057\u307E\u3059\u3002\");\n      }\n      if_stack.top() = !if_stack.top();\n\
    \      cout << s << \"\\n\";\n      continue;\n    }\n\n    if(!if_stack.empty()\
    \ && !if_stack.top()) {\n      cout << \"\\n\";\n      continue;\n    }\n\n  \
    \  if(s.starts_with(include_token)) {\n      const Path include_file = lookup_header(s.substr(include_token.size(),\
    \ s.size()-(include_token.size()+1)), file, include_path);\n      if(skip_target.count(include_file))\
    \ {\n        cout << \"\\n\";\n      } else {\n        cout << \"#line 1 \\\"\"\
    \ << include_file.string() << \"\\\"\\n\";\n        read_file(include_file, include_path,\
    \ skip_target, default_define_set);\n        cout << \"#line \" << line + 1 <<\
    \ \" \\\"\" << file.string() << \"\\\"\\n\";\n      }\n    } else if(s.starts_with(define_token))\
    \ {\n      define_set.insert(s.substr(define_token.size()));\n      cout << s\
    \ << \"\\n\";\n    } else if(s.starts_with(undef_token)) {\n      define_set.erase(s.substr(undef_token.size()));\n\
    \      cout << s << \"\\n\";\n    } else {\n      if(s.starts_with(\"#pragma once\"\
    )) {\n        skip_target.insert(file);\n        cout << \"\\n\";\n      } else\
    \ {\n        cout << s << \"\\n\";\n      }\n    }\n    line++;\n  }\n  cout <<\
    \ flush;\n}\n\nint main(int argc, char** argv) {\n  optional<Path> lib_path;\n\
    \  set<string> default_define_set;\n\n  {\n    int opt;\n    while((opt = getopt(argc,\
    \ argv, \"I:D:\")) != -1) {\n      switch(opt) {\n        case 'I':\n        \
    \  lib_path = optarg;\n          break;\n        case 'D':\n          default_define_set.insert(optarg);\n\
    \          break;\n        default:\n          throw runtime_error(\"\u4E0D\u660E\
    \u306A\u30AA\u30D7\u30B7\u30E7\u30F3\u304C\u6307\u5B9A\u3055\u308C\u307E\u3057\
    \u305F\u3002\");\n      }\n    }\n  }\n\n  const deque<Path> include_path = lib_path\
    \ ? deque<Path>{*lib_path} : deque<Path>();\n\n  if(argc <= optind) {\n    throw\
    \ runtime_error(\"\u5165\u529B\u30D5\u30A1\u30A4\u30EB\u304C\u6307\u5B9A\u3055\
    \u308C\u3066\u3044\u307E\u305B\u3093\u3002\");\n  }\n  // \u30D5\u30A1\u30A4\u30EB\
    \u8AAD\u307F\u8FBC\u307F\n  const Path src_file_name = argv[optind];\n  const\
    \ Path src_file = src_file_name.is_absolute() ? src_file_name : fs::current_path()\
    \ / src_file_name;\n  ifstream src_file_reader(src_file);\n  if (!src_file_reader)\
    \ {\n    throw runtime_error(\"\u5165\u529B\u30D5\u30A1\u30A4\u30EB\u304C\u898B\
    \u3064\u304B\u308A\u307E\u305B\u3093\u3067\u3057\u305F\u3002\");\n    return 1;\n\
    \  }\n\n  set<Path> skip_target;\n  read_file(src_file, include_path, skip_target,\
    \ default_define_set);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: bundler/main.cpp
  requiredBy: []
  timestamp: '2025-12-31 17:14:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bundler/main.cpp
layout: document
redirect_from:
- /library/bundler/main.cpp
- /library/bundler/main.cpp.html
title: "C++\u30E9\u30A4\u30D6\u30E9\u30EA\u30D0\u30F3\u30C9\u30E9\u30FC"
---
