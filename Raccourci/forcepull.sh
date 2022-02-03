# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    forcepull.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 12:12:45 by mgirardo          #+#    #+#              #
#    Updated: 2022/02/03 17:53:42 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cd ~/Sauvegarde/save

git pull

cp -r Libft ~/Desktop/42
cp -r Picsine ~/Desktop/42
cp -r ft_printf ~/Desktop/42
cp .zshrc ~/.zshrc
cp .vimrc ~/.vimrc
cp -r Raccourci ~
cp .gitignore ~/.gitignore
cp -r Piscine_AI ~/Desktop/42
cp -r get_next_line ~/Desktop/42

echo MODIFI SAVE.SH ET .ZSHRC SELON OS

# A chaque pullgit sur une machine differentes changer save.sh et .zshrc
# en focntion de linux ou mac os
