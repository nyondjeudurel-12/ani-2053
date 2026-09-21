# DEMONSTRATION 1 :( VIVRE DANS LA DEPOT DES AUTRES )

* Je vais continuer a travailler dans mon depot d'essai disponible a cette adresse "https://github.com/nyondjeudurel-12/exercice
"
* j'affiche l'historique GIT avec:
```
git log --oneline --graph --decorate --all
```
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline --graph --decorate --all
* 43be2bc (HEAD -> branche-rebase) supprime le fichier de 10 Mo
* 1f651e9 fichier de 10mo
* 9568dc4 Modification branche principal rebase
* 47154e4 (base-rebase) Modification branche principal rebase
| *   ce420d8 (test-rebase, test-integration) modification branche principal
| |\  
| | * 42d5561 (branche-merge) modification branche
| |/  
|/|   
:
```
* J'identifie les elements importants:
 la branche principale :
 ```
 9568dc4 
 ```
 le point de divergence:
 ```
 42d5561
 ```
 la fusion:
 ```
 ce420d8
 ```
 * Je dessine ensuite les graphs:
 ```
                  ● 42d5561  ← branche-merge
                /
● 02b8eb8 ── ● 40770c4 ── ● 186a3db ──┐
                                        │
                                        ● ce420d8  ← test-integration
 ```
 * Expliquons le point de divergence:
 ```
         ● 42d5561
       /
● 02b8eb8
       \
        ● 40770c4
 ```
  02b8eb8 est le commit commun. À partir de ce point, deux branches ont évolué séparément. C'est le point de divergence. 

  * j'explique maintenant la fusion :
  ```
                 ● 42d5561
                /
● 02b8eb8 ── ● 40770c4 ── ● 186a3db ──┐
                                        │
                                        ● ce420d8
 ` ```
  Le commit ce420d8 est le commit de fusion. Il réunit les deux historiques dans la branche test-integration.

*   je montre maintenant le meme graph avec le git log --oneline --graph --decorate --all
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\exercice 6\exercice B> git log --oneline --graph --decorate --all
* 43be2bc (HEAD -> branche-rebase) supprime le fichier de 10 Mo
* 1f651e9 fichier de 10mo
* 9568dc4 Modification branche principal rebase
* 47154e4 (base-rebase) Modification branche principal rebase
| *   ce420d8 (test-rebase, test-integration) modification branche principal
| |\  
| | * 42d5561 (branche-merge) modification branche
| |/  
|/|   
:
```
Le graphe que Git affiche correspond au dessin que j'ai fait au tableau. Les * représentent les commits, les lignes | et / représentent les différentes branches et leur évolution, et la convergence des lignes représente la fusion.

* petite correspondanceau tableau:
```
●	                       * = commit
Ligne verticale	|          = continuité de branche
/	                       séparation ou retour d'une branche
Deux chemins	           deux historiques de branches
Point de divergence	       commit commun avant la séparation
Point de convergence	   commit de fusion
Nom de branche	           indiqué avec --decorate
```
* Conclusion
***

Le graphe dessiné au tableau représente la structure logique de l'historique Git. La commande git log --graph permet de voir cette même structure directement dans le terminal. On retrouve donc les commits, les branches, le point de divergence et le commit de fusion.