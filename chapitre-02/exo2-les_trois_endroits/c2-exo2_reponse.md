# EXERCICE 2: (Les trois endroits )

* J'ai modifier  le fichier :
```
main1.cpp
```
en ajoutant ceux-ci:
```
#include <iostream>

int main (){


}
```
 
* Je lance la commande "git status "
et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

* ici Git détecte que main1.cpp a été modifié, mais la modification n'est pas encore préparée pour le commit.

* Je fais un "git add"
* Je fais ensuite un nouveau 
```
git status 
```
et j'obtiens :
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   main1.cpp

```
* Je fais ensuite un commit avec   
```
git commit -m "main1_modification"

j'obtiens:

[main 7bc3a4e] main1.cpp_modification
 1 file changed, 6 insertions(+)
```
* Puis je fais un nouveau 
```
git status
```
et j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1> git status                            
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
``` 
* Ce qui change : la modification a été enregistrée dans l'historique Git. Il n'y a maintenant plus de modification en attente.

* Conclusion
***
Cette manipulation permet de comprendre le cycle de modification avec Git. Après la modification, Git détecte le fichier comme modifié. Avec git add, la modification passe dans la zone de staging, prête à être enregistrée. Enfin, après le git commit, la modification est sauvegardée dans l’historique et le dépôt redevient propre 