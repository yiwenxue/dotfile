" Create a new buffer
nmap <space>t :enew<cr> 

" Move to the next buffer
nmap <space>l :bnext<CR>

" Move to the previous buffer
nmap <space>h :bprevious<CR>

" Close a buffer
nmap <space>d :bd <CR>

" List all buffers 
nmap <space>m :ls <CR>


inoremap <expr> <Tab> pumvisible() ? "\<C-n>" : "\<Tab>"
inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
inoremap <expr> <cr> pumvisible() ? "\<C-y>" : "\<C-g>u\<CR>"
autocmd! CompleteDone * if pumvisible() == 0 | pclose | endif
