# CHRONOMETRE 
# EXERCICE 7:

* je lance jenga build dans nkentseu :
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
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKGLSlang [STATIC_LIB] → 
  4. NKSPIRVCross [STATIC_LIB] → 
  5. NKMbedTLS [STATIC_LIB] → 
  6. pybind11 [STATIC_LIB] → 
  7. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  8. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  9. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  10. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  11. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  12. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  13. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  14. NKAnimPhysics [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  15. NKSpeech [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  16. NKCollision [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  17. NKEvolve [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  18. NKReflection [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  19. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  20. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  21. SandboxNKLogger [CONSOLE_APP] (depends: NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  22. SandboxNKFileSystem [CONSOLE_APP] (depends: NKFileSystem, NKThreading, NKLogger, NKContainers, NKMemory, NKCore, NKPlatform) → 
  23. NKSL [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSPIRVCross, NKThreading) → 
  24. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  25. NKAnimation [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  26. NKSpeechTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKSpeech, NKThreading) → 
  27. NKNavigation [STATIC_LIB] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  28. NKPhysics [STATIC_LIB] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  29. SandboxNKReflection [CONSOLE_APP] (depends: NKReflection, NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  30. NKSerialization [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKReflection, NKThreading) → 
  31. NKNetwork [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  32. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  33. NkSLCheck [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading) → 
  34. NkSLComputeCheck [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading) → 
  35. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  36. FontLoad [WINDOWED_APP] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  37. NkNavCoreDemo [CONSOLE_APP] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNavigation, NKPlatform, NKThreading) → 
  38. NKECS [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKThreading) → 
  39. SandboxNKNetwork [CONSOLE_APP] (depends: NKNetwork, NKTime, NKFileSystem, NKStream, NKMath, NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  40. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  41. NKMedia [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  42. NKGui [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  43. NKImageCodecTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  44. NKUI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  45. NKXR [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime, NKWindow) → 
  46. NKRHI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading, NKTime, NKWindow) → 
  47. NkImeTest [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime, NKWindow) → 
  48. NkVideoReadTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  49. NkFileWorkerTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  50. NKMediaTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  51. NkPdfRenderProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  52. NKVideoTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  53. NkPdfRasterTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  54. NkPdfProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  55. NKAudio [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  56. NKGuiDrawTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  57. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  58. NKUIIntegration [STATIC_LIB] (depends: NKUI, NKRHI, NKSL, NKEvent, NKWindow, NKImage, NKFont, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKTime, NKStream, NKFileSystem, NKReflection, NKSerialization) → 
  59. NkSWRasterPrimitives [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  60. NkRHIInterpTest [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  61. Model [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  62. NkFontDemo [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  63. NKTensor [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKThreading, NKTime, NKWindow) → 
  64. NKRenderer [STATIC_LIB] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  65. NkRHIDemoFullImage [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  66. NKGuiIntegration [STATIC_LIB] (depends: NKGui, NKRHI, NKSL, NKEvent, NKWindow, NKImage, NKFont, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKTime, NKStream, NKFileSystem, NKReflection, NKSerialization) → 
  67. NkFDV2 [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  68. NkComputeNkSL [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  69. NkRHIDemoFull [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  70. NkGpuProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  71. RendererRHI [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  72. NkMicRecord [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  73. NKSpeechFeatureDemo [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKSpeech, NKStream, NKThreading) → 
  74. NkAudioDemo [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  75. NKOpusRef [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  76. NKViewportDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  77. GemCrush [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  78. Gamepad [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  79. MonEssaie [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKWindow) → 
  80. NkDrawableDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  81. NewGeneration [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  82. NkImageDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  83. Nkoung [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  84. NKImGuiIntegration [STATIC_LIB] (depends: NKCanvas, NKImage, NKFont, NKRHI, NKSL, NKEvent, NKWindow, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKStream, NKTime, NKFileSystem, NKReflection, NKSerialization) → 
  85. NKRHIDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  86. RihenDefi [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  87. firsttriangle [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  88. NkSpriteDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  89. NkRef [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  90. NkCanvasDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  91. ConquerorProto [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  92. Pong [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  93. Mou [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  94. NKEditorKit [STATIC_LIB] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  95. NKCamera [STATIC_LIB] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  96. NkAudioPlayer [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  97. cr2d [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  98. NKGuiDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKWindow) → 
  99. NkVideoPlayer [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  100. NKAutograd [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  101. NKEvolveNNTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKEvolve, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  102. NKEvolveTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKEvolve, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  103. NkTensorGpuTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  104. NKGpuBenchTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  105. NKData [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  106. NKTensorDemo [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  107. Tuto05Meshes [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  108. Tuto02Renderer [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  109. NkAnimPhysTest [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKAudio, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  110. Tuto01Fenetre [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  111. Tuto04Camera [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  112. gltftest [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross) → 
  113. Tuto03Scene [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  114. NKEditMeshHarness [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  115. NKXRDemo [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKXR) → 
  116. r2d01 [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross) → 
  117. NkFBXParityDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  118. NKPA [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow, NKGuiIntegration) → 
  119. ImGuiRef [WINDOWED_APP] (depends: NKImGuiIntegration, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  120. NK3DModeler [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, NKGuiIntegration) → 
  121. NkAnimaEditor [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, NKGuiIntegration) → 
  122. ConquerorLab [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  123. NKCode [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  124. NKUIDesign [CONSOLE_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  125. NKEditorKitDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  126. NKEditorKitTest [CONSOLE_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  127. NkCameraDemos [WINDOWED_APP] (depends: NKCamera, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  128. NKARDemo [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCamera, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKXR) → 
  129. NKConvResidentBench [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  130. NKNN [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  131. NKConvBenchTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  132. NKOptim [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  133. NKInfer [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  134. NKDataTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  135. NKBpeTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  136. NKGen [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKTensor, NKThreading) → 
  137. NKAutogradTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  138. NKLlamaBlockTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  139. NKRebasinTransformer [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  140. NKConvTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  141. NKGpt [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKData, NKFileSystem, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading, NKTime) → 
  142. NKFp16Test [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  143. NKNNTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  144. NKTrain [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKData, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading) → 
  145. NKRL [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading) → 
  146. NKMlpResidentBench [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  147. NKQwen2GpuTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  148. NKQwen2Ask [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  149. NKQwenTokenizerTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  150. NKGGUFInspectTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  151. NKQ4MatmulTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  152. NKQwen2Chat [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  153. NKQwen2SftTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  154. NKQwen2BackwardTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  155. NKQwen2SftGpuTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  156. NKLLMInferTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  157. NKQwen2Train [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  158. renderdemo [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross, NKGen, NKNN, NKAutograd, NKTensor) → 
  159. NKSmoothMeshTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  160. NKGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  161. NKObjectGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  162. NKConvVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  163. NKVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  164. NKMeshRenderTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  165. NKMnistConvVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  166. NKMatTypeResetTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  167. NKVoxelGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  168. NKMnistVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  169. NKGenMeshTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  170. NKDiffusionTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  171. NKGen3DTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  172. NKInferTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  173. NKASRTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  174. NKTransformerTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKGpt, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  175. NKMnistGpuTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  176. NKIlyana [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGpt, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNN, NKNetwork, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  177. NKTTSTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  178. NKRebasinTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  179. NKMnistCnnGpuTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  180. NkVoiceLoopDemo [CONSOLE_APP] (depends: NKAudio, NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  181. NKGptTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKGpt, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  182. NKRnnCtcTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  183. NKMeshAITest [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  184. NKTrainTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  185. NKRLTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  186. NKAgent [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKFileSystem, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKTensor, NKThreading, NKTime) → 
  187. NKAgentLLMTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  188. NKAgentTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  189. NKCivilization [STATIC_LIB] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKECS, NKFileSystem, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKReflection, NKSerialization, NKTensor, NKThreading) → 
  190. Noge [STATIC_LIB] (depends: NKGlad, NKMath, NKTime, NKLogger, NKEvent, NKWindow, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKSL, NKRenderer, NKCollision, NKPhysics, NKNavigation, NKSerialization, NKFileSystem, NKFont, NKImage, NKECS, NKRL, NKAgent, NKAudio, NKMedia, NKNetwork) → 
  191. NKEmbodied [STATIC_LIB] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKTensor, NKThreading) → 
  192. NKCivilizationSocialTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  193. NKCivilizationScaleTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  194. NKCivilizationTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  195. Nogee [WINDOWED_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNavigation, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge, NKGuiIntegration) → 
  196. NkEditableMeshDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  197. NkAssetIODemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  198. NkAudioECSDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  199. NkLocomotionDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  200. PV3DE [WINDOWED_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNavigation, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge, NKGuiIntegration) → 
  201. NkHotReloadDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  202. NkNavDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNavigation, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  203. NkAgentEcsDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  204. NkSVGImportDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  205. NkUIHudDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNavigation, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  206. NkNetWorldDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  207. NKEmbodiedTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEmbodied, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
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
│  ✓ Build Successful                                                             Time: 1.20s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSPIRVCross                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.96s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMbedTLS                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 109 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.30s  │
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
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.70s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.16s  │
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
│  ✓ Build Successful                                                             Time: 0.33s  │
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
║  Project: NKAnimPhysics                                                    Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 6 source file(s)
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
║  Project: NKCollision                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
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
│  ✓ Build Successful                                                             Time: 0.19s  │
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
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.17s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKLogger                                                 Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
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
║  Project: NKSL                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 46 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.22s  │
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
║  Project: NKAnimation                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.14s  │
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
║  Project: NKNavigation                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPhysics                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
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
║  Project: NKSerialization                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.26s  │
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
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLCheck                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLComputeCheck                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.46s  │
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
║  Project: NkNavCoreDemo                                                   Kind: CONSOLE_APP  ║
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
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKNetwork                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
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
║  Project: NKMedia                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 82 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.53s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGui                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.17s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImageCodecTest                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUI                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 17 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.61s  │
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
│  ✗ Build Failed                                                                 Time: 2.68s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  44/207
Failed:         1
Not reached:    162  (arret au premier echec — voir --keep-going)
Errors:         2
Time:           16.41s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKXR
```
*  **LE TEMPS DE COMPILATION EST DE**: 16.41 SECONDES
*  **QUAND JE RELANCE J'OBTIENS**: 
```
Time:           18.80s
```

* CONCLUSION
***
 Elle peut être due a la memoire  cache, aux dépendances à recompiler, à l’utilisation du processeur et de la mémoire, ainsi aussi aux opérations effectuées sur système pendant la compilation. Ainsi, un même fichier peut nécessiter des temps de compilation différents d’une exécution à l’autre.