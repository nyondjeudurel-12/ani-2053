#   EXERCICE 7:(Le conflit qui n'en est pas un)

Pour cet exercice j'ai modifie la ligne 5, et celle 6 de mes deux clones et mes modifications etaient juste des commentaires qui sont respectivement **//modification premiere du fichier** et **//autre modification du fichier** selon les lignes 5 et 6. 

* Testons maintenant pour voir s'il y aura pas de conflits: Pour cela, on va utiliser les commandes git : **add, commit, et push** dans les deux clones. Tout d'abord il faut savoir que c'est cmme ceci, que se presentent mes deux clones :
```
#include <iostream>
#include <string>
#include <vector>
int main() {
    //modification premiere du fichier

    std::string name;
    std::cout << "Enter your name:";
    std::getline(std::cin, name);
    std::cout << "modification A, " << name << "!" << std::endl;
    return 0;
}
```
et :
```
#include <iostream>
#include <string>
#include <vector>

int main() {
    

    std::string name;
    std::cout << "Enter your name:";
    std::getline(std::cin, name);
    std::cout << "modification A, " << name << "!" << std::endl;
    return 0;
}
//autre modification du fichier
```

je commence a mettre sur le repository le premier en ces differentes etapes:
```
git add main.cpp
git commit -m "premiere modification
```
Resultat:
```
 - ajout d'un commentaire"
[main 02b8eb8] premiere modification - ajout d'un commentaire
 1 file changed, 2 insertions(+)
```
```
git push
```
Resultat:
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 361 bytes | 180.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/nyondjeudurel-12/exercice
   cc7d4b1..02b8eb8  main -> main
```

Le premier clone a donc deja ete pousse, passons au deuxieme:
```
git commit -m "autre 
```
Resultat:
```
modification"                               
[main 8b564a5] autre modification
 1 file changed, 3 insertions(+), 3 deletions(-)
```
```
 git push -u origin main 
```
Resultat:
```                
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 312 bytes | 312.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/nyondjeudurel-12/exercice.git
   b63f749..8b564a5  main -> main
```

* GIT ASSSEMBLE  
On remarque que bien que nous avonss modifier les deux clones mais cette fois a des lignes differentes, git n'a rencontre aucun conflit, ceci prouve que git a donc assemblet l'ensemble des modification, verifions cela avec **git log --oneline** :
```
8b564a5 (HEAD -> main, origin/main, origin/HEAD) autre modification
b63f749 autre modification- ajout du deuxieme commentaire
02b8eb8 premiere modification - ajout d'un commentaire
cc7d4b1 resolution
7ebdbca modifification depuis B
05a99e6 modif
322cb89 modification1
7851fb3 modification
ade50c1 main.cpp
```

On voit donc que nos deux commit sont presents:
```
8b564a5 (HEAD -> main, origin/main, origin/HEAD) autre modification
02b8eb8 premiere modification - ajout d'un commentaire
```
* Conclusion:  
Ce travail nous a donc permis de remarquer que plusieurs personnes peuvent travailler sur un depot distants et meme en modifiant on peut toujours pousser le projet sur github  il suffit simplement de savoir gerer les modifications