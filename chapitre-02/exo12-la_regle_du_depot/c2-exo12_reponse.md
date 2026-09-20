# EXERCICE 12:(LA REGLE DU DEPOT)

## DOCUMENT DEDIER AUX 04 ETUDIANTS:
* Commencons en definissant les regles de nommage des branches
Les 4 etudiants devront respecter cette convention . ma structure est  la suivante :
````
feature/nom-fonctionnalite
fix/nom-probleme
test/nom-test
docs/nom-documentation

Exemples:

feature/menu-principal
fix/bug-affichage
test/test-physique
docs/readme
````
* consigne a respecter:
```
-main est la branche principale.
-On ne travaille pas directement sur main.
-Chaque nouvelle fonctionnalité possède sa propre branche.
-Le nom doit être court et explicite.
-Utiliser des minuscules et des tirets.
```

* Definissons ce que doit contenir un commit .
Avant de creer un commit chaques etudiants doit respecter ceux ci :
```
-correspondre à une seule modification logique ;
-avoir un message clair ;
-ne pas mélanger plusieurs fonctionnalités sans rapport ;
-être suffisamment petit pour être facilement relu.
```
 Exemple de bons messages :
 ```
Corrige l'affichage du menu
Ajoute les tests du module de physique
 ```
 * surtout eviter :
 ```
-modification
-test
-changement
-correction
-truc
 ```
 * Definissons la regle avant un commit .
 avant et apres  chaque commit chaque etudiants doivent verifier le status de leur fichier avec :
 ```
git status
 ```
 * Chaque etudiants devront effectuer un add  puis un commit suivie d'un message tres clair voici les commandes :
 ```
git add <fichier>
git commit -m "message clair"
 ```
 L'objectif est de ne pas envoyer accidentellement des fichiers qui n'ont rien à voir avec la modification.

 * Definissons maintenant qui doit relire quoi .
 vous etes 04 etudiants  donc vous pouvez par exemple fonctionner avec une regle de relecture croisee comme ceux ci:
 ```
Étudiant 1 → Étudiant 2
Étudiant 2 → Étudiant 3
Étudiant 3 → Étudiant 4
Étudiant 4 → Étudiant 1
 ```
 comme ca personne ne valide seul son travail
  a ceux ci vous pouvez ajouter :
  une fonctionnalité importante → 2 relecteurs ;
  petite correction → 1 relecteur ;
  modification de main ou d'une partie critique → 2 relecteurs obligatoires.

Le point important est d'écrire clairement qui peut relire et qui peut valider.

* Definissons maintenant le fonctionnement avec les Pull Requests
pour decider que les modifications passent par une pull request le fonctionnement sera :
```
Travail local
   puis 
branche feature/...
   puis 
git push
   puis 
Pull Request
  puis 
relecture
  puis 
validation
  puis 
merge dans main
```

* Definissons maintenant les interdits. 
voici l'ensemble des interdits :
```
-travailler directement sur main ;
-faire un push --force sur main ;
-supprimer ou réécrire l'historique de main ;
-faire un commit contenant plusieurs modifications sans rapport ;
-utiliser des messages de commit vagues ;
-fusionner sa propre Pull Request sans relecture ;
-envoyer du code qui ne compile pas volontairement ;
-envoyer des fichiers temporaires ou générés inutilement.
```
je vais mettre un axant sur un point en particulier ne surtout pas effectuer un "git push --force main" sur la branche principale.

*  Definissons maintenant ce qu'on doit faire quand la branche principale est casse.
 Dans notre cas on vas travailler sur le fichier main.cpp disponible sur le lien github
 ```
 https://github.com/nyondjeudurel-12/exercice
 ```
 suivez cette procedure attentivement..

1. Arrêter les nouvelles intégrations:
Personne ne fusionne de nouvelle Pull Request tant que le problème n'est pas identifié.
2. identifier le commit responsable avec la commande :
```
git log --oneline 
```
3.  Prevenir les autres etudiants si le main est temporairement bloque.
4. corriger rapidement avec la commande :
```
git switch -c fix/main-cassee
```
apres la correction effectue un add puis un commit puis tu push .
5. verifier ensuite le main.cpp avec la commande :
```
git pull
```
