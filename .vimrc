source $VIMRUNTIME/defaults.vim

"set the colors on
syntax on

"set the line numbers
set nu

"let you use the mouse in vim
set mouse=a

"while on insert mode, replace the first character with the two others and put the cursor in the middle of them
inoremap ( ()<left>
inoremap [ []<left>
inoremap ' ''<left>
inoremap " ""<left>

"while on insert mode, replace the first character with ones following and put the cursor in the middle of the parenthesis
inoremap { {<cr><cr>}<up><Tab>
inoremap if if ()<left>
inoremap while while ()<left>
inoremap return return ()<left>

"while on insert mode, wherever your are on the line when you press ; it will put it at the end and put the cursor to the next line
inoremap ; <esc>$a;

"while on insert mode, first will save and put you back on insert mode, second will save and quit
inoremap \\ <esc>:w<cr>a
inoremap \\\ <esc>:wq<cr>

"while on echap mode, first will save and put you on insert mode, second will save and quit
noremap \\\ <esc>:wq<cr> 
noremap \\ <esc>:w<cr>a
