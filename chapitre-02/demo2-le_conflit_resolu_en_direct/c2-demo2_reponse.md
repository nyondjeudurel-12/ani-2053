# Demonstration 2: (Le conflit resolu en direct)

* pour cette demo je vais travailler dans mon depot d'essai disponible a cette adresse :
```
https://github.com/nyondjeudurel-12/exercice
```

* je verifie d'abord le statut avec la commande git status :

resultat:
```

PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch branche-rebase
nothing to commit, working tree clean
```
* je reviens ensuite sur le main avec la commande git switch main puis git pull
resultat:

```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git pull
remote: Enumerating objects: 17, done.
remote: Counting objects: 100% (17/17), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 13 (delta 4), reused 13 (delta 4), pack-reused 0 (from 0)
Unpacking objects: 100% (13/13), 1.28 KiB | 26.00 KiB/s, done.
From https://github.com/nyondjeudurel-12/exercice
   02b8eb8..8b564a5  main             -> origin/main
 * [new branch]      exercice-defaire -> origin/exercice-defaire
Updating 02b8eb8..8b564a5
Fast-forward
 main.cpp | 6 ++++--
 1 file changed, 4 insertions(+), 2 deletions(-)
```
* je creer une nouvelle branche pour provoquer le conflit avec git switch -c conflit-demo
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch -c conflit-demo
Switched to a new branch 'conflit-demo'
```
* je modifie ensuite le main en ajoutant un commentaire 
* j'effectue par la suite un git add puis un commit avec 
```git add main.cpp
git commit -m "Modification depuis la branche conflit"
```
resultat:

```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git add main.cpp
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git commit -m "Modification depuis la branche conflit"

[conflit-demo fbb54f6] Modification depuis la branche conflit
 1 file changed, 2 insertions(+)
```
* je retourne sur le main avec git switch main
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git switch main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```
* j'effectue une autre modification au meme endroit .
* je reeffectue un git add et un commit avec :
```
git add main.cpp
git commit -m "Modification depuis main"
```
* je provoque le conflit avec git merge conflit-demo
```
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```
* Expliquons maintenant les marqueurs 
```
<<<<<<< HEAD
```
Cela indique le début de la version actuellement présente sur main.
```
>>>>>>> conflit-demo
```
Cela indique la version provenant de la branche que Git essaie de fusionner.
* je resolve le meme de c onfits en choisissant un fichier.
le fichier n'a donc plus de marqueurs.

*  je verifie a nouveau le status avec git status et j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
* je valide la resolution avec git add main.cpp et je cree un comit pour la fusion puis je verifie que le commit est  ternimer  avec git status ;
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
* pour montrer la validation je compile mon projet avec la commande 
```
g++ main.cpp -o main.exe
```
puis j'execute avec .\main.exe
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> g++ main.cpp -o main.exe
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> .\main.exe    
Enter your name:
```
* Conclusion:
***

Cette démonstration m’a permis de comprendre comment gérer un conflit Git de manière méthodique. En lisant les marqueurs, en choisissant la version à conserver, en reconstruisant le code puis en le validant, j’ai pu résoudre le conflit sans perdre les modifications. Cela montre qu’un conflit Git peut être résolu calmement en suivant une procédure précise.

