# EXERCICE 8: (Six manieres de faire)

* Je vais trailler dans mon depot 'exercice' que voici le lien :
```
https://github.com/nyondjeudurel-12/exercice
```
* Dans le powershell j'ai commmencer par verifier si j'etais dans le depot avec git status :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```
* Ensuite j'ai regarder le branches avec git branch :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git branch
* main
```
* j'ai ensuite creer une autre branch: 
avec
```
git switch -c exercice-defaire
```
j'obtiens :

```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git switch -c exercice-defaire
Switched to a new branch 'exercice-defaire'
```
* *Premier cas une modification non voulue*:
****
* j'ai retirer une bibliotheque dans mon main.cpp
* je verifie ensuite le status avec git status et j'obtiens ceux ci:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
* J'annule cette modication comme j'ai juger qu'elle n'etait pas volontaire avec 'git restore main.cpp' et ma modification a ete annule .

* je verifie a nouveau le status avec git status et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
nothing to commit, working tree clean
```
* *Un add de trop*:
***

* j'effectue une autre modification je supprime encore une bibliotheque et quand je tape le git status j'ai ceux ci :
````
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
````
* j'effectue un git add main.cpp puis je verifie encore le status j'obtiens ceux ci:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   main.cpp

```
* Je supprime le fichier staging avec :
```
git restore --staged main.cpp
```
* je verifie le status et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp
```
Ceux message signifie la modification exixte toujours mas elle n'est plus dans le staging.

*  *Un commit de trop*
***
* comme mon main.cpp est encore modifier j'effectue un git add main.cpp puis je verifie a nouveau le status
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status                   
On branch exercice-defaire
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   main.cpp
```
* je creer un mauvais commit volontairement :
```
git commit -m "modification temporaire"

resultat:

PS C:\Users\nyond\OneDrive\Desktop\exercice> git commit -m "modification temporaire"
[exercice-defaire 586de1a] modification temporaire
 1 file changed, 1 insertion(+), 1 deletion(-)
```
* je verifie l'historique avec git log --oneline -5
j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git log --oneline -5
586de1a (HEAD -> exercice-defaire) modification temporaire
cc7d4b1 (origin/main, origin/HEAD, main) resolution
7ebdbca modifification depuis B
05a99e6 modif
322cb89 modification1
```
* j'ai donc juger que le commit etait une erreur alors je decide de l'annuler avec la commande :
```
git reset HEAD~1

resultat:

Unstaged changes after reset:
M       main.cpp
```
* je verifie a nouveau l'historique avec git log --oneline -5
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git log --oneline -5
cc7d4b1 (HEAD -> exercice-defaire, origin/main, origin/HEAD, main) resolution
7ebdbca modifification depuis B
05a99e6 modif
322cb89 modification1
7851fb3 modification
```
j'observe donc que la modification a ete annuler

*  *Un commit deja pousser qu'il faut annuler*:
***
* j'effectue a nouveau une modification je retire une autre bibliotheque 
* j'effectue un git add main.cpp puis un git commit -m "commit annuler"
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git commit -m "commit annuler"         
[exercice-defaire 650faee] commit annuler
 1 file changed, 2 insertions(+), 2 deletions(-)
```
* je lance le git log --oneline -3 pour trouver son identifiant j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git log --oneline -3
650faee (HEAD -> exercice-defaire) commit annuler
cc7d4b1 (origin/main, origin/HEAD, main) resolution
7ebdbca modifification depuis B

identifiant: 650faee
```
* je lie ensuite ma branche a github avec 'git push -u origin exercice-defaire'puis je push .
* j'annule le commit avec  la commande 

```
git revert 650faee
```
j'obtiens ceux ci:
```
Revert "commit annuler"

This reverts commit 650faeecf0911a5b14e5ba27497abb8884a611b2.

# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
#
# On branch exercice-defaire
.git/COMMIT_EDITMSG [unix] (16:58 19/09/2026)                                              1,1 Top
recording @q                                                                        

resultat:
PS C:\Users\nyond\OneDrive\Desktop\exercice> git revert 650faee
[exercice-defaire 66595cf] Revert "commit annuler"
 1 file changed, 2 insertions(+), 2 deletions(-)
```

* je relance git push et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git push          
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 357 bytes | 357.00 KiB/s, done.
Total 3 (delta 1), reused 1 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/nyondjeudurel-12/exercice
   650faee..66595cf  exercice-defaire -> exercice-defaire
 
```
* *Mettre un travail en cour de cote*
***
* Je modifie a nouveau mon main.cpp en supprimat a nouveau une  bibliotheque . puis je lance git status et  j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status                             
On branch exercice-defaire
Your branch is up to date with 'origin/exercice-defaire'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
* Je met mon travail de cote avec la comande 'git stash'
et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git stash
Saved working directory and index state WIP on exercice-defaire: 66595cf Revert "commit annuler"
```
* je reverifie le status et j'obtiens
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
Your branch is up to date with 'origin/exercice-defaire'.

nothing to commit, working tree clean
```
la modification est donc stocker dans le strash.

* pour verifier ce que le strash contient je lance la commande git stash list 
```
PS C:\Users\nyond\OneDrive\Desktop\exercice>  git stash list 
stash@{0}: WIP on exercice-defaire: 66595cf Revert "commit annuler"
```
* je recupere le travail avec git stash pop
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git stash pop
On branch exercice-defaire
Your branch is up to date with 'origin/exercice-defaire'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (44c20346954a7f8a5d22ad43eaf28b843dffab37)
```
* je verifie le status et j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status     
On branch exercice-defaire
Your branch is up to date with 'origin/exercice-defaire'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
* *Retrouver un commit perdu*
***
* je verifie a  nouveau le status apres avooir push
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git status
On branch exercice-defaire
Your branch is up to date with 'origin/exercice-defaire'.

nothing to commit, working tree clean
```
* je cree ensuite le commit que je vais perdre 
```
git commit -m "the last1"
```
* Je fais un add puis un commit pour le commit  a retrouver ..
```
git commit -m "Commit à retrouver"
j'obtiens 

PS C:\Users\nyond\OneDrive\Desktop\exercice> git commit -m "commit retrouver"
[exercice-defaire c710151] commit retrouver
 1 file changed, 1 insertion(+)
```

* je verifie le commit avec git log --oneline -5
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git log --oneline -5               
c710151 (HEAD -> exercice-defaire) commit retrouver
b6e491a (origin/exercice-defaire) the last
66595cf Revert "commit annuler"
650faee commit annuler
cc7d4b1 (origin/main, origin/HEAD, main) resolution
```
* Je fais ensuite disparaitre le commit de l'historique courant avec la commande git reset --hard c710151
j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git reset --hard c710151
HEAD is now at c710151 commit retrouver
```
* je verifie le commit disparu avec PS git log --oneline -5 
resultat 
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git log --oneline -5
c710151 (HEAD -> exercice-defaire) commit retrouver
b6e491a (origin/exercice-defaire) the last
66595cf Revert "commit annuler"
650faee commit annuler
cc7d4b1 (origin/main, origin/HEAD, main) resolution
```
* j'utilise maintenant git reflog 
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git reflog
c710151 (HEAD -> exercice-defaire) HEAD@{0}: reset: moving to c710151
c710151 (HEAD -> exercice-defaire) HEAD@{1}: commit: commit retrouver
b6e491a (origin/exercice-defaire) HEAD@{2}: commit: the last
66595cf HEAD@{3}: reset: moving to HEAD
66595cf HEAD@{4}: revert: Revert "commit annuler"
650faee HEAD@{5}: commit: commit annuler
cc7d4b1 (origin/main, origin/HEAD, main) HEAD@{6}: reset: moving to HEAD~1
586de1a HEAD@{7}: commit: modification temporaire
cc7d4b1 (origin/main, origin/HEAD, main) HEAD@{8}: checkout: moving from main to exercice-defaire
:


voici la ligne qui m'interesse c710151 (HEAD -> exercice-defaire) HEAD@{1}: commit: commit retrouver
```

* je restaure ensuite le commit avec git reset --hard c710151
resultat
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git reset --hard c710151
HEAD is now at c710151 commit retrouver
```
* je verifie que le commit est revenu git log --oneline -5
resultat
```
PS C:\Users\nyond\OneDrive\Desktop\exercice> git log --oneline -5
c710151 (HEAD -> exercice-defaire) commit retrouver
b6e491a (origin/exercice-defaire) the last
66595cf Revert "commit annuler"
650faee commit annuler
cc7d4b1 (origin/main, origin/HEAD, main) resolution
```
* Conclusion
***

Cette tâche m’a permis de comprendre comment gérer différentes erreurs et situations courantes avec Git. J’ai appris à annuler une modification, retirer un fichier du *staging*, supprimer un commit, annuler un commit déjà envoyé avec `git revert`, mettre temporairement un travail de côté avec `git stash` et retrouver un commit perdu grâce au `git reflog`. Ces commandes permettent ainsi de mieux contrôler l’historique du projet et de récupérer plus facilement après une erreur.
