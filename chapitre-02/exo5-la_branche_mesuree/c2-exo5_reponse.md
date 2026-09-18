## Exercice 5 : la_branche_mesuree

* j ai modifie le fichier pour la premiere fois ensuite j ai tape :
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\EXERCICE-1>"{0:N2} Ko" -f ((Get-ChildItem -Recurse -File | Measure-Object Length -Sum).Sum / 1KB)
```
pour pouvoir calculer la taille du fichier et j ai trouve:
taille = 1.61 ko

et j ai tape :
```
git add main1.cpp
```
pour pouvoir ajouter les modifications faites 

* ensuite je tape 
```
git status
```
ca me donne 
```
On branch taille-test
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

* puis j ai fait un 
```
git commit -m "main1_modification1"
```
qui est le premier commit ce qui me donne 
```
[taille-test d18a671] main1_modification1
 1 file changed, 1 insertion(+)
```

* j ai effectue la deuxieme modification j ai fait un 
```
git add main1.cpp
```
ensuite j ai fais 
```
git commit -m "main1_modification2"
```
ce quime donne 
```
[taille-test 3d4bb68] main1_modification2
 1 file changed, 3 insertions(+), 1 deletion(-)
```
puis je fais un 
```
git status 
```
ce qui me donne 
```
On branch taille-test
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
* Ensuite j ai fai la troisieme modification et j ai tape
```
git add main1.cpp 
```
Ensuite j ai fait un 
```
git commit -m "main1_modification3"
```

ce qui donne 
```
[taille-test c8c8573] main1_modification3
 1 file changed, 1 deletion(-)
```

ensuite un 
```
git status 
```
et ca donne 
```
On branch taille-test
nothing to commit, working tree clean
```
* ensuite j affiche l historique des commits avec
```
git log --oneline                  
```
et ca donne 
```
c8c8573 (HEAD -> taille-test) main1_modification3
3d4bb68 main1_modification2
d18a671 main1_modification1
```
* puis j ai utilise la commande :
```
{0:N2} Ko" -f ((Get-ChildItem -Recurse -File | Measure-Object Length -Sum).Sum / 1KB)
```
pour trouver la taille en kilo octet qui est :
taille = 2.64 ko

* calcul du depot gagnee

pour le calcul je fait 
```
2.64 - 1.61 = 1.03 ko 
```
*  Conclusion
***
donc le depot a gagnee 1.03 ko sur le disque. 