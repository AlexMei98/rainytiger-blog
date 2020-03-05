# 1. Pre
cur_dir=/tmp/vim-lua
mkdir ${cur_dir}

echo "\nINFO **: Install git, make, gcc, g++...\n"
sudo apt update
sudo apt -y upgrade
sudo apt install -y git make gcc g++

# 2. readline-8.0
echo "\nINFO **: Install readline-8.0...\n"
cd ${cur_dir} && wget -c https://ftp.gnu.org/gnu/readline/readline-8.0.tar.gz
tar zxf readline-8.0.tar.gz && cd readline-8.0
./configure
sudo make
sudo make install

# 3. ncurses-6.1
echo "\nINFO **: Install ncurses-6.1...\n"
cd ${cur_dir} && wget -c https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.1.tar.gz
tar zxf ncurses-6.1.tar.gz && cd ncurses-6.1
./configure
sudo make
sudo make install

# 4. lua-5.3.5
echo "\nINFO **: Install lua-5.3.5...\n"
cd ${cur_dir} && wget -c https://www.lua.org/ftp/lua-5.3.5.tar.gz
tar zxf lua-5.3.5.tar.gz && cd lua-5.3.5
sed -i 's/-ldl -lreadline/-ldl -lreadline -lncurses/g' src/Makefile
sudo make linux
sudo make install

# 5. vim
echo "\nINFO **: Install vim...\n"
cd ${cur_dir} && git clone https://github.com/vim/vim.git && cd vim
./configure --with-features=huge \
            --enable-pythoninterp=yes \
            --enable-rubyinterp=yes \
            --enable-perlinterp=yes \
            --enable-luainterp=yes \
            --with-lua-prefix=/usr/local \
            --prefix=/usr
sudo make
sudo make install

# 6. spf13-vim
echo "\nINFO **: Install spf13-vim ...\n"
cd ${cur_dir} && wget -c https://raw.githubusercontent.com/spf13/spf13-vim/3.0/bootstrap.sh -O spf13-vim.sh
sed -i "202a sed -i 's/amirh/vim-scripts/g' $HOME/.spf13-vim-3/.vimrc.bundles\n" spf13-vim.sh
sh spf13-vim.sh

# 7. finish
echo "\nINFO **: Move to your previous path...\n"
echo "\n         Vim with lua has been installed, enjoy it!\n"
