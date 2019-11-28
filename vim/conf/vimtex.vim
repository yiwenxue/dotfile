let g:vimtex_enabled = 1

if !exists('g:ycm_semantic_triggers')
    let g:ycm_semantic_triggers = {}
endif
au VimEnter * let g:ycm_semantic_triggers.tex=g:vimtex#re#youcompleteme

let g:vimtex_quickfix_latexlog = {'default' : 0}


" let g:vimtex_view_method = 'mupdf'
let g:vimtex_view_general_viewer = 'evince'
let g:vimtex_compiler_callback_hooks = ['MyHook']

function! MyHook(status)
    echom a:status
    " silent call system('xdotool windowactive' . v:windowid . '--sync')
    " silent call system('xdotool windowactive' . v:windowid)
endfunction
