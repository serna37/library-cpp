#!/bin/bash
set -e

# $1：移動先フォルダ
# $2：問題URL

cd $1

# testフォルダがあったら消す
[ -d "test" ] && rm -rf "test"

# URLからDLする
oj d $2
