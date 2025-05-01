# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    forcepull.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 12:12:45 by mgirardo          #+#    #+#              #
#    Updated: 2023/10/18 13:47:01 by mgirardo         ###   ########.fr        #
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
