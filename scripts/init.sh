#!/bin/bash
set -ex

# バンドラのビルド
cd /workspaces/library-cpp/bundler
make build

# oj: テストDL・テスト実行用
pip3 install --user online-judge-tools --break-system-packages

# atcoder-cli: フォルダ作成用
sudo npm install -g atcoder-cli
acc config default-task-choice all
acc config default-test-dirname-format test

# テンプレート準備
CONF_DIR=$(acc config-dir)
mkdir -p "$CONF_DIR/cpp"
cd "$CONF_DIR/cpp"
[ ! -f main.cpp ] && touch main.cpp
cat - << "EOF" > template.json
{
    "task": {
        "program": [
            "main.cpp"
        ],
        "submit": "bundle.cpp"
    }
}
EOF
