#!/bin/bash
set -e

is_installed() {
    [ `which "$1"` ]
}

install() {
    for p in "$@"
    do
        if [ `uname` == "Darwin" ]; then brew install $p; fi
        if [ `uname` == "Linux"  ]; then sudo apt-get install -y $p; fi
    done
}

if [ `uname` == "Darwin" ]
then
    if ! is_installed brew
    then
        ruby -e "$(curl -fsSL \
            https://raw.githubusercontent.com/Homebrew/install/master/install)"
        echo 'export PATH="/usr/local/bin:$PATH"' >> ~/.bash_profile
    else
        brew upgrade
    fi
fi

install cmake git
git submodule update --init --recursive --remote
