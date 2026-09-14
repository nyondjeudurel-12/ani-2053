# EXERCICE 10

* voici les 7 dependances directes de NKCanvas :

-NKWindow
-NKFont
-NKImage
-NKStream
-NKTime
-NKGlad
-NKThreading

* GRAPHE:
```
                         NKCanvas
                            │
        ┌───────────┬───────┼────────┬─────────┬────────┬───────────┐
        │           │       │        │         │        │           │

    NKWindow     NKFont  NKImage  NKStream  NKTime  NKGlad   NKThreading
        │           │       │        │         │        │           │
        │           │       │        │         │        │           │
     
 ┌────────────┐ ┌────────┐ ┌──────────────┐ ┌────────┐      ┌────────────┐
 │NKContainers│ │NKPlat. │ │NKContainers  │ │NKCont. │      │NKContainers│
 │NKCore      │ │NKCore  │ │NKCore        │ │NKCore  │      │NKCore      │
 │NKEvent     │ │NKMemory│ │NKFileSystem  │ │NKLogger│      │NKMemory    │
 │NKFileSystem│ │NKMath  │ │NKLogger      │ │NKMemory│      │NKPlatform  │
 │NKLogger    │ │NKCont. │ │NKMath        │ │NKPlat. │      └────────────┘
 │NKMath      │ │NKThread│ │NKMemory      │ │NKThread│  
 │NKMemory    │ │        │ │NKPlatform    │ └────────┘  
 │NKPlatform  │ │        │ │NKStream      │             
 │NKThreading │ │        │ │NKThreading   │             
 │NKTime      │ │        │ └──────────────┘             
 └────────────┘ └────────┘                              
   ````                                                     
                                               
                                               
 * Il faut construire 17 projets avec lui.

PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> py "C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Jenga\Jenga\Jenga.py" build --target NKCanvas

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
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (17 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  11. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  12. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  13. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  14. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKUI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  17. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow)