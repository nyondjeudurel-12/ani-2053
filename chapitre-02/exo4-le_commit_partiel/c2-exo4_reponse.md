# EXERCICE 4:(LE COMMIT PARTIEL )

* J'ai commence par modifier le fichier "main1.cpp" j'ai ajoute une bibliotheque et j'ai ajouter quelques instructions.

* je verifie ensuite les 02 modifications avec le commande 
```
git diff
```
et j'obtiens :

```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1>git diff
diff --git a/main1.cpp b/main1.cpp
index f14477a..832e514 100644
--- a/main1.cpp
+++ b/main1.cpp
@@ -1,6 +1,10 @@
 #include <iostream>
+#include <string>
 
-int main (){
-
:
```

* je verifie ensuite l'etat des modifications avec "git status"
 j'obtiens:
 ```
 PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1>git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
 ```

* J'utilise ensuite la commande 
```
git add -p
```
j'obtiens:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1>git add -p
diff --git a/main1.cpp b/main1.cpp
index f14477a..832e514 100644
--- a/main1.cpp
+++ b/main1.cpp
@@ -1,6 +1,10 @@
 #include <iostream>
+#include <string>
 
-int main (){
-
-
+int main() {
+    std::string name;
+    std::cout << "Enter your name: ";
+    std::getline(std::cin, name);
+    std::cout << "Hello, " << name << "!" << std::endl;
+    return 0;
 }
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 2 hunks.
@@ -1,2 +1,3 @@
 #include <iostream>
+#include <string>
 
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
@@ -2,5 +3,8 @@
 
-int main (){
-
-
+int main() {
+    std::string name;
+    std::cout << "Enter your name: ";
+    std::getline(std::cin, name);
+    std::cout << "Hello, " << name << "!" << std::endl;
+    return 0;
 }
\ No newline at end of file
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n
```
* j ai fait un premier commit avec 
```
git commit -m "1 ere modification"
```
ce qui donne 
```
[main ea2215a] 1 ere modification
 1 file changed, 1 insertion(+)
```
j ajoute les modifications restante avec 
```
git add nom du fichier
```
j ai cree le deuxieme commit avec :
```
git commit -m "2 eme modification"
```
ca donne :
```
[main a264d7b] 2 eme modification
 1 file changed, 6 insertions(+), 3 deletions(-)
```
* Apres je tape la commande :
```
git status
```
Et j ai comme resultat:
```
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```
* J affiche l historique avec :
```
git log --oneline
```
et ca donne 
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1>git log --oneline
a264d7b (HEAD -> main) 2 eme modification
ea2215a 1 ere modification
7bc3a4e main1.cpp_modification
fd76c08 (origin/main) Fichier_3
340f5de Fichier_2
b33e443 Fichier_1
```
* conclusion

Cet exercice montre l’intérêt de git add -p lorsqu’un même fichier contient plusieurs modifications indépendantes. Cette commande permet de sélectionner chaque modification séparément afin de créer deux commits distincts, chacun correspondant à un seul sujet. Cela rend l’historique Git plus clair, plus organisé et facilite la compréhension des changements effectués dans le projet.