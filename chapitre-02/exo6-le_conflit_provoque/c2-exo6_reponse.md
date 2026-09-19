# EXERCICE 6:(Le conflit provoquer)

* Le fichier que j'ai decider de modifier est le fichier "main.cpp" disponible sur mon github notament a cette adresse .
```
https://github.com/nyondjeudurel-12/exercice
```
* J'ai creer un clone A appeler exercice A et un second clone appeller exercice B j'ai clonne a l'aide de la commande 
````
git clone https://github.com/nyondjeudurel-12/exercice
````
* J'ai ensuite verifier l'etat des dossiers avec le git status dans les deux clones.
j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice A> git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

* j'ai modifier une ligne dans exercice A et j'ai effectuer une modification differente a la meme ligne dans B.

* puis dans exercice A j'ai effectuer un 'git add main.cpp' puis un commit avec 'git commit -m "modification A"' puis j'ai push avec git push.
j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice A> git push
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 301 bytes | 301.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/nyondjeudurel-12/exercice.git
   322cb89..05a99e6  main -> main
```

* Je suis aller dans second clone j'ai egalement lancer git add main.cpp puis git commit -m "modification B" puis quand j'ai voulu utilise le git push je suis tomber sur ceux ci :

```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git push
To https://github.com/nyondjeudurel-12/exercice
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/nyondjeudurel-12/exercice'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```
* j'ai vouler detecter le conflit et j'ai donc utiliser la commande git pull et j'obtiens ceux ci :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git pull
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 1), reused 3 (delta 1), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 281 bytes | 25.00 KiB/s, done.
From https://github.com/nyondjeudurel-12/exercice
   322cb89..05a99e6  main       -> origin/main
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

* j'ai ensuite lancer la commande git status  pour verifier l'etat du fichier et j'ai obtenu ceux ci 

```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
* pour resoudre l'erreur j'ai donc choisit une seul version j'ai concerver celle de A j'a appliquer la meme modification du clone A dans le clone B.

* j'ai relancer git status et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch and 'origin/main' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
        modified:   main.cpp

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp
```
* j'ai donc par la suite refais un git add un nouveu git commit -m "resolution" et j'ai push le fichier.
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git add .
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git commit -m "resolution"
[main cc7d4b1] resolution
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git push

Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 490 bytes | 490.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/nyondjeudurel-12/exercice
   05a99e6..cc7d4b1  main -> main
```

* Conclusion 
***
 j’ai pu provoquer un refus de push, puis un conflit lors du pull. J’ai ensuite résolu manuellement le conflit dans main.cpp, créé le commit de résolution et envoyé les modifications sur le dépôt . Cela montre l’importance de synchroniser régulièrement son travail et de savoir résoudre les conflits lors d’un travail collaboratif avec Git.
