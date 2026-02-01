#!/bin/bash
set -e

# $1：移動先フォルダ
# $2：コンテストコード

cd $1
acc new $2 --template cpp
