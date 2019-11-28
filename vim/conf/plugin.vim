call plug#begin('~/.vim/plugged')


Plug 'VundleVim/Vundle.vim' " package mamager 
Plug 'jiangmiao/auto-pairs' " auto complete pairs 
Plug 'vim-airline/vim-airline' " change the apperance of bar
Plug 'vim-airline/vim-airline-themes' "theme database
Plug 'scrooloose/nerdtree' 
Plug 'tpope/vim-commentary' "add shortcut to turn lines into comment
Plug 'Yggdroot/indentLine' "auto indent line 
Plug 'junegunn/fzf' "search tools
Plug 'airblade/vim-gitgutter' " a tool to show git status
Plug 'neoclide/coc.nvim' , {'branch': 'release'} 
" Plug 'ycm-core/YouCompleteMe' " a code complete tool 
Plug 'lervag/vimtex' " to simplify latex compile 
Plug 'SirVer/ultisnips' " complete engine to complete code segments
Plug 'honza/vim-snippets' " auto complete the codes
" Plug 'dense-analysis/ale'
Plug 'morhetz/gruvbox' 
Plug 'tomasr/molokai'

call plug#end()
