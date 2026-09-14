# Modification dans mon_projet
# EXERCICE 6:

* Voici mon fichier MonEssaie:
```
from Jenga import *
from jengaconfig import *

with project("MonEssaie"):
    windowedapp()
    language("C++")
    cppdialect("C++17")
    location(".")

    files(["src/**.cpp"])
    nkentseudependson(["NKCanvas","NKFont", "NKGlad"],
    extra_includes=["src"])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}−%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}−%{cfg.system}/%{prj.name}")

    with filter("system:Windows"):
        usetoolchain(TC_WINDOWS)
        links(["user32", "gdi32", "opengl32","dwmapi", "shell32"])

    with filter("config:Debug"):
        defines(["_DEBUG"]);optimize("Off"); symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"]);optimize("Speed"); symbols(False)
```
* Quand je retire le nkentseudependson j'obtient le message suivant:
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
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (207 projects):
  1. MonEssaie [WINDOWED_APP] → 
  2. NKPlatform [STATIC_LIB] → 
  3. NKGlad [STATIC_LIB] → 
  4. NKGLSlang [STATIC_LIB] → 
  5. NKSPIRVCross [STATIC_LIB] → 
  6. NKMbedTLS [STATIC_LIB] → 
  7. pybind11 [STATIC_LIB] → 
  8. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  9. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  10. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  11. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  12. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  13. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  14. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  15. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  16. SandboxNKLogger [CONSOLE_APP] (depends: NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  17. NKCollision [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  18. NKEvolve [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  19. NKAnimPhysics [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  20. NKReflection [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  21. NKSpeech [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  22. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  23. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  24. NKNavigation [STATIC_LIB] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  25. NKPhysics [STATIC_LIB] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  26. SandboxNKReflection [CONSOLE_APP] (depends: NKReflection, NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  27. NKSpeechTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKSpeech, NKThreading) → 
  28. NKSL [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSPIRVCross, NKThreading) → 
  29. NKSerialization [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKReflection, NKThreading) → 
  30. NKAnimation [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  31. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  32. NKNetwork [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  33. SandboxNKFileSystem [CONSOLE_APP] (depends: NKFileSystem, NKThreading, NKLogger, NKContainers, NKMemory, NKCore, NKPlatform) → 
  34. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  35. NkNavCoreDemo [CONSOLE_APP] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNavigation, NKPlatform, NKThreading) → 
  36. NkSLComputeCheck [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading) → 
  37. NkSLCheck [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading) → 
  38. NKECS [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKThreading) → 
  39. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  40. FontLoad [WINDOWED_APP] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  41. SandboxNKNetwork [CONSOLE_APP] (depends: NKNetwork, NKTime, NKFileSystem, NKStream, NKMath, NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  42. NkImeTest [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime, NKWindow) → 
  43. NKXR [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime, NKWindow) → 
  44. NKRHI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading, NKTime, NKWindow) → 
  45. NKImageCodecTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  46. NKMedia [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  47. NKUI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  48. NKGui [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  49. NkComputeNkSL [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  50. NkSWRasterPrimitives [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  51. NKRenderer [STATIC_LIB] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  52. NKTensor [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKThreading, NKTime, NKWindow) → 
  53. NkRHIDemoFullImage [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  54. NkFontDemo [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  55. Model [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  56. NkFDV2 [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  57. RendererRHI [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  58. NkRHIDemoFull [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  59. NkRHIInterpTest [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  60. NkGpuProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  61. NkFileWorkerTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  62. NKMediaTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  63. NkPdfRenderProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  64. NkPdfProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  65. NKVideoTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  66. NKAudio [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  67. NkVideoReadTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  68. NkPdfRasterTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  69. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  70. NKUIIntegration [STATIC_LIB] (depends: NKUI, NKRHI, NKSL, NKEvent, NKWindow, NKImage, NKFont, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKTime, NKStream, NKFileSystem, NKReflection, NKSerialization) → 
  71. NKGuiDrawTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  72. NKGuiIntegration [STATIC_LIB] (depends: NKGui, NKRHI, NKSL, NKEvent, NKWindow, NKImage, NKFont, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKTime, NKStream, NKFileSystem, NKReflection, NKSerialization) → 
  73. gltftest [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross) → 
  74. Tuto03Scene [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  75. r2d01 [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross) → 
  76. NkFBXParityDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  77. Tuto02Renderer [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  78. NKXRDemo [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKXR) → 
  79. Tuto05Meshes [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  80. NKEditMeshHarness [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  81. Tuto04Camera [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  82. Tuto01Fenetre [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  83. NKEvolveTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKEvolve, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  84. NkTensorGpuTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  85. NKGpuBenchTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  86. NKAutograd [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  87. NKData [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  88. NKEvolveNNTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKEvolve, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  89. NKTensorDemo [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  90. NKOpusRef [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  91. NkMicRecord [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  92. NKSpeechFeatureDemo [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKSpeech, NKStream, NKThreading) → 
  93. NkAudioDemo [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  94. NkAnimPhysTest [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKAudio, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  95. NKRHIDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  96. NkImageDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  97. NkRef [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  98. NkAudioPlayer [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  99. GemCrush [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  100. Gamepad [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  101. NKImGuiIntegration [STATIC_LIB] (depends: NKCanvas, NKImage, NKFont, NKRHI, NKSL, NKEvent, NKWindow, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKStream, NKTime, NKFileSystem, NKReflection, NKSerialization) → 
  102. NkCanvasDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  103. NkSpriteDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  104. Nkoung [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  105. Mou [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  106. cr2d [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  107. NKGuiDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKWindow) → 
  108. NkDrawableDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  109. NKEditorKit [STATIC_LIB] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  110. ConquerorProto [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  111. Pong [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  112. NkVideoPlayer [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  113. firsttriangle [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  114. NKCamera [STATIC_LIB] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  115. RihenDefi [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  116. NewGeneration [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  117. NKViewportDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  118. NKPA [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow, NKGuiIntegration) → 
  119. NKConvResidentBench [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  120. NKNN [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  121. NKInfer [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  122. NKOptim [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  123. NKConvBenchTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  124. NKBpeTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  125. NKDataTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  126. ImGuiRef [WINDOWED_APP] (depends: NKImGuiIntegration, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  127. NKEditorKitDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  128. NKCode [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  129. ConquerorLab [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  130. NKUIDesign [CONSOLE_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  131. NkAnimaEditor [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, NKGuiIntegration) → 
  132. NK3DModeler [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, NKGuiIntegration) → 
  133. NKEditorKitTest [CONSOLE_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  134. NKARDemo [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCamera, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKXR) → 
  135. NkCameraDemos [WINDOWED_APP] (depends: NKCamera, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  136. NKGen [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKTensor, NKThreading) → 
  137. NKAutogradTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  138. NKQwen2Train [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  139. NKQwen2SftGpuTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  140. NKGGUFInspectTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  141. NKQ4MatmulTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  142. NKQwen2GpuTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  143. NKQwenTokenizerTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  144. NKQwen2Ask [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  145. NKLLMInferTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  146. NKQwen2Chat [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  147. NKMlpResidentBench [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  148. NKQwen2BackwardTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  149. NKRL [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading) → 
  150. NKTrain [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKData, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading) → 
  151. NKQwen2SftTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  152. NKNNTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  153. NKFp16Test [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  154. NKGpt [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKData, NKFileSystem, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading, NKTime) → 
  155. NKLlamaBlockTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  156. NKRebasinTransformer [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  157. NKConvTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  158. NKConvVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  159. NKVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  160. NKGen3DTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  161. renderdemo [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross, NKGen, NKNN, NKAutograd, NKTensor) → 
  162. NKMeshRenderTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  163. NKDiffusionTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  164. NKVoxelGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  165. NKObjectGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  166. NKMnistVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  167. NKMatTypeResetTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  168. NKGenMeshTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  169. NKGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  170. NKMnistConvVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  171. NKSmoothMeshTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  172. NKRLTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  173. NKAgent [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKFileSystem, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKTensor, NKThreading, NKTime) → 
  174. NKInferTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  175. NKRnnCtcTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  176. NKASRTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  177. NKMnistCnnGpuTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  178. NkVoiceLoopDemo [CONSOLE_APP] (depends: NKAudio, NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  179. NKMnistGpuTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  180. NKTrainTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  181. NKMeshAITest [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  182. NKTTSTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  183. NKRebasinTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  184. NKTransformerTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKGpt, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  185. NKGptTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKGpt, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  186. NKIlyana [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGpt, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNN, NKNetwork, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  187. NKEmbodied [STATIC_LIB] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKTensor, NKThreading) → 
  188. NKCivilization [STATIC_LIB] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKECS, NKFileSystem, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKReflection, NKSerialization, NKTensor, NKThreading) → 
  189. NKAgentTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  190. NKAgentLLMTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  191. Noge [STATIC_LIB] (depends: NKGlad, NKMath, NKTime, NKLogger, NKEvent, NKWindow, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKSL, NKRenderer, NKCollision, NKPhysics, NKNavigation, NKSerialization, NKFileSystem, NKFont, NKImage, NKECS, NKRL, NKAgent, NKAudio, NKMedia, NKNetwork) → 
  192. NKEmbodiedTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEmbodied, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  193. NKCivilizationTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  194. NKCivilizationSocialTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  195. NKCivilizationScaleTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  196. PV3DE [WINDOWED_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNavigation, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge, NKGuiIntegration) → 
  197. NkNetWorldDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  198. NkEditableMeshDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  199. Nogee [WINDOWED_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNavigation, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge, NKGuiIntegration) → 
  200. NkUIHudDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNavigation, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  201. NkLocomotionDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  202. NkAgentEcsDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  203. NkAssetIODemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  204. NkAudioECSDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  205. NkSVGImportDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  206. NkHotReloadDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  207. NkNavDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNavigation, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssaie                                                      Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project MonEssaie

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGLSlang                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 50 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSPIRVCross                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.93s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMbedTLS                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 109 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.38s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: pybind11                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project pybind11

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.76s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.17s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.32s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.14s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.29s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKLogger                                                 Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCollision                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvolve                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimPhysics                                                    Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 6 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKReflection                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeech                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.13s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.11s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNavigation                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPhysics                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKReflection                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeechTest                                                    Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSL                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 46 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSerialization                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimation                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.13s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNetwork                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKFileSystem                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkNavCoreDemo                                                   Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLComputeCheck                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLCheck                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKECS                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.48s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: FontLoad                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKNetwork                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkImeTest                                                      Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKXR                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkXrOpenXRBackend.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKXR\src\NKXR\Backend\Nk ║
║ XrOpenXRBackend.cpp:30:10: fatal error: 'vulkan/vulkan.h' file not found                     ║
║    30 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKXR\src\NKXR\Backend\NkXrOpenXRBackend.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 2.62s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  42/207
Failed:         1
Not reached:    164  (arret au premier echec — voir --keep-going)
Errors:         2
Time:           14.00s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKXR
```
* Temps de compilation : 14 secondes


* Maintenant je remet le dependson et je retire le link voici le message recu :
```

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.86s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.55s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimPhysics                                                    Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 6 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.22s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvolve                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKReflection                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCollision                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKLogger                                                 Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeech                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.42s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKReflection                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNavigation                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPhysics                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSL                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 46 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.44s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSerialization                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.31s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNetwork                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKFileSystem                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimation                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.15s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeechTest                                                    Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.40s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkNavCoreDemo                                                   Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLCheck                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLComputeCheck                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKECS                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKNetwork                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: FontLoad                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.12s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.49s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKRHI                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 37 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkComputeContext.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkC ║
║ omputeContext.cpp:4:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkC ║
║ omputeContext.h:54:                                                                          ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkComputeContext.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkComputeContext.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkC ║
║ omputeContext.cpp:4:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkC ║
║ omputeContext.h:54:                                                                          ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkComputeContext.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: NkML.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkM ║
║ L.cpp:4:                                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkM ║
║ L.h:34:                                                                                      ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkML.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                 Compilation Error: NkML.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkM ║
║ L.cpp:4:                                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkM ║
║ L.h:34:                                                                                      ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkML.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                       Compilation Error: NkDirectX11CommandBuffer.cpp                        ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1\NkDirectX11CommandBuffer.cpp:6:                                                            ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1/NkDirectX11Device.h:5:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX11\NkDirectX11CommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkDeviceFactory.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkD ║
║ eviceFactory.cpp:4:                                                                          ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core/NkD ║
║ eviceFactory.h:14:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkDeviceFactory.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkDeviceFactory.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkD ║
║ eviceFactory.cpp:4:                                                                          ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core/NkD ║
║ eviceFactory.h:14:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Core\NkDeviceFactory.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                       Compilation Error: NkDirectX11CommandBuffer.cpp                        ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1\NkDirectX11CommandBuffer.cpp:6:                                                            ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1/NkDirectX11Device.h:5:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX11\NkDirectX11CommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkDirectX11Device.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1\NkDirectX11Device.cpp:5:                                                                   ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1/NkDirectX11Device.h:5:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX11\NkDirectX11Device.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                       Compilation Error: NkDirectX12CommandBuffer.cpp                        ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2\NkDirectX12CommandBuffer.cpp:6:                                                            ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2/NkDirectX12Device.h:7:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX12\NkDirectX12CommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkDirectX11Device.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1\NkDirectX11Device.cpp:5:                                                                   ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 1/NkDirectX11Device.h:5:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX11\NkDirectX11Device.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                       Compilation Error: NkDirectX12CommandBuffer.cpp                        ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2\NkDirectX12CommandBuffer.cpp:6:                                                            ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2/NkDirectX12Device.h:7:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX12\NkDirectX12CommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkDirectX12Device.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2\NkDirectX12Device.cpp:5:                                                                   ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2/NkDirectX12Device.h:7:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX12\NkDirectX12Device.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkDirectX12Device.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2\NkDirectX12Device.cpp:5:                                                                   ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX1 ║
║ 2/NkDirectX12Device.h:7:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\DirectX12\NkDirectX12Device.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                         Compilation Error: NkOpenglCommandBuffer.cpp                         ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\N ║
║ kOpenglCommandBuffer.cpp:5:                                                                  ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl/N ║
║ kOpenglDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\NkOpenglCommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                         Compilation Error: NkOpenglCommandBuffer.cpp                         ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\N ║
║ kOpenglCommandBuffer.cpp:5:                                                                  ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl/N ║
║ kOpenglDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\NkOpenglCommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkOpenglDevice.cpp                             ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\N ║
║ kOpenglDevice.cpp:5:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl/N ║
║ kOpenglDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\NkOpenglDevice.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkOpenglDevice.cpp                             ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\N ║
║ kOpenglDevice.cpp:5:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl/N ║
║ kOpenglDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\NkOpenglDevice.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                        Compilation Error: NkOpenglDeviceInternal.cpp                         ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\N ║
║ kOpenglDeviceInternal.cpp:6:                                                                 ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl/N ║
║ kOpenglDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\NkOpenglDeviceInternal.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                        Compilation Error: NkOpenglDeviceInternal.cpp                         ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\N ║
║ kOpenglDeviceInternal.cpp:6:                                                                 ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl/N ║
║ kOpenglDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Opengl\NkOpenglDeviceInternal.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkSLIntegration.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\SL\NkSLI ║
║ ntegration.cpp:9:                                                                            ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/SL/NkSLI ║
║ ntegration.h:14:                                                                             ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\SL\NkSLIntegration.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkSLIntegration.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\SL\NkSLI ║
║ ntegration.cpp:9:                                                                            ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/SL/NkSLI ║
║ ntegration.h:14:                                                                             ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\SL\NkSLIntegration.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                        Compilation Error: NkSoftwareCommandBuffer.cpp                        ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ \NkSoftwareCommandBuffer.cpp:5:                                                              ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ /NkSoftwareDevice.h:7:                                                                       ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software\NkSoftwareCommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                        Compilation Error: NkSoftwareCommandBuffer.cpp                        ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ \NkSoftwareCommandBuffer.cpp:5:                                                              ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ /NkSoftwareDevice.h:7:                                                                       ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software\NkSoftwareCommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkSoftwareDevice.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ \NkSoftwareDevice.cpp:4:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ /NkSoftwareDevice.h:7:                                                                       ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software\NkSoftwareDevice.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkSoftwareDevice.cpp                            ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ \NkSoftwareDevice.cpp:4:                                                                     ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software ║
║ /NkSoftwareDevice.h:7:                                                                       ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Software\NkSoftwareDevice.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                         Compilation Error: NkVulkanCommandBuffer.cpp                         ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\N ║
║ kVulkanCommandBuffer.cpp:5:                                                                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan/N ║
║ kVulkanCommandBuffer.h:11:10: fatal error: 'vulkan/vulkan.h' file not found                  ║
║    11 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\NkVulkanCommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                               Compilation Error: NkGrid3D.cpp                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Tools\Gr ║
║ id3D\NkGrid3D.cpp:1:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Tools\Gr ║
║ id3D/NkGrid3D.h:2:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Tools\Grid3D\NkGrid3D.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                         Compilation Error: NkVulkanCommandBuffer.cpp                         ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\N ║
║ kVulkanCommandBuffer.cpp:5:                                                                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan/N ║
║ kVulkanCommandBuffer.h:11:10: fatal error: 'vulkan/vulkan.h' file not found                  ║
║    11 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\NkVulkanCommandBuffer.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkVulkanDevice.cpp                             ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\N ║
║ kVulkanDevice.cpp:5:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan/N ║
║ kVulkanDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\NkVulkanDevice.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                            Compilation Error: NkVulkanDevice.cpp                             ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\N ║
║ kVulkanDevice.cpp:5:                                                                         ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan/N ║
║ kVulkanDevice.h:6:                                                                           ║
║ In file included from                                                                        ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkI ║
║ Device.h:28:                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkD ║
║ eviceInitInfo.h:35:10: fatal error: 'vulkan/vulkan.h' file not found                         ║
║    35 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Runtime\NKRHI\src\NKRHI\Vulkan\NkVulkanDevice.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                Time: 22.48s  │
│ Errors: 62  | Failed files: 31                                                               │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  40/207
Failed:         1
Not reached:    166  (arret au premier echec — voir --keep-going)
Errors:         62
Time:           36.01s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKRHI
```
* Temps de compilation : 42.42 secondes.

* **conclusion**:

la difference principale est:
nkentseudependson concerne surtout « qui doit être construit avant qui », alors que link concerne davantage « quelles bibliothèques sont nécessaires pour construire le projet ».