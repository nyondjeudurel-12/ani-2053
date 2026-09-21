# Demonstration 3:( Ce que le 'reflog' sauve)

* pour cette demo je vais travailler dans mon depot d'essai disponible a cette adresse :
```
https://github.com/nyondjeudurel-12/exercice
```
* je verifie le status avec git status 
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B
On branch main
nothing to commit, working tree clean
```
* je creer un travail que nous alons volontairement detruire pour ce faire je check avec Get-Content main.cpp
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> Get-Content main.cpp
#include <iostream>
#include <string>
#include <vector>
//commentaires 

//commentaire
 
int main() {
    

    std::string name;
    std::cout << "Enter your name:";
    std::getline(std::cin, name);
    std::cout << "modification A, " << name << "!" << std::endl;
    return 0;
}
//autre modification du fichier
```
* j'effectue une modification et je lance le git diff : 
resultat :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git diff
diff --git a/main.cpp b/main.cpp
index c951354..459e655 100644
--- a/main.cpp
+++ b/main.cpp
@@ -2,8 +2,6 @@
 #include <string>
 #include <vector>
 //commentaires 
-
-//commentaire
  
 int main() {
:
```
* j'enregistre le travail dans un commit avec les commandes :
```
git add main.cpp
git commit -m "Travail important avant reset"
```
* je verifie avec git log --oneline -5
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline -5
3874267 (HEAD -> main) Travail important avant reset
9a5e2c8 (origin/main, origin/HEAD) Merge branch 'conflit-demo'
b3f818a Modification depuis main
fbb54f6 (conflit-demo) Modification depuis la branche conflit
8b564a5 autre modification
```
* je detruit volontairement le travail avec 
```
git reset --hard HEAD~1
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git reset --hard HEAD~1
HEAD is now at 9a5e2c8 Merge branch 'conflit-demo'
```
* je regarde maintenant l'historique avec git log --oneline -5 
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline -5
9a5e2c8 (HEAD -> main, origin/main, origin/HEAD) Merge branch 'conflit-demo'
b3f818a Modification depuis main
fbb54f6 (conflit-demo) Modification depuis la branche conflit
8b564a5 autre modification
b63f749 autre modification- ajout du deuxieme commentaire
```
* je verifie le status avec 
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```
* Maintenant, on va chercher la trace du déplacement de HEAD avec git refog 
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git reflog
9a5e2c8 (HEAD -> main, origin/main, origin/HEAD) HEAD@{0}: reset: moving to HEAD~1
3874267 HEAD@{1}: commit: Travail important avant reset
9a5e2c8 (HEAD -> main, origin/main, origin/HEAD) HEAD@{2}: checkout: moving from main to main
9a5e2c8 (HEAD -> main, origin/main, origin/HEAD) HEAD@{3}: checkout: moving from main to main
9a5e2c8 (HEAD -> main, origin/main, origin/HEAD) HEAD@{4}: merge conflit-demo: Merge made by the 'ort' strategy.
b3f818a HEAD@{5}: commit: Modification depuis main
8b564a5 HEAD@{6}: checkout: moving from conflit-demo to main
:
```
voici le commit qui nous interesse
```
 3874267 HEAD@{1}: commit: Travail important avant reset
```
* je verifie que le commit existe encore avec git show 3874267 :
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git show 3874267
commit 3874267858459d09f801e020e6b109f7a433caad
Author: Daiki ny <nyondjeudurel8.com>
Date:   Mon Sep 21 20:36:18 2026 +0100

    Travail important avant reset

diff --git a/main.cpp b/main.cpp
index c951354..459e655 100644
--- a/main.cpp
+++ b/main.cpp
@@ -2,8 +2,6 @@
 #include <string>
:
```
* je recupere le commit avec la commande git reset --hard 3874267

```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git reset --hard 3874267
HEAD is now at 3874267 Travail important avant reset
```
puis git log --oneline -5
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline -5
3874267 (HEAD -> main) Travail important avant reset
9a5e2c8 (origin/main, origin/HEAD) Merge branch 'conflit-demo'
b3f818a Modification depuis main
fbb54f6 (conflit-demo) Modification depuis la branche conflit
8b564a5 autre modification
```
* verification finale git status:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
* je constate que le commit reecuperer est de nouveau sur ma branche avec:
```
git log --oneline --graph --decorate -5
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline --graph --decorate -5
* 3874267 (HEAD -> main) Travail important avant reset
*   9a5e2c8 (origin/main, origin/HEAD) Merge branch 'conflit-demo'
|\  
| * fbb54f6 (conflit-demo) Modification depuis la branche conflit
* | b3f818a Modification depuis main
|/  
* 8b564a5 autre modification
```
* Conclusion:
***
Le point important à retenir est que git log montre l'historique accessible de la branche, tandis que git reflog permet de retrouver des positions précédentes de HEAD, notamment après un reset.