#   EXERCICE 9: (L'HISTOIRE  D'UN FICHIER )

* Le fichier que j'utilise pour cette tache est le fichier Nkcolor.cpp de Nkentseu.

* j'utilise la commande 
```
git log --all --follow -- c:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
```
pour lire l'historique de Nkcolor.cpp

resultat:

```
PS C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu> git log --all --follow -- c:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
commit e6e597fddc99c8f9923aaa0dafa7e1e289f5901c
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Aug 6 20:35:53 2026 +0100

    Documentation et outillage : cours « Entrainer une IA », conventions de fichiers
    
    Cours (Documentation/cours-ia/, PDF 42 pages) -- meme charte que le cours
    NkCanvas & NKGui. Dix chapitres : comprendre, preparer sa machine (Windows,
    Linux, macOS, WSL2), le corpus, entrainer, reprendre, dialoguer, specialiser,
    partir de zero, les fichiers. Toutes les commandes ont ete EXECUTEES avant
    d'etre ecrites, et les chiffres sont des mesures : 9,15 s/pas, 10,6 jours
    l'epoque, 231 Mo le checkpoint, 77 Mo le livrable.
    
    Le cours dit aussi ce qui ne marche pas : apres 8 pas la reponse est
    strictement identique, et c'est normal -- quelques pas ne changent rien de
    perceptible. Le taire ferait conclure a tort que l'entrainement echoue.
    
    CONVENTIONS_FICHIERS.md -- la regle qui manquait : l'extension dit ce que le

```
* je reconstitue sa creation avec la commande :
```
git log --diff-filter=A --follow -- c:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
```
resultat :
```
PS C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu> git log --diff-filter=A --follow -- c:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12
```
je reconstitue  ensuite les trois moments ou il a le plus change avec la commande
```
git log --all --follow --stat -- c:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
```
resultat:

```
PS C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu> git log --all --follow --stat -- c:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkColor.cpp
commit e6e597fddc99c8f9923aaa0dafa7e1e289f5901c
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Aug 6 20:35:53 2026 +0100

    Documentation et outillage : cours « Entrainer une IA », conventions de fichiers
    
    Cours (Documentation/cours-ia/, PDF 42 pages) -- meme charte que le cours
    NkCanvas & NKGui. Dix chapitres : comprendre, preparer sa machine (Windows,
    Linux, macOS, WSL2), le corpus, entrainer, reprendre, dialoguer, specialiser,
    partir de zero, les fichiers. Toutes les commandes ont ete EXECUTEES avant
    d'etre ecrites, et les chiffres sont des mesures : 9,15 s/pas, 10,6 jours
    l'epoque, 231 Mo le checkpoint, 77 Mo le livrable.
    
    Le cours dit aussi ce qui ne marche pas : apres 8 pas la reponse est
    strictement identique, et c'est normal -- quelques pas ne changent rien de
    perceptible. Le taire ferait conclure a tort que l'entrainement echoue.
    
    CONVENTIONS_FICHIERS.md -- la regle qui manquait : l'extension dit ce que le
    fichier PRODUIT, jamais comment il est ecrit dedans. D'ou : les materiaux
    nodaux gardent .nkmat (le nodal est une facon de decrire, pas un type
    d'asset), mais un graphe de geometrie n'est pas un materiau. Le test qui
    tranche : deux fichiers qu'on peut deposer au meme endroit avec le meme effet
    partagent leur extension.
    
    Est aussi consigne le refus d'ajouter un type binaire a NKS1 : le format
    .nkasset fait deja mieux (en-tete + archive + octets bruts references par
    decalage), ce qui permet la lecture paresseuse, evite une copie, et separe le
    CRC de la structure de celui des donnees.
    
    .gitignore -- les poids appris (*.nkla, *.nkgp, *.gguf) sont des SORTIES de
    calcul : 77 Mo l'adaptateur, 231 Mo le checkpoint. Le corpus, lui, se versionne
    -- c'est du travail humain.

 Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

commit ef1bb63b5b7cc21a0d31121473fb56d71b1fbc98
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sun Jul 26 06:42:47 2026 +0100

    feat(nkai): DQN/PPO, deploiement transformer Qwen2, corps simule, TTS complet, emergence sociale, diffusion, person
nalite agent
    
    - NKRL : DQN (Jalon 2) + PPO/GAE actions continues + preuve multi-agent (Jalon 3)
    - NKInfer : dequantification GGUF (Q4_K/Q6_K/Q8_0/F16) + execution transformer Qwen2 reelle
      (28 couches, KV-cache, echantillonnage) sur poids reels Qwen2.5 7B Instruct
    - NKEmbodied : corps simule (capteurs/actionneurs/boucle), controle robuste
      (bruit capteur, limites actionneur, frequence fixe, watchdog securite)
    - NKSpeech : normalisation texte TTS complete (nombres/dates/ordinaux fr+en,
      dialectes belge/suisse), re-scoring n-gram ASR, boucle voix bout-en-bout
    - NKCivilization : regle sociale ressources renouvelables, migration NkScheduler,
      passage a l'echelle, export CSV, scenario what-if
    - NKGen : diffusion DDPM conditionnee par classe + extension nuage de points 3D
    - NKAgent : traits de personnalite mesurables + pont raisonnement LLM via NKInfer
    - NKTrain/NKData : callbacks (early-stopping, LR schedule), checkpoints generiques,
      tokenizer BPE generalise, vocabulaire/padding, augmentation de donnees
    - NKOptim/NKNN/NKAutograd : clipping de gradient, Dropout/Sequential/MLP-CNN,
      mode sans-gradient + detach
    - NKMath/Noge : fusion NkColor (doublon NKMath/Noge resorbe dans NkColorF)
    - Reconciliation des ROADMAP.md avec l'etat reel du code (NKNN/NKOptim/NKTensor/NKAutograd)
    - PV3DE : migration Noge + fix compilation (Phase R0)

 Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 655 ++++++++++++++++++++++++
 1 file changed, 655 insertions(+)

commit bdda350a054705f217f0daf5a54ab02bcb9c56ef
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Jul 9 16:53:52 2026 +0100

    style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
    
    Applique le .clang-format maison a tout l'arbre source C++ :
    - indentation par namespace (NamespaceIndentation: All)
    - public/private/protected indentes sous class (IndentAccessModifiers)
    - une ligne vide entre definitions (SeparateDefinitionBlocks)
    - une instruction par ligne, accolades attachees, tabs
    
    1748 fichiers (.h/.cpp/.inl/.mm). Verifie : NKGptTrain 25/25 et renderdemo 28/28 buildent OK apres reformatage.

 Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 1122 +++++++++++++----------
 1 file changed, 646 insertions(+), 476 deletions(-)

commit d557314e707baf17e53029b9d9cae2c5164dd417
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Tue May 5 20:04:22 2026 +0100

    update

 {Modules => Kernel}/Foundation/NKMath/src/NKMath/NkColor.cpp | 0
 1 file changed, 0 insertions(+), 0 deletions(-)

commit 1d4f072b3ca1af774f191889211cc51fc224e24e
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Apr 30 08:44:44 2026 +0100

    refactor 002

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 45 +++++++++++-------------
 1 file changed, 20 insertions(+), 25 deletions(-)

commit f1e536a58890ac267b12ab7df1004d0a43270c48
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Wed Apr 29 10:39:16 2026 +0100

    refactor 001

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 472 ++++++++++++++++++-----
 1 file changed, 367 insertions(+), 105 deletions(-)

commit 8737e282dbcbeab52dc0e6fb2740904daaf09013
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sun Apr 19 12:23:47 2026 +0100

    Begin clearing and restructured file

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 17 ++++++++---------
 1 file changed, 8 insertions(+), 9 deletions(-)

commit 9c90ccc45b942de199a4f0cbc164710bd8bdb4cc
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Mar 26 06:33:57 2026 +0100

    bug fix

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 16 ++++++++--------
 1 file changed, 8 insertions(+), 8 deletions(-)

commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 255 +++++++++++++++++++++++
 1 file changed, 255 insertions(+)
(END)

commit 9c90ccc45b942de199a4f0cbc164710bd8bdb4cc
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Mar 26 06:33:57 2026 +0100

    bug fix

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 16 ++++++++--------
 1 file changed, 8 insertions(+), 8 deletions(-)

commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 255 +++++++++++++++++++++++
 1 file changed, 255 insertions(+)
~
~
~
~
~
~
~
(END)

commit 9c90ccc45b942de199a4f0cbc164710bd8bdb4cc
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Mar 26 06:33:57 2026 +0100

    bug fix

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 16 ++++++++--------
 1 file changed, 8 insertions(+), 8 deletions(-)

commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 255 +++++++++++++++++++++++
 1 file changed, 255 insertions(+)
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
(END)

commit 9c90ccc45b942de199a4f0cbc164710bd8bdb4cc
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Mar 26 06:33:57 2026 +0100

    bug fix

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 16 ++++++++--------
 1 file changed, 8 insertions(+), 8 deletions(-)

commit 9c49f79fc1d5eabac6df981bfd6996abe1e7f4bf
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sat Mar 21 03:25:48 2026 +0100

    bug fix vulkan opengl dx11 current bug software and dx12

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 255 +++++++++++++++++++++++
 1 file changed, 255 insertions(+)
~
~
``` 
* je cherche maintenant les trois moments ou il a le plus changer :
resultat:
```
Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 655 ++++++++++++++++++++++++
 1 file changed, 655 insertions(+)

Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 1122 +++++++++++++----------
 1 file changed, 646 insertions(+), 476 deletions(-)

  Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 472 ++++++++++++++++++-----
 1 file changed, 367 insertions(+), 105 deletions(-)


```
* passons a ce que les message disent des raisons :

```
Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 655 ++++++++++++++++++++++++
 1 file changed, 655 insertions(+)

le message qu'affiche ce commit est :

"style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
    
    Applique le .clang-format maison a tout l'arbre source C++ :
    - indentation par namespace (NamespaceIndentation: All)
    - public/private/protected indentes sous class (IndentAccessModifiers)
    - une ligne vide entre definitions (SeparateDefinitionBlocks)
    - une instruction par ligne, accolades attachees, tabs
    
    1748 fichiers (.h/.cpp/.inl/.mm). Verifie : NKGptTrain 25/25 et renderdemo 28/28 buildent OK apres reformatage.
"

Kernel/Foundation/NKMath/src/NKMath/NkColor.cpp | 1122 +++++++++++++----------
 1 file changed, 646 insertions(+), 476 deletions(-)

 le message qu'affiche ce commit est :

 update

 Modules/Foundation/NKMath/src/NKMath/NkColor.cpp | 472 ++++++++++++++++++-----
 1 file changed, 367 insertions(+), 105 deletions(-)

le message qu'affiche ce commit est :

  refactor 001

``` 

* *Conclusion*
***

Cette tâche m’a permis de retracer l’évolution complète d’un fichier du moteur grâce à l’historique Git. L’analyse des différents commits permet de comprendre quand le fichier a été créé, comment il a évolué et quelles étaient les raisons indiquées par les développeurs pour ses principales modifications.
