# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    forcepull.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 12:12:45 by mgirardo          #+#    #+#              #
#    Updated: 2022/02/22 15:56:55 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cd ~/Sauvegarde/save

git pull

cp -r 42_cursus ~/Desktop
cp .zshrc ~/.zshrc
cp .vimrc ~/.vimrc
cp -r Raccourci ~
cp .gitignore ~/.gitignore

echo MODIFI SAVE.SH ET .ZSHRC SELON OS

# A chaque pullgit sur une machine differentes changer save.sh et .zshrc
# en focntion de linux ou mac os
