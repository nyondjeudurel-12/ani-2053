# DEMONSTRATION 2:
 
* commande permettant de mesurer le temps de construction:
```
Measure-Command { jenga build --config Debug }

Measure-Command { jenga build --target NKMath --config Debug }
```
# Mesure des temps de compilation

## Objectif

L'objectif est de mesurer et de comparer plusieurs situations de compilation du projet :

1. Construction complète à froid
2. Construction complète à chaud
3. Construction d'un seul module
4. Construction après modification d'un seul fichier source
5. Construction après modification d'un seul fichier d'en-tête



## 1. Construction complète à froid

Une construction à froid correspond à une compilation effectuée sans résultats de compilation précédents disponibles.



## 2. Construction complète à chaud

Après avoir effectué la première compilation, sans modifier les sources, relancer exactement la même commande :

```powershell
jenga build --config Debug
```

Cette fois, Jenga peut réutiliser les résultats déjà construits.

**Résultat :**


Construction complète à chaud :
``` 
Time:           1m0.5s
```

### Observation

La construction à chaud devrait normalement être plus rapide que la construction à froid, car le système peut détecter que les fichiers n'ont pas changé et éviter une partie du travail.

---

## 3. Construction d'un seul module

Choisir un module du projet, par exemple `NKMath`.

Lancer :

```powershell
jenga build --target NKMath --config Debug
```

Mesurer le temps affiché.

**Résultat :**

Module construit : NKMath
```
Time:           19.04s
```

Cette mesure permet de comparer le coût de construction d'un seul module avec celui de l'ensemble du workspace.

---

## 4. Construction après modification d'un seul fichier source

Choisir un fichier `.cpp` appartenant au module étudié.

Effectuer une modification minimale, par exemple ajouter temporairement un commentaire :

```cpp
// Test de recompilation
```

Enregistrer le fichier puis relancer :

```powershell
jenga build --target NKMath --config Debug
```

Mesurer le temps.

**Résultat :**


Fichier modifié : NkAngle.cpp
```
Temps après modification :    3.95s
```

### Observation

Jenga détecte que le fichier source a changé. Le fichier concerné doit donc être recompilé et les étapes nécessaires à la production du module peuvent ensuite être effectuées.

---

## 5. Construction après modification d'un seul en-tête

Choisir maintenant un fichier `.h` utilisé par plusieurs fichiers `.cpp`.

Effectuer une modification minimale :

```cpp
// Test de recompilation d'un header
```

Enregistrer puis lancer :

```powershell
jenga build --target NKMath --config Debug
```

Mesurer le temps.

**Résultat :**

```text
En-tête modifié : NkAngle.h
Temps après modification : 8.22s
```

---



# Tableau récapitulatif
```
| Situation                     |   Temps |
| ----------------------------- | ------: |
| Construction complète à froid | ------- |
| Construction complète à chaud | 1m05s s |
| Construction d'un seul module | 19.04s |
| Modification d'un `.cpp`      | 3.95 s |
| Modification d'un `.h`        | 8.22 s |
```
---

# Analyse

La comparaison permet de mettre en évidence le fonctionnement incrémental du système de build.

La construction complète à froid est généralement la plus coûteuse car les résultats précédents ne peuvent pas être réutilisés.

La construction complète à chaud est généralement beaucoup plus rapide lorsque rien n'a changé.

La construction d'un seul module limite le travail au module demandé et permet donc de réduire le temps de compilation.

Lorsqu'un seul fichier `.cpp` est modifié, le système peut généralement limiter la recompilation au fichier concerné et aux étapes nécessaires à la reconstruction du module.

En revanche, lorsqu'un fichier `.h` est modifié, tous les fichiers sources qui dépendent de cet en-tête peuvent devoir être recompilés. Une petite modification dans un en-tête très utilisé peut donc entraîner beaucoup plus de travail.

# Conclusion

Ces mesures montrent l'intérêt de la compilation incrémentale. Le système de build évite de reconstruire inutilement les éléments qui n'ont pas changé.

Le cas de la modification d'un en-tête est particulièrement important : même si un seul fichier `.h` est modifié, son utilisation par plusieurs fichiers `.cpp` peut provoquer la recompilation de nombreux fichiers dépendants. Le coût réel d'une modification dépend donc fortement du **graphe de dépendances** du projet.
