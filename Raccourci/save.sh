#creer un dossier save et mettre le .git du repo 42 dedans
#creer un dossier contenant le dossier save et save.sh au meme niveau

#fait que la suite du programme sera lu comme du bash
#!/bin/bash

#go where to save
cd ~/Sauvegarde

#clear save folder
rm -rf save/*

#copy all documents in save folder
cp -r ~/Desktop/42/Libft save # -R veut dire que ca va copier le dossier en recursif ( donc jusqu a la derniere stratt inferieur
cp -r ~/Desktop/42/Picsine save # -R veut dire que ca va copier le dossier en recursif ( donc jusqu a la derniere stratt inferieur
cp -r ~/Raccourci save
cp ~/.zshrc save
cp ~/.vimrc save

#clear gits
cd save
	#mac os
#find . -name "*.git" -mindepth 2 -type d -exec rm -rf {} \;
	#linux
find . -mindepth 2 -name "*.git" -type d -exec rm -rf {} \;

#git save
git add .
git commit -m "Save Commit"
git push