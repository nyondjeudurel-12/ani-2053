#   EXERCICE 10 (Fusionner de rejouer)


* Pour cette tache je vais travailler dans mon depot "exercice" sur le clone exercice B 
disponible a cette adresse :
```
https://github.com/nyondjeudurel-12/exercice
```

* je verifie d'abord l'integriter des fichiers avec le git status :

```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```
* je lance git rebase --continue pour terminer s'il y a un rebase en cour.
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git rebase --continue
fatal: no rebase in progress
```
il y avait rien en cour .

* je verifie ensuite les branch avec le git branch :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git branch
* main
```
tous est ok.

* je creer une branche pour la tache avec la commande :
```
git switch -c test-integration
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch -c test-integration
Switched to a new branch 'test-integration'
```
* je procede donc a l'integration avec la commande :
```
git switch -c branche-merge
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch -c branche-merge
Switched to a new branch 'branche-merge'
```
* j'effectue une modification sur le fichier main.cpp je retire une bibliotheque. puis j'effectue un git add main.cpp. je poursuis avec un commit donc git commit -m "modification branche m"

* je retourne ensuite au git switch test-integration
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch test-integration           
Already on 'test-integration'
```
* j'effectue une autre mofification sur le main.cpp je supprime une autre bibliotheque puis j'effectue un nouveau add puis un nouveau commit avec git commit -m "modification branche principal"
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git commit -m "modification branche principal"  
[test-integration ce420d8] modification branche principal
```
* j'effectue donc des a present la fusion avec la commande :
```
git merge branche-merge
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git merge branche-merge                       
Already up to date.
```

* j'affiche le graph avec la commande :
```
git log --oneline --graph --decorate --all
```
resultat :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git merge branche-merge                       
Already up to date.
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline --graph --decorate --all
*   ce420d8 (HEAD -> test-integration) modification branche principal
|\  
| * 42d5561 (branche-merge) modification branche
* | 186a3db modification branche principale
* | 40770c4 modification branche m
|/  
* 02b8eb8 (origin/main, origin/HEAD, main) premiere modification - ajout d'un commentaire
*   cc7d4b1 resolution
|\  
| * 05a99e6 modif
* | 7ebdbca modifification depuis B
|/  
* 322cb89 modification1
* 7851fb3 modification
* ade50c1 main.cpp
```

* je passe maintenant a la partie rebase . je creer une branche de reference avec git switch -c test-rebase
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch -c test-rebase                   
Switched to a new branch 'test-rebase'
```
* je reviens au commit commun avec la commande :
```
git switch -c base-rebase 02b8eb8
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch -c base-rebase 02b8eb8
Switched to a new branch 'base-rebase'
```
* Je creer la branche qui contiendra la modification avec git switch -c branche-rebase et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch -c branche-rebase
Switched to a new branch 'branche-rebase'
```

* je modifie a nouveau mon mian.cpp j'effectue un git add main.cpp puis un git commit -m "modification branche rebase"
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git add main.cpp
>> git commit -m "Modification branche rebase"
[branche-rebase 423fb6f] Modification branche rebase
 1 file changed, 1 insertion(+), 1 deletion(-)
```
* je retouene donc sur la base avec git switch base-rebase
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch base-rebase
Switched to branch 'base-rebase'
```
* j'effectue une autre modification et je refais > git add main.cpp  
et git commit -m "Modification branche principal rebase" 
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git add main.cpp  
>> git commit -m "Modification branche principal rebase"
[detached HEAD 9568dc4] Modification branche principal rebase
 1 file changed, 2 insertions(+), 2 deletions(-)
```    
* je reviens sur la branche de travail git switch branche-rebase avec git switch branche-rebase
resultat
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch branche-rebase
Switched to branch 'branche-rebase'
```
* j'effectue donc un git rebase base-rebase pour que git rejoue le commit de branche-rebase au dessus du commit de base-rebase
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git rebase base-rebase               
Successfully rebased and updated refs/heads/branche-rebase.
```
* j'affiche son graphe avec git log --oneline --graph --decorate --all -15 resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline --graph --decorate --all -15
* 9568dc4 (HEAD -> branche-rebase) Modification branche principal rebase
* 47154e4 (base-rebase) Modification branche principal rebase
| *   ce420d8 (test-rebase, test-integration) modification branche principal
| |\  
| | * 42d5561 (branche-merge) modification branche
| |/  
|/|   
| * 186a3db modification branche principale
| * 40770c4 modification branche m
|/  
* 02b8eb8 (origin/main, origin/HEAD, main) premiere modification - ajout d'un commentaire
*   cc7d4b1 resolution
|\  
| * 05a99e6 modif
* | 7ebdbca modifification depuis B
|/  
* 322cb89 modification1
* 7851fb3 modification
* ade50c1 main.cpp
```

* conclusion
***

Avec merge, les deux historiques sont conservés et Git ajoute généralement un commit de fusion et 
avec rebase, les commits sont rejoués sur une nouvelle base, ce qui produit un historique plus linéaire .