# Projet Jenga.
# EXERCICE 5:

J'ai commence par creer le dossier "MonEssaie" dans le dossier Application de Nkentseu. 

Ensuite j'ai cree un fichier main.cpp voici son contenu
 ```
#include <iostream>
int main() {

    return 0;
}
```
j'ai egalement cree un fichier main.jenga dans lequelle j'ai ecrit le programe de compilation du main.cpp 
```
import os
from Jenga import *
from Jenga.GlobalToolchains import RegisterJengaGlobalToolchains

with workspace("main.cpp"):
    configurations(["Debug", "Release"])
    targetoses([TargetOS.WINDOWS])
    targetarchs([TargetArch.X86_64])

    with project("main.cpp"):
        consoleapp()
        language("C++")
        cppdialect("C++17")
        files(["**.cpp"])

        with filter("system:Windows"):
            usetoolchain("clang-mingw")
```

j'ai ensuite declarer le fichier au workspace avec la commande :  
```
with include("Applications/MonEssai/main.jenga"): 
        
        pass
```
dans Nkentseu.jenga

j'ai lancer jenga.info et j'ai obtenue ceux ci:
```
Projects
------------------------------------------------------------
Name       Kind         Language   Test   External
==================================================
main.cpp   ConsoleApp   C++        No     No


Available Toolchains
------------------------------------------------------------
Name                Family   Target OS   Arch     Env  
=======================================================
host-clang          clang    Windows     x86_64   mingw
host-gcc            gcc      Windows     x86_64   mingw
clang-mingw         clang    Windows     x86_64   mingw
mingw               gcc      Windows     x86_64   mingw
clang-cross-linux   clang    Linux       x86_64   gnu


Daemon
------------------------------------------------------------
Status: Not running
```

j'ai donc terminer avec le build et voici le resultat :
```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.6.2             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. main.cpp [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: main.cpp                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.02s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```


conclusion:

j'ai terminer avec le test de mon premier projet avec jenga.