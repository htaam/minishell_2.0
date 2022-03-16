#!/bin/sh

echo "Do you want to check if the updated readline library is installed?"


#    CHECK IF BREW IS INSTALLED
which -s brew
if [[ $? != 0 ]] ; then
    echo "Installing Homebrew..."
        curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
else
    echo "Updating brew..."
        brew update
fi

#    CHECK if the config is in zshrc
if grep 'source $HOME/.brewconfig.zsh' ~/.zshrc ; then
    echo "zshrc is configured correctly."
else
    echo "Adding config to .zshrc..."
        echo 'source $HOME/.brewconfig.zsh' >> ~/.zshrc
        source ~/.zshrc
fi

#    CHECK IF pkg-config and readline are installed

brew install pkg-config

brew install readline

printenv PKG_CONFIG_PATH
if [[ $? != 0 ]] ; then
    echo "Environment variable is not set correctly..."
    RL_PATH=$(brew ls readline | grep readline.pc | sed 's|/readline.pc||g')
    cat << EOF >> ~/.zshrc
# Add Path to Readline library in Brew
export PKG_CONFIG_PATH=$RL_PATH 
EOF
    source ~/.zshrc
    echo "Environment variable added to .zshrc!"
else
    echo "Environment variable OK"
fi

echo "The Makefile should compile correctly now."