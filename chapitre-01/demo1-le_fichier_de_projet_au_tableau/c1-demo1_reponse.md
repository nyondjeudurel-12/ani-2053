# DEMONSTRATION 1:

# Présentation d'un fichier `.jenga`

## Objectif

L'objectif est de présenter un fichier `.jenga` réel et d'expliquer simplement :


## 1. Qu'est-ce qu'un fichier `.jenga` ?

Un fichier `.jenga` est un fichier de configuration utilisé par le système de build **Jenga**.

Il permet de décrire un projet et de fournir au système de compilation les informations nécessaires pour savoir comment celui-ci doit être construit.


## 2. Ce que le `.jenga` déclare

Le fichier `.jenga` sert à **déclarer la configuration du module**.

Par exemple, lorsqu'un module est déclaré comme une bibliothèque statique, le fichier peut contenir une configuration indiquant son type :

```text
Type = StaticLib
```

## 3. Ce que le `.jenga` filtre

Le fichier `.jenga` peut également servir à déterminer **ce qui doit ou ne doit pas être pris en compte** lors de la construction.

Il peut notamment filtrer :

* certains fichiers ;
* certaines configurations ;
* certains projets ;
* certaines plateformes ;
* certaines dépendances ;
* ou encore certains types de builds.

Ces filtres permettent d'éviter de construire inutilement des éléments qui ne sont pas nécessaires dans la configuration actuelle.

---

## 4. Ce que le `.jenga` délègue

Le `.jenga` ne réalise pas lui-même toute la compilation.

Il **décrit les règles et informations du projet**, puis délègue l'exécution du build aux différents outils utilisés par Jenga.

On peut donc distinguer :

```text
.jenga
   ↓
Décrit le projet
   ↓
Jenga
   ↓
Détermine les actions à effectuer
   ↓
Compilateur / linker
   ↓
Produit le résultat final
```

Le `.jenga` constitue donc principalement une **description du projet**, tandis que Jenga orchestre la construction.

---

## 5. Où est décidé qu'un module est une bibliothèque statique ?

C'est la question importante à laquelle il faut pouvoir répondre pendant la présentation.

Pour le module étudié, il faut rechercher dans son fichier `.jenga` la déclaration correspondant au **type du projet**.

Dans la liste des projets du workspace, on peut par exemple trouver :

```text
NKMath    StaticLib    C++
```

Cela signifie que `NKMath` est identifié comme une **bibliothèque statique**.

La décision concernant le type du module doit donc être recherchée dans la configuration `.jenga` qui déclare ce projet, et non dans le fichier `.cpp`.

### À retenir

```text
.jenga → déclare le type du projet
       → StaticLib
       → Jenga interprète cette déclaration
       → le système de build construit une bibliothèque statique
```

---

## 6. Exemple avec NKMath

Pour le module `NKMath`, on peut présenter les informations de manière simplifiée :

```text
Nom du projet : NKMath
Type          : StaticLib
Langage       : C++
```

Le fichier `.jenga` associé permet de définir la configuration nécessaire à la construction de ce module.

La compilation des fichiers `.cpp` produit ensuite les fichiers objets, puis le linker permet de regrouper ces éléments pour produire la bibliothèque statique.

---

## 7. Les trois notions à retenir

| Élément      | Rôle                                                                  |
| ------------ | --------------------------------------------------------------------- |
| **Déclarer** | Décrire le projet, ses sources, son type et ses dépendances           |
| **Filtrer**  | Déterminer les éléments à prendre ou à exclure selon la configuration |
| **Déléguer** | Confier la compilation et l'édition de liens aux outils appropriés    |

---

## 8. Réponse à la question de la classe

### « Où est décidé que ce module est une bibliothèque statique ? »

La réponse est :

> **C'est dans la configuration du projet, via la déclaration de son type dans le `.jenga` ou dans la configuration Jenga qui génère/décrit ce projet. Le type `StaticLib` indique à Jenga que le module doit être construit comme une bibliothèque statique.**

Il faut montrer directement à la classe **la ligne réelle du fichier `.jenga`** correspondant au module présenté.

---

## 9. Conclusion

Le fichier `.jenga` joue donc le rôle de **description du projet pour le système de build**. Il permet de déclarer les caractéristiques du module, de filtrer certains éléments et de déléguer les opérations de compilation aux outils appropriés.

L'information essentielle à retenir est que le type du module, par exemple **`StaticLib`**, est défini dans la configuration du projet. C'est cette information qui permet au système de build de savoir qu'il doit produire une bibliothèque statique.
