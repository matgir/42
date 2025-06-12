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
	#linux
find . -mindepth 2 -name "*.git" -type d -exec rm -rf {} \;
find . -mindepth 2 -name "*.vscode" -type d -exec rm -rf {} \;
find . -mindepth 2 -name "*.a" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "*.o" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "*.swp" -type f -exec rm -rf {} \;
find . -mindepth 2 -name ".DS.Store" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "a.out" -type f -exec rm -rf {} \;
find . -mindepth 2 -name "*.env" -type f -exec rm -rf {} \;

#git save
git add .

# Ask user for commit message
echo -n "Enter a commit message (default: Save Commit): "
read commit_msg

# Use default message if user didn't provide one
if [ -z "$commit_msg" ]; then
    commit_msg="Save Commit"
fi

git commit -m "$commit_msg"
git push

cd -
