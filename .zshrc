#seulement pour linux
[[ $TERM != "screen" ]] && exec tmux

set -g mouse on

alias norm='norminette -R CheckForbiddenSourceHeader'
alias gcc='gcc -Wall -Werror -Wextra'
alias pwls='pwd && ls -la'
alias forcesave='cd ~/Sauvegarde && ./save.sh'
