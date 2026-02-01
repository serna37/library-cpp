#!/bin/bash
set -e

# $1：プログラムファイル
# $2：作成先のフォルダ

# ビルド済みバンドラを実行
/workspaces/library-cpp/bundler/build/cpp-bundler \
    -I /workspaces/library-cpp \
    $1 > $2/bundle.cpp

# lineから始まる行を消す
sed -i '/^#line/d' $2/bundle.cpp

# 生成したファイルを開く
code $2/bundle.cpp
