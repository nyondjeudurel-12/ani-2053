# Demonstration 4:(La revue de branche)

* Tous d'abord je clone le lien envoyer par le chef de l'exercice avec a l'aide de ceux ci:
```
https://github.com/Loveline-Azemfack/GestionnaireEtudiants
```
* Nous travailons donc 04 sur l'exercice depuis un depot distant .

* je commence par faire un git pull pour prendre les modification qui ont ete faite en ligne .
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git pull
From https://github.com/Loveline-Azemfack/GestionnaireEtudiants
 * [new branch]      feat/student-management -> origin/feat/student-management
Already up to date.
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git branch
* main
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git switch feat/student-management
branch 'feat/student-management' set up to track 'origin/feat/student-management'.
Switched to a new branch 'feat/student-management'
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git pull 
From https://github.com/Loveline-Azemfack/GestionnaireEtudiants
 * [new branch]      feat/student-search -> origin/feat/student-search
Already up to date.
```

* je verifie ensuite la branch ou je me trouve avec git branch je constate que je suis le *main j'effectue donc un git switch feat/student-management
 resultat:
 ```
 PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git branch
* main
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git switch feat/student-management
branch 'feat/student-management' set up to track 'origin/feat/student-management'.
Switched to a new branch 'feat/student-management'
 ```
 * La tache qui m'a ete donner par le chef est la suivante:
 ```
 Afficher la liste des étudiants.
Présenter clairement leurs informations.
Vérifier le fonctionnement avec plusieurs étudiants.
 ```

 * je creer donc un fichier main.cpp sur mon bureau et je traville dessus loin du depot de travaille d'equipe.

 * dans le main.cpp j'incremente donc ceux ci :
 ```
 #include <iostream>
#include <string>
#include <vector>

struct Etudiant {
    std::string nom;
    std::string prenom;
    int age;
};

int main() {

    std::vector<Etudiant> etudiants = {
        {"Nyondjeu", "Durel", 22},
        {"Azemfack", "Loveline", 18},
        {"Sadjifil", "Gabriel", 19},
        {"Kenmoe", "Noela", 19},
    
    };

    std::cout << "Liste des etudiants" << std::endl;
    std::cout << "===================" << std::endl;

    for (const Etudiant& etudiant : etudiants) {
        std::cout << "Nom    : " << etudiant.nom << std::endl;
        std::cout << "Prenom : " << etudiant.prenom << std::endl;
        std::cout << "Age    : " << etudiant.age << " ans" << std::endl;
        std::cout << "-------------------" << std::endl;
    }

    return 0;
}
 ```
 * je compile ensuite avec la commande :
 ```
 g++ main.cpp -o main.exe
 ```
 puis j'execute avec :
 ```
 ./main.exe
 ```
 resultat:
 ```
 PS C:\Users\nyond\OneDrive\Desktop\main demo4> ./main.exe              
Liste des etudiants
===================
Nom    : Nyondjeu
Prenom : Durel
Age    : 22 ans
-------------------
Nom    : Azemfack
Prenom : Loveline
Age    : 18 ans
-------------------
Nom    : Sadjifil
Prenom : Gabriel
Age    : 19 ans
-------------------
Nom    : Kenmoe
Prenom : Noela
Age    : 19 ans
-------------------
 ```
* Je colle ensuite mon travaille dans mon espace de travaille partager et je verifie le status avec git status et j'obtiens :

````
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git status                             
On branch feat/student-management
Your branch is up to date with 'origin/feat/student-management'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   Gestionnaire_d'Etudiants/main.cpp

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        .vscode/

no changes added to commit (use "git add" and/or "git commit -a")
````
* Le chef ma ensuite ajouter comme collaborateur dans le depot github
grace a mon nom d'utilisteur .

* j'ai du par la suite accepter l'invitation a collaborer par mail.

* j'ai ensuite effectuer un git add . puis un0' git commit -m "Section_Du_main_permettant_d'afficher_la _liste_des_etudiants"'

* j'effectue ensuite un git push 
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git add .
warning: in the working copy of '.vscode/c_cpp_properties.json', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of '.vscode/launch.json', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of '.vscode/settings.json', LF will be replaced by CRLF the next time Git touches it
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git commit -m "Section_Du_main_permettant_d'afficher_la _liste_des_etudiants"
[feat/student-management 32e0b79] Section_Du_main_permettant_d'afficher_la _liste_des_etudiants
 4 files changed, 134 insertions(+)
 create mode 100644 .vscode/c_cpp_properties.json
 create mode 100644 .vscode/launch.json
 create mode 100644 .vscode/settings.json
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git push
Enumerating objects: 11, done.
Counting objects: 100% (11/11), done.
Delta compression using up to 8 threads
Compressing objects: 100% (8/8), done.
Writing objects: 100% (8/8), 1.79 KiB | 916.00 KiB/s, done.
Total 8 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/Loveline-Azemfack/GestionnaireEtudiants
   d2ac43e..32e0b79  feat/student-management -> feat/student-management
```

* je repars donc sur la branche principale et je switch avec git switch main.
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git switch main                                                              
error: Your local changes to the following files would be overwritten by checkout:
        Gestionnaire_d'Etudiants/main.cpp
Please commit your changes or stash them before you switch branches.
Aborting
```
* puis j'effectue une fusion:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git merge feat/student-management                                            
Already up to date.
```

* j'effectue donc un git pull pour recuperer le travail des autres.
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git pull
remote: Enumerating objects: 6, done.
remote: Counting objects: 100% (6/6), done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (4/4), 753 bytes | 44.00 KiB/s, done.
From https://github.com/Loveline-Azemfack/GestionnaireEtudiants
   d2ac43e..c9f1c3a  feat/student-search -> origin/feat/student-search
Already up to date.
```
* je lance le git log --oneline.
resultat:
```
PS C:\Users\nyond\OneDrive\Desktop\ALL REPOS\GestionnaireEtudiants> git log --oneline
32e0b79 (HEAD -> feat/student-management, origin/feat/student-management) Section_Du_main_permettant_d'afficher_la _liste_des_etudiants
d2ac43e (origin/main, origin/HEAD, main) creation du projet
```
* Revue du commit d2ac43e

Message : creation du projet

Le commit correspond à la création initiale du projet GestionnaireEtudiants. Son message permet de comprendre globalement son objectif et il porte sur un seul sujet : l'initialisation du projet.

Cependant, le message pourrait être amélioré en utilisant une formulation plus précise et une majuscule, par exemple : Initialise le projet GestionnaireEtudiants.

Pour vérifier complètement la qualité de ce commit, il faut également examiner les fichiers ajoutés afin de vérifier qu'ils correspondent bien à la création du projet et qu'aucun fichier inutile ou sans rapport n'y a été ajouté.