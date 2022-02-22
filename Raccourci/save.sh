#creer un dossier save et mettre le .git du repo 42 dedans
#creer un dossier contenant le dossier save et save.sh au meme niveau

#fait que la suite du programme sera lu comme du bash
#!/bin/bash

#go where to save
cd ~/Sauvegarde

#clear save folder
rm -rf save/*

#copy all documents in save folder
cp -r ~/Desktop/42_cursus save # -R veut dire que ca va copier le dossier en recursif ( donc jusqu a la derniere stratt inferieur
cp -r ~/Raccourci save
cp ~/.zshrc save
cp ~/.vimrc save
cp ~/.gitignore save

#clear gits
cd save
	#mac os
#find . -name "*.git" -mindepth 2 -type d -exec rm -rf {} \;
#find . -name "*.a" -mindepth 2 -type f -exec rm -rf {} \;
#find . -name "*.o" -mindepth 2 -type f -exec rm -rf {} \;
#find . -name "*.swp" -mindepth 2 -type f -exec rm -rf {} \;
#find . -name ".DS.Store" -mindepth 2 -type f -exec rm -rf {} \;
#find . -name "a.out" -mindepth 2 -type f -exec rm -rf {} \;
	#linux
find . -mindepth 2 -name "*.git" -type d -exec rm -rf {} \;
find . -mindepth 2 -name "*.vscode" -type d -exec rm -rf {} \;
find . -mindepth 2 -name "*.a" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "*.o" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "*.swp" -type f -exec rm -rf {} \;
find . -mindepth 2 -name ".DS.Store" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "a.out" -type f -exec rm -rf {} \;

#git save
git add .
git commit -m "Save Commit"
git push
