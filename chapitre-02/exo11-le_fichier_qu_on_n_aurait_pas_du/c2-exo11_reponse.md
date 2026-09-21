# EXERCICE 11:(Le fichier qu'on n'aurait pas du)

* Je commence par verifier la taille de mon fichier dans mon depot d'essai disponible a cette adresse :
```
https://github.com/nyondjeudurel-12/exercice

```
* je lance le git status pour verifie si je me troubve belle et bien dasn mon depot git .
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch branche-rebase
nothing to commit, working tree clean
```
* je verifie ensuite la taille de mon fichier avec la commande :
```
(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> (Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
0,0417318344116211
```
mon ficher pese donc 0,0417318344116211 mo

* Je cree volontairement un fichier de 10 mo avec la commande 
```
fsutil file createnew gros_fichier.bin 10485760
```
resultat;
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> fsutil file createnew gros_fichier.bin 10485760
Le fichier C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B\gros_fichier.bin est créé
```
10485760 represente 10 mo .
* je verifie ensuite sa taille avec la commande :
```
Get-Item gros_fichier.bin | Select-Object Name,Length
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> Get-Item gros_fichier.bin | Select-Object Name,Length

Name               Length
----               ------
gros_fichier.bin 10485760
```
il ese belle et bien  10 mo.

* j'ajoute ensuite le fichier a git avec le git add gros_fichier.bin
* j'effectue donc volontairement le premier commit avec la commande :
```
git commit -m "fichier de 10mo"
```
* je verifie avec git log --oneline -3
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline -3
1f651e9 (HEAD -> branche-rebase) fichier de 10mo
9568dc4 Modification branche principal rebase
47154e4 (base-rebase) Modification branche principal rebase
```
* je mesure la taille de .git apres le gros commit avec la commande:
```
(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
```
resultat :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> (Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
0,0860223770141602
```
je constate que sa taille a doubler.

* je supprime le fichier du commit precedent avec :
```
Remove-Item gros_fichier.bin
```
* je verifie le status avec le git status et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch branche-rebase
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    gros_fichier.bin

no changes added to commit (use "git add" and/or "git commit -a")
```
il a bien ete supprime.
* j'effectue un nouveau commit avec git add -u puis un commit avec git commit -m "supprime le fichier de 10 Mo"
* je verifie que le projet n'existe plus dans le projet actuel avec la commande ;
```
Test-Path gros_fichier.bin
```
resuultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> Test-Path gros_fichier.bin
False
```
* je reverifie l'historique avec git log --oneline -4
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline -4
43be2bc (HEAD -> branche-rebase) supprime le fichier de 10 Mo
1f651e9 fichier de 10mo
9568dc4 Modification branche principal rebase
47154e4 (base-rebase) Modification branche principal rebase
```
le fichier a disparu de la version actuelle, mais il existe toujours dans l'historique Git.
* je mesure a nouveau le .git avec:
```
(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
``` 
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> (Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
0,0864353179931641
```
* je verifie ensuite que git possede toujours le fichier dans l'historique avec la commande :
```
git log --all --full-history -- gros_fichier.bin
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline -4
43be2bc (HEAD -> branche-rebase) supprime le fichier de 10 Mo
1f651e9 fichier de 10mo
9568dc4 Modification branche principal rebase
47154e4 (base-rebase) Modification branche principal rebase
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> (Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum / 1MB
0,0864353179931641
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --all --full-history -- gros_fichier.bin
commit 43be2bcc76d32b5641d03f087928bf5c63cd28b4 (HEAD -> branche-rebase)
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 00:54:30 2026 +0100

    supprime le fichier de 10 Mo

commit 1f651e926d8880928210a4c0058db5f59460cc98
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 00:43:35 2026 +0100

    fichier de 10mo
```
il est belle et bien la .

* ** Conclusion**
***

Cette expérience montre que supprimer un fichier volumineux dans un nouveau commit ne le supprime pas de l’historique Git. Même si le fichier de 10 Mo n’est plus présent dans la version actuelle du projet, les données restent conservées dans `.git`. La taille du dépôt peut donc rester importante. Cela montre l’importance d’éviter de versionner inutilement de gros fichiers dans Git.
