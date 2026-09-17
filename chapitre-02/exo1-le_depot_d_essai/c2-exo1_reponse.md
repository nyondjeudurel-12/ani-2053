# EXERCICE 1:
* J'ai cree un depot vide appeler "EXERCICE 1 " voici le lien :
```
https://github.com/nyondjeudurel-12/EXERCICE-1.git
```
* Je l'est ensuite clonner sur ma machine dans le terminal a l'aide de la commande suivante :
```
git clone https://github.com/nyondjeudurel-12/EXERCICE-1.git
```
* J'ai cree trois fichier donc : 
```
main1.cpp
main2.cpp
main3.cpp
```
dans main1.cpp j'ai commencer par initialiser avec 
```
git init
``` 
puis j'ai cree un premier commit avec :
```
git commit -m "Fichier_1"
```
puis je l'est pousser avec :
```
git push
```
j'ai fais pareil pour les 02 autres fichiers  

* Pour afficher l'historique en une ligne oar commit j'ai utiliser la commande :
```
git log --oneline
```
j'ai donc obtenue ceux ci :
```
fd76c08 (HEAD -> main, origin/main) Fichier_3
340f5de Fichier_2
b33e443 Fichier_1
```
* Maintenant j'ai affiche le graph avec la commande suivante:
```
git log --oneline --graph
```
et j'ai obtenu ceux ci: 
```
* fd76c08 (HEAD -> main, origin/main) Fichier_3
* 340f5de Fichier_2
* b33e443 Fichier_1
```
* CONCLUSION  
***
 J'effectue donc une remarque . c'est la remarque selon laquel l'historique et le graph mon proposer des resultats similaires . j'ai effectue toutes les taches voici les commandes concernats les commits.

 ```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git init 
Reinitialized existing Git repository in C:/Users/nyond/OneDrive/Desktop/ALL REPOS/EXERCICE-1/.git/
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git add .
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git commit -m "Fichier_1"
[main (root-commit) b33e443] Fichier_1
 4 files changed, 101 insertions(+)
 create mode 100644 .vscode/c_cpp_properties.json
 create mode 100644 .vscode/launch.json
 create mode 100644 .vscode/settings.json
 create mode 100644 main1.cpp
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git push 
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (7/7), 1.38 KiB | 705.00 KiB/s, done.
Total 7 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/nyondjeudurel-12/EXERCICE-1.git
 * [new branch]      main -> main
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git add .
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git commit -m "Fichier_2"
[main 340f5de] Fichier_2
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 main2.cpp
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git push                 
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (2/2), 270 bytes | 270.00 KiB/s, done.
Total 2 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/nyondjeudurel-12/EXERCICE-1.git
   b33e443..340f5de  main -> main
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git add .                
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git commit -m "Fichier_3"
[main fd76c08] Fichier_3
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 main3.cpp
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git push                 
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (2/2), 233 bytes | 233.00 KiB/s, done.
Total 2 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/nyondjeudurel-12/EXERCICE-1.git
   340f5de..fd76c08  main -> main
 ```
