# Comparons

pour compter le nombre de fichier sources j'ai utiliser la commande suivant dans le dossier nkentseu :(Get-ChildItem -Recurse -Include .cpp,.h,.py,.hpp,.sh,.jenga -File).Count

j'ai obtenu 3406 fichiers sources !=  2641 fichiers sources comme dans le chapitre.  

pour compter le nombre de lignes du depot j'ai utiliser la commande suivant dans le dossier nkentseu : (Get-ChildItem -Recurse -Include .cpp,.h,.hpp,.py,.sh.jenga,.md,.txt,.json,.git,*.bat -File | Get-Content | Measure-Object -Line).Lines

j'ai obtenu 1631791 lignes !=  1193385 lignes .

# Conclusion

 Cette difference est probablement du au fait que je ne connais pas entierement toutes les extensions de l'ensemble des fichiers contenue dans le dossier nkentseu.