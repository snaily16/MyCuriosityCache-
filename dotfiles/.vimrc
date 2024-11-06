" let g:gruvbox_color_column="bg1"
" autocmd vimenter * ++nested colorscheme gruvbox
colorscheme gruvbox
set background=dark
filetype plugin indent on
syntax on
set nu
set list
set expandtab
set ts=4
set sw=4
set ruler
autocmd FileType yaml setlocal ts=2 sts=2 sw=2 expandtab

call plug#begin()
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'
call plug#end()
