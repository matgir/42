#seulement pour linux
[[ $TERM != "screen" ]] && exec tmux

set -g mouse on

alias norm='norminette -R CheckForbiddenSourceHeader'
alias gccflag='gcc -Wall -Werror -Wextra'
alias pwls='pwd && ls -la'
alias forcesave='cd ~/Raccourci && ./save.sh'
alias pullgit='cd ~/Raccourci && ./forcepull.sh'
