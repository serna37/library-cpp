#!/bin/bash
set -e

# $1：移動先フォルダ

# 移動してテスト実行
cd $1
oj t
