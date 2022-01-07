# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    forcepull.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 12:12:45 by mgirardo          #+#    #+#              #
#    Updated: 2022/01/07 13:23:53 by mgirardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cd ~/Sauvegarde/save

git pull

cp -r Libft ~/Desktop/42
cp -r Picsine ~/Desktop/42
cp -r .zshrc ~/.zshrc
