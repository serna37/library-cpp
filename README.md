[![Actions Status](https://github.com/serna37/library-cpp/workflows/verify/badge.svg)](https://github.com/serna37/library-cpp/actions)
[![GitHub Pages](http://img.shields.io/badge/-GitHub_Pages-696969.svg?logo=github&logoColor=ffffff&style=flat)](https://serna37.github.io/library-cpp)  
[![AtCoder](https://badgen.org/img/atcoder/serna37/rating/algorithm?style=flat&label=serna37)](https://atcoder.jp/users/serna37)  
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/serna37/library-cpp?style=flat)

# [C++ ライブラリ](https://serna37.github.io/library-cpp)
C++での競技プログラミング向けに構築した、アルゴリズムとデータ構造のライブラリです。

## ⬇️ 導入
本リポジトリをクローンします。
```sh
git clone https://github.com/serna37/library-cpp
```

バンドルやojなどの関連コマンドが、私の[dotfiles](https://github.com/serna37/dotfiles/blob/master/cpp.zsh)にあります。

## 📂 include
リポジトリを`~/git`にクローンしたものとしています。
1. お目当てのコードを[Pages](https://serna37.github.io/library-cpp)からみつける
1. `include`文をクリックしてコピーする
1. 各ライブラリの説明文「`使い方`」を参考に、コードを書く

または、各ライブラリのコードブロックの`bundle`ボタンを押下し  
そのままコピペしても利用できます。

## 📽️ コンパイル
プログラムファイルがライブラリを認識できるよう、`-I`にパスを追加します。
- 🛠️ ビルドコマンド例
```sh
g++ -D=LOCAL -std=c++23 \
  -I $HOME/git/library-cpp \
  -Wall -Wextra \
  -mtune=native -march=native \
  -fconstexpr-depth=2147483647 \
  -o main ./main.cpp
```

- 🛠️ コンパイルフラグの設定例

https://github.com/serna37/library-cpp/blob/86b0ee815e773af78733ff4c0f600e42db816d74/compile_flags.txt#L1-L6

## 💎 バンドル
バンドラをビルドします
```sh
cd ~/git/library-cpp/bundler
make build
```

対象のプログラムファイルに対し、バンドラを実行します。includeしたものが全て1つのプログラムファイルにまとまるため、これを提出します
```sh
TARGET=./main.cpp
~/git/library-cpp/bundler/build/cpp-bundler -I ~/git/library-cpp $TARGET > ./bundle.cpp
```

なお、展開されたうち `#line 1 /Users/xxx/git/...` という行を削除するにはsedコマンドを用いる場合
```sh
sed -i '' '/^#line/d' ./bundle.cpp
```
のようにできます。(Macで確認)
