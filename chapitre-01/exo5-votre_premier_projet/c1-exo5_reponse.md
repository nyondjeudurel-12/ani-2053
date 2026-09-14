# Projet Jenga.
# EXERCICE 5:

J'ai commence par creer le dossier "MonEssaie" dans le dossier Application de Nkentseu. 

Ensuite j'ai cree un fichier MonEssaie.cpp voici son contenu
 ```
#include <iostream>
int main() {

    return 0;
}
```
j'ai egalement cree un fichier MonEssaie.jenga dans lequelle j'ai ecrit le programe de compilation de MonEssaie.cpp 
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

j'ai ensuite declarer le fichier au workspace avec la commande :  
```
with include("Applications/MonEssaie/MonEssaie.jenga"): 
        
        pass
```
dans Nkentseu.jenga

j'ai lancer jenga.info et j'ai obtenue ceux ci:
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

Error loading workspace: External file not found: Applications\MonEssai\main.jenga
Failed to load workspace.
PS C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu> jenga info

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

[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
========================== Jenga Workspace: Nkentseu ===========================

Location: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu
Entry file: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Nkentseu.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Linux, macOS, Android, iOS, Web, HarmonyOS, XboxSeries, XboxOne
Target Architectures: x86_64, arm64, wasm32
Start project: Sandbox


Projects
------------------------------------------------------------
Name                         Kind          Language   Test   External
=====================================================================
__Unitest__                  StaticLib     C++        No     No
MonEssaie                    WindowedApp   C++        No     Yes
NKPlatform                   StaticLib     C++        No     Yes
NKPlatform_Tests             TestSuite     C++        Yes    Yes
NKCore                       StaticLib     C++        No     Yes
NKCore_Tests                 TestSuite     C++        Yes    Yes
NKLogger                     StaticLib     C++        No     Yes
NKLogger_Tests               TestSuite     C++        Yes    Yes
NKMath                       StaticLib     C++        No     Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMemory                     StaticLib     C++        No     Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKContainers                 StaticLib     C++        No     Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKFont                       StaticLib     C++        No     Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKAudio                      StaticLib     C++        No     Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime                       StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKThreading                  StaticLib     C++        No     Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork                    StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKSerialization              StaticLib     C++        No     Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKEvent                      StaticLib     C++        No     Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKCanvas                     StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKRHI                        StaticLib     C++        No     Yes
NKUI                         StaticLib     C++        No     Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKGui                        StaticLib     C++        No     Yes
NKEditorKit                  StaticLib     C++        No     Yes
NkPdfRasterTest              ConsoleApp    C++        No     Yes
NKCode                       WindowedApp   C++        No     Yes
NkFileWorkerTest             ConsoleApp    C++        No     Yes
NkPdfRenderProbe             ConsoleApp    C++        No     Yes
NkPdfProbe                   ConsoleApp    C++        No     Yes
NK3DModeler                  WindowedApp   C++        No     Yes
NKImGuiIntegration           StaticLib     C++        No     Yes
NKUIIntegration              StaticLib     C++        No     Yes
NKGuiIntegration             StaticLib     C++        No     Yes
NKCamera                     StaticLib     C++        No     Yes
NKCamera_Tests               TestSuite     C++        Yes    Yes
NKCollision                  StaticLib     C++        No     Yes
NKCollision_Tests            TestSuite     C++        Yes    Yes
NKPhysics                    StaticLib     C++        No     Yes
NKPhysics_Tests              TestSuite     C++        Yes    Yes
NKAnimPhysics                StaticLib     C++        No     Yes
NKAnimation                  StaticLib     C++        No     Yes
NKNavigation                 StaticLib     C++        No     Yes
NKNavigation_Tests           TestSuite     C++        Yes    Yes
NKXR                         StaticLib     C++        No     Yes
NKXR_Tests                   TestSuite     C++        Yes    Yes
renderdemo                   WindowedApp   C++        No     Yes
gltftest_Tests               TestSuite     C++        Yes    Yes
Gamepad_Tests                TestSuite     C++        Yes    Yes
renderdemo_Tests             TestSuite     C++        Yes    Yes
NkRHIDemoFullImage           WindowedApp   C++        No     Yes
NewGeneration                WindowedApp   C++        No     Yes
NkCanvasDemo_Tests           TestSuite     C++        Yes    Yes
r2d01                        WindowedApp   C++        No     Yes
NkRHIInterpTest_Tests        TestSuite     C++        Yes    Yes
FontLoad                     WindowedApp   C++        No     Yes
NkSWRasterPrimitives_Tests   TestSuite     C++        Yes    Yes
NkDrawableDemo               WindowedApp   C++        No     Yes
NkRHIInterpTest              WindowedApp   C++        No     Yes
NkCanvasDemo                 WindowedApp   C++        No     Yes
NkRHIDemoFull                WindowedApp   C++        No     Yes
r2d01_Tests                  TestSuite     C++        Yes    Yes
NkFDV2_Tests                 TestSuite     C++        Yes    Yes
NkSpriteDemo                 WindowedApp   C++        No     Yes
cr2d_Tests                   TestSuite     C++        Yes    Yes
NewGeneration_Tests          TestSuite     C++        Yes    Yes
firsttriangle_Tests          TestSuite     C++        Yes    Yes
NkFontDemo                   WindowedApp   C++        No     Yes
firsttriangle                WindowedApp   C++        No     Yes
NkFDV2                       WindowedApp   C++        No     Yes
NkFontDemo_Tests             TestSuite     C++        Yes    Yes
NkSpriteDemo_Tests           TestSuite     C++        Yes    Yes
NkRHIDemoFullImage_Tests     TestSuite     C++        Yes    Yes
NkSWRasterPrimitives         WindowedApp   C++        No     Yes
NKRHIDemo_Tests              TestSuite     C++        Yes    Yes
NkDrawableDemo_Tests         TestSuite     C++        Yes    Yes
cr2d                         WindowedApp   C++        No     Yes
NkRHIDemoFull_Tests          TestSuite     C++        Yes    Yes
NKRHIDemo                    WindowedApp   C++        No     Yes
Gamepad                      WindowedApp   C++        No     Yes
gltftest                     WindowedApp   C++        No     Yes
RendererRHI_Tests            TestSuite     C++        Yes    Yes
RendererRHI                  WindowedApp   C++        No     Yes
ConquerorProto               WindowedApp   C++        No     Yes
NkAudioDemo                  ConsoleApp    C++        No     Yes
NkCameraDemos                WindowedApp   C++        No     Yes
SandboxNKFileSystem          ConsoleApp    C++        No     Yes
SandboxNKLogger              ConsoleApp    C++        No     Yes
SandboxNKReflection          ConsoleApp    C++        No     Yes
SandboxNKNetwork             ConsoleApp    C++        No     Yes
NKRenderer_Tests             TestSuite     C++        Yes    Yes
NKRenderer                   StaticLib     C++        No     Yes
NKTensor_Tests               TestSuite     C++        Yes    Yes
NKTensor                     StaticLib     C++        No     Yes
NKAutograd                   StaticLib     C++        No     Yes
NKAutograd_Tests             TestSuite     C++        Yes    Yes
NKNN_Tests                   TestSuite     C++        Yes    Yes
NKNN                         StaticLib     C++        No     Yes
NKOptim                      StaticLib     C++        No     Yes
NKOptim_Tests                TestSuite     C++        Yes    Yes
NKData_Tests                 TestSuite     C++        Yes    Yes
NKData                       StaticLib     C++        No     Yes
NKTrain_Tests                TestSuite     C++        Yes    Yes
NKTrain                      StaticLib     C++        No     Yes
NKInfer_Tests                TestSuite     C++        Yes    Yes
NKInfer                      StaticLib     C++        No     Yes
NKRL                         StaticLib     C++        No     Yes
NKRL_Tests                   TestSuite     C++        Yes    Yes
NKAgent                      StaticLib     C++        No     Yes
NKAgent_Tests                TestSuite     C++        Yes    Yes
NKEvolve_Tests               TestSuite     C++        Yes    Yes
NKEvolve                     StaticLib     C++        No     Yes
NKCivilization_Tests         TestSuite     C++        Yes    Yes
NKCivilization               StaticLib     C++        No     Yes
NKEmbodied_Tests             TestSuite     C++        Yes    Yes
NKEmbodied                   StaticLib     C++        No     Yes
NKGen                        StaticLib     C++        No     Yes
NKGen_Tests                  TestSuite     C++        Yes    Yes
NKGpt                        StaticLib     C++        No     Yes
NKSpeech                     StaticLib     C++        No     Yes
NKTensorDemo                 ConsoleApp    C++        No     Yes
NkSLComputeCheck             ConsoleApp    C++        No     Yes
NkGpuProbe                   ConsoleApp    C++        No     Yes
NkComputeNkSL                ConsoleApp    C++        No     Yes
NkTensorGpuTest              ConsoleApp    C++        No     Yes
NKGpuBenchTest               ConsoleApp    C++        No     Yes
NKConvBenchTest              ConsoleApp    C++        No     Yes
NKConvResidentBench          ConsoleApp    C++        No     Yes
NKMlpResidentBench           ConsoleApp    C++        No     Yes
NKMnistGpuTrain              ConsoleApp    C++        No     Yes
NKRebasinTest                ConsoleApp    C++        No     Yes
NKMnistCnnGpuTrain           ConsoleApp    C++        No     Yes
NKTransformerTest            ConsoleApp    C++        No     Yes
NKGptTrain                   ConsoleApp    C++        No     Yes
NKIlyana                     ConsoleApp    C++        No     Yes
NKAutogradTest               ConsoleApp    C++        No     Yes
NKNNTest                     ConsoleApp    C++        No     Yes
NKConvTest                   ConsoleApp    C++        No     Yes
NKDataTest                   ConsoleApp    C++        No     Yes
NKBpeTest                    ConsoleApp    C++        No     Yes
NKLlamaBlockTest             ConsoleApp    C++        No     Yes
NKRebasinTransformer         ConsoleApp    C++        No     Yes
NKTrainTest                  ConsoleApp    C++        No     Yes
NKFp16Test                   ConsoleApp    C++        No     Yes
NKRnnCtcTest                 ConsoleApp    C++        No     Yes
NKASRTest                    ConsoleApp    C++        No     Yes
NKImageCodecTest             ConsoleApp    C++        No     Yes
NkEditableMeshDemo           ConsoleApp    C++        No     Yes
NkLocomotionDemo             ConsoleApp    C++        No     Yes
NkAssetIODemo                ConsoleApp    C++        No     Yes
NkFBXParityDemo              ConsoleApp    C++        No     Yes
NkSVGImportDemo              ConsoleApp    C++        No     Yes
NKMeshAITest                 ConsoleApp    C++        No     Yes
NKEditMeshHarness            ConsoleApp    C++        No     Yes
NkAnimPhysTest               ConsoleApp    C++        No     Yes
NkMicRecord                  ConsoleApp    C++        No     Yes
NKSpeechTest                 ConsoleApp    C++        No     Yes
NKTTSTrain                   ConsoleApp    C++        No     Yes
NkVoiceLoopDemo              ConsoleApp    C++        No     Yes
NKSpeechFeatureDemo          ConsoleApp    C++        No     Yes
NKMediaTest                  ConsoleApp    C++        No     Yes
NkVideoReadTest              ConsoleApp    C++        No     Yes
NkAudioPlayer                WindowedApp   C++        No     Yes
NkVideoPlayer                WindowedApp   C++        No     Yes
NKOpusRef                    ConsoleApp    C++        No     Yes
NKVideoTest                  ConsoleApp    C++        No     Yes
NKInferTest                  ConsoleApp    C++        No     Yes
NKGGUFInspectTest            ConsoleApp    C++        No     Yes
NKLLMInferTest               ConsoleApp    C++        No     Yes
NKQwenTokenizerTest          ConsoleApp    C++        No     Yes
NKQwen2BackwardTest          ConsoleApp    C++        No     Yes
NKQwen2SftTest               ConsoleApp    C++        No     Yes
NKQ4MatmulTest               ConsoleApp    C++        No     Yes
NKQwen2GpuTest               ConsoleApp    C++        No     Yes
NKQwen2Chat                  ConsoleApp    C++        No     Yes
NKQwen2SftGpuTest            ConsoleApp    C++        No     Yes
NKQwen2Train                 ConsoleApp    C++        No     Yes
NKQwen2Ask                   ConsoleApp    C++        No     Yes
NKRLTest                     ConsoleApp    C++        No     Yes
NKAgentTest                  ConsoleApp    C++        No     Yes
NKAgentLLMTest               ConsoleApp    C++        No     Yes
NkAgentEcsDemo               ConsoleApp    C++        No     Yes
NKEmbodiedTest               ConsoleApp    C++        No     Yes
NKEvolveTest                 ConsoleApp    C++        No     Yes
NKEvolveNNTest               ConsoleApp    C++        No     Yes
NKCivilizationTest           ConsoleApp    C++        No     Yes
NKCivilizationSocialTest     ConsoleApp    C++        No     Yes
NKCivilizationScaleTest      ConsoleApp    C++        No     Yes
NKGenTest                    ConsoleApp    C++        No     Yes
NKVAETest                    ConsoleApp    C++        No     Yes
NKMnistVAETest               ConsoleApp    C++        No     Yes
NKMnistConvVAETest           ConsoleApp    C++        No     Yes
NKConvVAETest                ConsoleApp    C++        No     Yes
NKDiffusionTest              ConsoleApp    C++        No     Yes
NKVoxelGenTest               ConsoleApp    C++        No     Yes
NKObjectGenTest              ConsoleApp    C++        No     Yes
NKGen3DTest                  ConsoleApp    C++        No     Yes
NKGenMeshTest                ConsoleApp    C++        No     Yes
NKSmoothMeshTest             ConsoleApp    C++        No     Yes
NKMatTypeResetTest           ConsoleApp    C++        No     Yes
NKMeshRenderTest             ConsoleApp    C++        No     Yes
Model                        WindowedApp   C++        No     Yes
NkSLCheck                    ConsoleApp    C++        No     Yes
NKPA                         WindowedApp   C++        No     Yes
NKECS_Tests                  TestSuite     C++        Yes    Yes
NKECS                        StaticLib     C++        No     Yes
Noge                         StaticLib     C++        No     Yes
Noge_Tests                   TestSuite     C++        Yes    Yes
Nogee                        WindowedApp   C++        No     Yes
NKEditorKitDemo              WindowedApp   C++        No     Yes
NKEditorKitTest              ConsoleApp    C++        No     Yes
NKUIDesign                   WindowedApp   C++        No     Yes
ConquerorLab                 WindowedApp   C++        No     Yes
NkRef                        WindowedApp   C++        No     Yes
NkAnimaEditor                WindowedApp   C++        No     Yes
ImGuiRef                     WindowedApp   C++        No     Yes
NKGuiDrawTest                ConsoleApp    C++        No     Yes
NKGuiDemo                    WindowedApp   C++        No     Yes
NKViewportDemo               WindowedApp   C++        No     Yes
PV3DE                        WindowedApp   C++        No     Yes
Pong                         WindowedApp   C++        No     Yes
Nkoung                       WindowedApp   C++        No     Yes
Mou                          WindowedApp   C++        No     Yes
NkImeTest                    WindowedApp   C++        No     Yes
NkImageDemo                  WindowedApp   C++        No     Yes
RihenDefi                    WindowedApp   C++        No     Yes
NkAudioECSDemo               ConsoleApp    C++        No     Yes
NkNetWorldDemo               ConsoleApp    C++        No     Yes
NkNavDemo                    ConsoleApp    C++        No     Yes
NkNavCoreDemo                ConsoleApp    C++        No     Yes
NkHotReloadDemo              ConsoleApp    C++        No     Yes
NkUIHudDemo                  ConsoleApp    C++        No     Yes
Tuto05Meshes                 WindowedApp   C++        No     Yes
Tuto01Fenetre                WindowedApp   C++        No     Yes
Tuto03Scene                  WindowedApp   C++        No     Yes
Tuto04Camera                 WindowedApp   C++        No     Yes
Tuto02Renderer               WindowedApp   C++        No     Yes
NKXRDemo                     WindowedApp   C++        No     Yes
NKARDemo                     WindowedApp   C++        No     Yes
GemCrush                     WindowedApp   C++        No     Yes


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
✓   [3/12] Compiled: NkRecursiveMutex.cpp
✓   [4/12] Compiled: NkConditionVariable.cpp
✓   [5/12] Compiled: NkMutex.cpp
✓   [6/12] Compiled: NkThread.cpp
✓   [7/12] Compiled: NkSpinLock.cpp
✓   [8/12] Compiled: NkBarrier.cpp
✓   [9/12] Compiled: NkEvent.cpp
✓   [10/12] Compiled: NkReaderWriterLock.cpp
✓   [11/12] Compiled: NkLatch.cpp
✓   [12/12] Compiled: NkThreadPool.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKThreading.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLogLevel.cpp
✓   [2/14] Compiled: NkLoggerFormatter.cpp
✓   [3/14] Compiled: NkSink.cpp
✓   [4/14] Compiled: NkRegistry.cpp
✓   [5/14] Compiled: NkLogMessage.cpp
✓   [6/14] Compiled: NkLog.cpp
✓   [7/14] Compiled: NkLogger.cpp
✓   [8/14] Compiled: NkAsyncSink.cpp
✓   [9/14] Compiled: NkConsoleSink.cpp
✓   [10/14] Compiled: NkDailyFileSink.cpp
✓   [11/14] Compiled: NkFileSink.cpp
✓   [12/14] Compiled: NkDistributingSink.cpp
✓   [13/14] Compiled: NkNullSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKLogger.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.80s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCollision                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkCollisionWorld.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCollision.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKLogger                                                 Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKLogger\SandboxNKLogger.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKReflection                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkType.cpp
✓   [2/7] Compiled: NkInspector.cpp
✓   [3/7] Compiled: NkProperty.cpp
✓   [4/7] Compiled: NkMethod.cpp
✓   [5/7] Compiled: NkRegistry.cpp
✓   [6/7] Compiled: NkClass.cpp
✓   [7/7] Compiled: NkReflection.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKReflection.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvolve                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkPopulation.cpp
✓   [2/2] Compiled: NkEvolution.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKEvolve.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.48s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkFileWatcher.cpp
✓   [2/5] Compiled: NkPath.cpp
✓   [3/5] Compiled: NkFileSystem.cpp
✓   [4/5] Compiled: NkFile.cpp
✓   [5/5] Compiled: NkDirectory.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKFileSystem.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontDetect.cpp
✓   [2/8] Compiled: NkFontSizeCache.cpp
✓   [3/8] Compiled: NkUtils.cpp
✓   [4/8] Compiled: NkFontRasterizer.cpp
✓   [5/8] Compiled: NkFontParser.cpp
✓   [6/8] Compiled: NkFontAtlas.cpp
✓   [7/8] Compiled: NkFontMesh.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKFont.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.61s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimPhysics                                                    Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 6 source file(s)
✓   [1/6] Compiled: NkContactDetector.cpp
✓   [2/6] Compiled: NkBalance.cpp
✓   [3/6] Compiled: NkClipBalancePass.cpp
✓   [4/6] Compiled: NkAutoPose.cpp
✓   [5/6] Compiled: NkPoseBalancer.cpp
✓   [6/6] Compiled: NkPoseMass.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKAnimPhysics.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.50s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkDate.cpp
✓   [2/8] Compiled: NkTimeZone.cpp
✓   [3/8] Compiled: NkClock.cpp
✓   [4/8] Compiled: NkTimeSpan.cpp
✓   [5/8] Compiled: NkDuration.cpp
✓   [6/8] Compiled: NkSystemClock.cpp
✓   [7/8] Compiled: NkChrono.cpp
✓   [8/8] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKTime.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.76s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeech                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkG2P.cpp
✓   [2/5] Compiled: NkTextNorm.cpp
✓   [3/5] Compiled: NkGriffinLim.cpp
✓   [4/5] Compiled: NkAudioFeatures.cpp
✓   [5/5] Compiled: NkVoiceSynth.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKSpeech.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPhysics                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkIntegrator.cpp
✓   [2/2] Compiled: NkPhysicsWorld.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPhysics.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.84s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNavigation                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkNavMesh.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKNavigation.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.45s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKReflection                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled with warnings: main.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                      Warning: main.cpp                                       ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Sandbox\System\NKReflection\src\main.cp ║
║ p:22:9: warning: 'offsetof' on non-standard-layout type 'SelfType' (aka '(anonymous          ║
║ namespace)::DemoObject') [-Winvalid-offsetof]                                                ║
║    22 |         NKENTSEU_REFLECT_PROPERTY(value)                                             ║
║       |         ^                         ~~~~~                                              ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKReflection\src/NKReflec ║
║ tion/NkRegistry.h:525:49: note: expanded from macro 'NKENTSEU_REFLECT_PROPERTY'              ║
║ 525 | #define NKENTSEU_REFLECT_PROPERTY(PropertyName)                                        ║
║ NKENTSEU_REFLECT_PROPERTY_FLAGS(PropertyName, 0ULL)                                          ║
║ |                                                 ^                                          ║
║ ~~~~~~~~~~~~                                                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKReflection\src/NKReflec ║
║ tion/NkRegistry.h:546:4: note: expanded from macro 'NKENTSEU_REFLECT_PROPERTY_FLAGS'         ║
║ 546 |                         offsetof(SelfType, PropertyName));                             ║
║ \                                                                                            ║
║       |                         ^                  ~~~~~~~~~~~~                              ║
║ C:/msys64/ucrt64/lib/clang/21/include/__stddef_offsetof.h:16:24: note: expanded from macro   ║
║ 'offsetof'                                                                                   ║
║    16 | #define offsetof(t, d) __builtin_offsetof(t, d)                                      ║
║       |                        ^                     ~                                       ║
║ 1 warning generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKReflection\SandboxNKReflection.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.62s  │
│ Warnings: 2                                                                                  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKFileSystem                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKFileSystem\SandboxNKFileSystem.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.57s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkConsoleStream.cpp
✓   [2/4] Compiled: NkBinaryStream.cpp
✓   [3/4] Compiled: NkStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKStream.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimation                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkMotionPath.cpp
✓   [2/4] Compiled: NkAnimationEditor.cpp
✓   [3/4] Compiled: NkAnimRetarget.cpp
✓   [4/4] Compiled: NkAnimation.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKAnimation.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.55s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSL                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 46 source file(s)
✓   [1/46] Compiled: NkSLCodeGenCPP.cpp
✓   [2/46] Compiled: NkSLCodeGenCPP.cpp
✓   [3/46] Compiled: NkSLCodeGenBytecode.cpp
✓   [4/46] Compiled: NkSLCodeGenBytecode.cpp
✓   [5/46] Compiled: NkSLCodeGenGLSL.cpp
✓   [6/46] Compiled: NkSLCodeGenGLSLVulkan.cpp
✓   [7/46] Compiled: NkSLCodeGenGLSLVulkan.cpp
✓   [8/46] Compiled: NkSLCodeGenGLSL.cpp
✓   [9/46] Compiled: NkSLCodeGenHLSL.cpp
✓   [10/46] Compiled: NkSLCodeGenHLSL.cpp
✓   [11/46] Compiled: NkSLCodeGenHLSLStructs.cpp
✓   [12/46] Compiled: NkSLCodeGenAdvanced.cpp
✓   [13/46] Compiled: NkSLCodeGenAdvanced.cpp
✓   [14/46] Compiled: NkSLCodeGenHLSLDX12.cpp
✓   [15/46] Compiled: NkSLCodeGenHLSLDX12.cpp
✓   [16/46] Compiled: NkSLCodeGenHLSLStructs.cpp
✓   [17/46] Compiled: NkSLCodeGenMSL.cpp
✓   [18/46] Compiled: NkSLCodeGenMSL.cpp
✓   [19/46] Compiled: NkSLCodeGenMSLSpirvCross.cpp
✓   [20/46] Compiled: NkSLCodeGenMSLSpirvCross.cpp
✓   [21/46] Compiled: NkSLCompiler.cpp
✓   [22/46] Compiled: NkSLLexer.cpp
✓   [23/46] Compiled: NkSLCompiler.cpp
✓   [24/46] Compiled: NkSLFeatures.cpp
✓   [25/46] Compiled: NkGLSLCompiler.cpp
✓   [26/46] Compiled: NkGLSLCompiler.cpp
✓   [27/46] Compiled: NkSLLexer.cpp
✓   [28/46] Compiled: NkSLParser.cpp
✓   [29/46] Compiled: NkSLParser.cpp
✓   [30/46] Compiled: NkSLFeatures.cpp
✓   [31/46] Compiled: NkSLSymbolTable.cpp
✓   [32/46] Compiled: NkSLSemantic.cpp
✓   [33/46] Compiled: NkSLSymbolTable.cpp
✓   [34/46] Compiled: NkSLSemantic.cpp
✓   [35/46] Compiled: NkSLReflector.cpp
✓   [36/46] Compiled: NkSLReflector.cpp
✓   [37/46] Compiled: NkSLByteCodeIO.cpp
✓   [38/46] Compiled: NkSLByteCodeIO.cpp
✓   [39/46] Compiled: NkShaderAnnotations.cpp
✓   [40/46] Compiled: NkShaderAnnotations.cpp
✓   [41/46] Compiled: NkShaderAnnotations.cpp
✓   [42/46] Compiled: NkSLVM.cpp
✓   [43/46] Compiled: NkSLVM.cpp
✓   [44/46] Compiled: NkShaderConvert.cpp
✓   [45/46] Compiled: NkShaderConvert.cpp
✓   [46/46] Compiled: NkShaderConvert.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKSL.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 21.59s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSerialization                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkJSONValue.cpp
✓   [2/12] Compiled: NkBinaryWriter.cpp
✓   [3/12] Compiled: NkJSONWriter.cpp
✓   [4/12] Compiled: NkBinaryReader.cpp
✓   [5/12] Compiled: NkISerializable.cpp
✓   [6/12] Compiled: NkJSONReader.cpp
✓   [7/12] Compiled: NkArchive.cpp
✓   [8/12] Compiled: NkXMLWriter.cpp
✓   [9/12] Compiled: NkXMLReader.cpp
✓   [10/12] Compiled: NkYAMLWriter.cpp
✓   [11/12] Compiled: NkYAMLReader.cpp
✓   [12/12] Compiled: NkReflectSerializer.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKSerialization.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.86s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNetwork                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkNetDefines.cpp
✓   [2/10] Compiled: NkNetWorld.cpp
✓   [3/10] Compiled: NkRPC.cpp
✓   [4/10] Compiled: NkBitStream.cpp
✓   [5/10] Compiled with warnings: NkLobby.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                     Warning: NkLobby.cpp                                     ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\L ║
║ obby\NkLobby.cpp:581:4: warning: ignoring return value of function declared with 'nodiscard' ║
║ attribute [-Wunused-result]                                                                  ║
║ 581 |                         mConnMgr.Broadcast(buffer, totalSize,                          ║
║ NkNetChannel::NK_NET_CHANNEL_RELIABLE_ORDERED);                                              ║
║       |                         ^~~~~~~~~~~~~~~~~~                                           ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\L ║
║ obby\NkLobby.cpp:699:4: warning: ignoring return value of function declared with 'nodiscard' ║
║ attribute [-Wunused-result]                                                                  ║
║ 699 |                         mSession.GetConnMgr()->Broadcast(buffer,                       ║
║ NkLobbyMessageHeader::kSize + writer.BytesWritten(),                                         ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\L ║
║ obby\NkLobby.cpp:770:4: warning: ignoring return value of function declared with 'nodiscard' ║
║ attribute [-Wunused-result]                                                                  ║
║ 770 |                         mSession.GetConnMgr()->Broadcast(buffer,                       ║
║ NkLobbyMessageHeader::kSize + writer.BytesWritten(),                                         ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\L ║
║ obby\NkLobby.cpp:927:4: warning: ignoring return value of function declared with 'nodiscard' ║
║ attribute [-Wunused-result]                                                                  ║
║   927 |                         socket.SetBroadcast(true);                                   ║
║       |                         ^~~~~~~~~~~~~~~~~~~ ~~~~                                     ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\L ║
║ obby\NkLobby.cpp:968:4: warning: ignoring return value of function declared with 'nodiscard' ║
║ attribute [-Wunused-result]                                                                  ║
║   968 |                         socket.SetBroadcast(true);                                   ║
║       |                         ^~~~~~~~~~~~~~~~~~~ ~~~~                                     ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\L ║
║ obby\NkLobby.cpp:969:4: warning: ignoring return value of function declared with 'nodiscard' ║
║ attribute [-Wunused-result]                                                                  ║
║   969 |                         socket.SetNonBlocking(true);                                 ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~ ~~~~                                   ║
║ 6 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [6/10] Compiled with warnings: NkConnection.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkConnection.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:820:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ 820 |                         mRUDP.Send(buffer, NkSystemHeader::kSize,                      ║
║ NkNetChannel::NK_NET_CHANNEL_UNRELIABLE);                                                    ║
║ |                         ^~~~~~~~~~                                                         ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                       ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:840:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ 840 |                         mRUDP.Send(buffer, NkSystemHeader::kSize,                      ║
║ NkNetChannel::NK_NET_CHANNEL_UNRELIABLE);                                                    ║
║ |                         ^~~~~~~~~~                                                         ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                       ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:916:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   916 |                         mSocket.SetNonBlocking(true);                                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~ ~~~~                                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:917:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   917 |                         mSocket.SetRecvBufferSize(kNkRecvBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:918:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   918 |                         mSocket.SetSendBufferSize(kNkSendBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:954:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   954 |                         mSocket.SetNonBlocking(true);                                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~ ~~~~                                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:955:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   955 |                         mSocket.SetRecvBufferSize(kNkRecvBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:956:4: warning: ignoring return value of function declared with     ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   956 |                         mSocket.SetSendBufferSize(kNkSendBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:1133:5: warning: ignoring return value of function declared with    ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║  1133 |                                 conn->Disconnect(reason);                            ║
║       |                                 ^~~~~~~~~~~~~~~~ ~~~~~~                              ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\P ║
║ rotocol\NkConnection.cpp:1142:6: warning: ignoring return value of function declared with    ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║  1142 |                                         mConnections[i]->Disconnect(reason);         ║
║       |                                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~           ║
║ 10 warnings generated.                                                                       ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [7/10] Compiled with warnings: NkHTTPClient.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkHTTPClient.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\H ║
║ TTP\NkHTTPClient.cpp:46:9: warning: 'NOMINMAX' macro redefined [-Wmacro-redefined]           ║
║    46 | #define NOMINMAX                                                                     ║
║       |         ^                                                                            ║
║ C:/msys64/ucrt64/include/c++/15.2.0/x86_64-w64-mingw32/bits/os_defines.h:45:9: note:         ║
║ previous definition is here                                                                  ║
║    45 | #define NOMINMAX 1                                                                   ║
║       |         ^                                                                            ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\H ║
║ TTP\NkHTTPClient.cpp:891:4: warning: ignoring return value of function declared with         ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   891 |                         ParseURL(req.url, scheme, host, port, path);                 ║
║       |                         ^~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                   ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\H ║
║ TTP\NkHTTPClient.cpp:1316:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║  1316 |                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {      ║
║       |                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1317 |                                 bool success = !resp.HasError() && resp.IsOK();      ║
║       |                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1318 |                                 if (cb) {                                            ║
║       |                                 ~~~~~~~~~                                            ║
║  1319 |                                         cb(success);                                 ║
║       |                                         ~~~~~~~~~~~~                                 ║
║  1320 |                                 }                                                    ║
║       |                                 ~                                                    ║
║  1321 |                         });                                                          ║
║       |                         ~                                                            ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\H ║
║ TTP\NkHTTPClient.cpp:1333:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║  1333 |                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {      ║
║       |                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1334 |                                 NkVector<NkLeaderboardEntry> entries;                ║
║       |                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                ║
║ 1335 |                                 if (!resp.HasError() && resp.IsOK() &&                ║
║ !resp.body.Empty()) {                                                                        ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                 ║
║ 1336 |                                         // Parsing JSON simplifié — en production     ║
║ utiliser un vrai parser                                                                      ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                            ║
║ 1337 |                                         // Exemple attendu :                          ║
║ [{"player":"Alice","score":1000,"rank":1},...]                                               ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                          ║
║  1338 |                                         ParseLeaderboardJSON(resp.body, entries);    ║
║       |                                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    ║
║  1339 |                                 }                                                    ║
║       |                                 ~                                                    ║
║  1340 |                                 cb(entries);                                         ║
║       |                                 ~~~~~~~~~~~~                                         ║
║  1341 |                         });                                                          ║
║       |                         ~                                                            ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\H ║
║ TTP\NkHTTPClient.cpp:1354:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║  1354 |                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {      ║
║       |                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1355 |                                 uint32 rank = 0;                                     ║
║       |                                 ~~~~~~~~~~~~~~~~                                     ║
║  1356 |                                 uint64 score = 0;                                    ║
║       |                                 ~~~~~~~~~~~~~~~~~                                    ║
║ 1357 |                                 if (!resp.HasError() && resp.IsOK() &&                ║
║ !resp.body.Empty()) {                                                                        ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                 ║
║  1358 |                                         // Parsing JSON simplifié                    ║
║       |                                         ~~~~~~~~~~~~~~~~~~~~~~~~~                    ║
║  1359 |                                         ParsePlayerRankJSON(resp.body, rank, score); ║
║       |                                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║
║  1360 |                                 }                                                    ║
║       |                                 ~                                                    ║
║  1361 |                                 cb(rank, score);                                     ║
║       |                                 ~~~~~~~~~~~~~~~~                                     ║
║  1362 |                         });                                                          ║
║       |                         ~                                                            ║
║ 5 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [8/10] Compiled with warnings: NkReliableUDP.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkReliableUDP.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\T ║
║ ransport\NkReliableUDP.cpp:483:6: warning: ignoring return value of function declared with   ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ 483 |                                         mSocket->SendTo(buffer, NkRUDPHeader::kSize +  ║
║ entry->size, mRemote);                                                                       ║
║ |                                         ^~~~~~~~~~~~~~~                                    ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                           ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\T ║
║ ransport\NkReliableUDP.cpp:509:6: warning: ignoring return value of function declared with   ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ 509 |                                         mSocket->SendTo(buffer, NkRUDPHeader::kSize +  ║
║ entry->size, mRemote);                                                                       ║
║ |                                         ^~~~~~~~~~~~~~~                                    ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                           ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\T ║
║ ransport\NkReliableUDP.cpp:520:5: warning: ignoring return value of function declared with   ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   520 |                                 SendACK();                                           ║
║       |                                 ^~~~~~~                                              ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\T ║
║ ransport\NkReliableUDP.cpp:543:5: warning: ignoring return value of function declared with   ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ 543 |                                 mSocket->SendTo(buffer, NkRUDPHeader::kSize, mRemote); ║
║       |                                 ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║
║ 4 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [9/10] Compiled: NkWebSocketServer.cpp
✓   [10/10] Compiled with warnings: NkSocket.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                    Warning: NkSocket.cpp                                     ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\T ║
║ ransport\NkSocket.cpp:573:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   573 |                         SetSendBufferSize(kNkSendBufferSize);                        ║
║       |                         ^~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\T ║
║ ransport\NkSocket.cpp:574:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║   574 |                         SetRecvBufferSize(kNkRecvBufferSize);                        ║
║       |                         ^~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ 2 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKNetwork.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 8.26s  │
│ Warnings: 27                                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkEventState.cpp
✓   [3/10] Compiled: NkDropSystem.cpp
✓   [4/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [5/10] Compiled: NkEventDispatcher.cpp
✓   [6/10] Compiled: NkEventSystem.cpp
✓   [7/10] Compiled: NkGamepadSystem.cpp
✓   [8/10] Compiled: NkKeyboardEvent.cpp
✓   [9/10] Compiled: NkMouseEvent.cpp
✓   [10/10] Compiled: NkWindowEvent.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKEvent.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.46s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeechTest                                                    Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NKSpeechTest\NKSpeechTest.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.84s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkNavCoreDemo                                                   Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkNavCoreDemo\NkNavCoreDemo.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.55s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkPNGCodec.cpp
✓   [2/13] Compiled: NkICOCodec.cpp
✓   [3/13] Compiled: NkBMPCodec.cpp
✓   [4/13] Compiled: NkJPEGCodec.cpp
✓   [5/13] Compiled: NkHDRCodec.cpp
✓   [6/13] Compiled: NkGIFCodec.cpp
✓   [7/13] Compiled: NkEXRCodec.cpp
✓   [8/13] Compiled: NkPPMCodec.cpp
✓   [9/13] Compiled: NkQOICodec.cpp
✓   [10/13] Compiled: NkWebPCodec.cpp
✓   [11/13] Compiled: NkTGACodec.cpp
✓   [12/13] Compiled: NkSVGCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKImage.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.47s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: FontLoad                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: main.cpp
✓   [2/2] Compiled: NkFont.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\FontLoad\FontLoad.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.64s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLComputeCheck                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkSLComputeCheck\NkSLComputeCheck.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLCheck                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkSLCheck\NkSLCheck.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.46s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKECS                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkGameplayEventBus.cpp
✓   [2/2] Compiled: NkWorld.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKECS.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.14s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKNetwork                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled with warnings: main.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                      Warning: main.cpp                                       ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Sandbox\System\NKNetwork\src\main.cpp:4 ║
║ 49:6: warning: format specifies type 'unsigned int' but the argument has type 'SizeType'     ║
║ (aka 'unsigned long long') [-Wformat]                                                        ║
║ 448 |                 std::printf("[HTTPS] %s -> status=%u bodyLen=%u error='%s'\n",         ║
║ argv[2], resp.statusCode,                                                                    ║
║       |                                                              ~~                      ║
║       |                                                              %llu                    ║
║   449 |                                         resp.body.Length(), resp.error.CStr());      ║
║       |                                         ^~~~~~~~~~~~~~~~~~                           ║
║ 1 warning generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKNetwork\SandboxNKNetwork.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.71s  │
│ Warnings: 2                                                                                  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkWindowClipboard.cpp
✓   [3/9] Compiled: NkWindowClipboardImage.cpp
✓   [4/9] Compiled: NkContext.cpp
✓   [5/9] Compiled: NkWindowCursor.cpp
✓   [6/9] Compiled: NkDialogs.cpp
✓   [7/9] Compiled: NkWESystem.cpp
✓   [8/9] Compiled: NkWin32EventSystem.cpp
✓   [9/9] Compiled: NkWin32Window.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKWindow.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.87s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImageCodecTest                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NKImageCodecTest\NKImageCodecTest.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUI                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 17 source file(s)
✓   [1/17] Compiled: NkUIAnimation.cpp
✓   [2/17] Compiled: NkUIDrawList.cpp
✓   [3/17] Compiled: NkUILayout.cpp
✓   [4/17] Compiled: NkUIFontBridge.cpp
✓   [5/17] Compiled: NkUIContext.cpp
✓   [6/17] Compiled: NkUIDock.cpp
✓   [7/17] Compiled: NkUIFont.cpp
✓   [8/17] Compiled: NkUIMath.cpp
✓   [9/17] Compiled: NkUILayout2.cpp
✓   [10/17] Compiled: NkUIMenu.cpp
✓   [11/17] Compiled: NkUIRenderer.cpp
✓   [12/17] Compiled: NkUIWindow.cpp
✓   [13/17] Compiled: NkUIWidgets.cpp
✓   [14/17] Compiled: NkUIFileBrowser.cpp
✓   [15/17] Compiled: NkUIGizmo.cpp
✓   [16/17] Compiled: NkUITree.cpp
✓   [17/17] Compiled: NkUIViewport3D.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKUI.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.73s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGui                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkGuiIcons.cpp
✓   [2/5] Compiled: NkGuiFont.cpp
✓   [3/5] Compiled: NkGuiDrawList.cpp
✓   [4/5] Compiled: NkGuiContext.cpp
✓   [5/5] Compiled: NkGuiWidgets.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKGui.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.61s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMedia                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 82 source file(s)
✓   [1/82] Compiled: NkAacHuffmanTables.cpp
✓   [2/82] Compiled: NkWavWriter.cpp
✓   [3/82] Compiled: NkAacBitReader.cpp
✓   [4/82] Compiled: NkAacHuffman.cpp
✓   [5/82] Compiled: NkAacDequant.cpp
✓   [6/82] Compiled: NkAacFilterbank.cpp
✓   [7/82] Compiled: NkAacDecoder.cpp
✓   [8/82] Compiled: NkAacTns.cpp
✓   [9/82] Compiled: NkAacIcs.cpp
✓   [10/82] Compiled: NkCeltBands.cpp
✓   [11/82] Compiled: NkCeltAlloc.cpp
✓   [12/82] Compiled: NkAacTables.cpp
✓   [13/82] Compiled: NkCeltDeemphasis.cpp
✓   [14/82] Compiled: NkCeltAntiCollapse.cpp
✓   [15/82] Compiled: NkCeltEnergy.cpp
✓   [16/82] Compiled: NkCeltPvq.cpp
✓   [17/82] Compiled: NkCeltDenorm.cpp
✓   [18/82] Compiled: NkCeltLaplace.cpp
✓   [19/82] Compiled: NkCeltDecoder.cpp
✓   [20/82] Compiled: NkCeltRate.cpp
✓   [21/82] Compiled: NkCeltMdct.cpp
✓   [22/82] Compiled: NkOpusDecoder.cpp
✓   [23/82] Compiled: NkOpusPacket.cpp
✓   [24/82] Compiled: NkCeltQuantBands.cpp
✓   [25/82] Compiled: NkCeltSplit.cpp
✓   [26/82] Compiled: NkCeltVq.cpp
✓   [27/82] Compiled: NkOpusRange.cpp
✓   [28/82] Compiled: NkSilkExcitationTables.cpp
✓   [29/82] Compiled: NkAmrDecoder.cpp
✓   [30/82] Compiled: NkSilkDecoder.cpp
✓   [31/82] Compiled: NkSilkExcitation.cpp
✓   [32/82] Compiled: NkSilkFrameType.cpp
✓   [33/82] Compiled: NkSilkGains.cpp
✓   [34/82] Compiled: NkSilkIndices.cpp
✓   [35/82] Compiled: NkSilkIndicesTables.cpp
✓   [36/82] Compiled: NkSilkLtp.cpp
✓   [37/82] Compiled: NkSilkLpc.cpp
✓   [38/82] Compiled: NkSilkLtpTables.cpp
✓   [39/82] Compiled: NkSilkMath.cpp
✓   [40/82] Compiled: NkSilkNlsf.cpp
✓   [41/82] Compiled: NkSilkNlsfTables.cpp
✓   [42/82] Compiled: NkSilkResampler.cpp
✓   [43/82] Compiled: NkSilkSynthesis.cpp
✓   [44/82] Compiled: NkSilkTop.cpp
✓   [45/82] Compiled: NkH264Transform.cpp
✓   [46/82] Compiled: NkH264Cavlc.cpp
✓   [47/82] Compiled: NkH264Decoder.cpp
✓   [48/82] Compiled: NkHevcCabac.cpp
✓   [49/82] Compiled: NkOpusFile.cpp
✓   [50/82] Compiled: NkH264Encoder.cpp
✓   [51/82] Compiled: NkMpeg1Tables.cpp
✓   [52/82] Compiled: NkHevcDecoder.cpp
✓   [53/82] Compiled: NkH264IntraDecoder.cpp
✓   [54/82] Compiled: NkAv1Decoder.cpp
✓   [55/82] Compiled: NkMpeg1Encoder.cpp
✓   [56/82] Compiled: NkMpeg2Decoder.cpp
✓   [57/82] Compiled: NkTheoraDecoder.cpp
✓   [58/82] Compiled: NkVp9Itxfm.cpp
✓   [59/82] Compiled: NkMediaDemux.cpp
✓   [60/82] Compiled: NkVp8Decoder.cpp
✓   [61/82] Compiled: NkMediaProbe.cpp
✓   [62/82] Compiled: NkVp9Decoder.cpp
✓   [63/82] Compiled: NkPdfGlyphList.cpp
✓   [64/82] Compiled: NkPdfInfo.cpp
✓   [65/82] Compiled: NkPdfRaster.cpp
✓   [66/82] Compiled: NkHevcCtu.cpp
✓   [67/82] Compiled: NkPdfShading.cpp
✓   [68/82] Compiled: NkPdf.cpp
✓   [69/82] Compiled: NkPdfColonnes.cpp
✓   [70/82] Compiled: NkAviWriter.cpp
✓   [71/82] Compiled: NkPdfFont.cpp
✓   [72/82] Compiled: NkMovWriter.cpp
✓   [73/82] Compiled: NkWebmWriter.cpp
✓   [74/82] Compiled: NkMp4H264Writer.cpp
✓   [75/82] Compiled: NkPdfLoad.cpp
✓   [76/82] Compiled: NkPdfRender.cpp
✓   [77/82] Compiled: NkPdfStruct.cpp
✓   [78/82] Compiled: NkVideoRecorder.cpp
✓   [79/82] Compiled: NkImageSequenceWriter.cpp
✓   [80/82] Compiled: NkVideoConverter.cpp
✓   [81/82] Compiled: NkVideoWriter.cpp
✓   [82/82] Compiled: NkVideoReader.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMedia.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 15.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKXR                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkArFlow.cpp
✓   [2/10] Compiled: NkArImu.cpp
✓   [3/10] Compiled: NkArSession.cpp
✓   [4/10] Compiled: NkArCalibration.cpp
✓   [5/10] Compiled: NkArWorld.cpp
✓   [6/10] Compiled: NkArMarker.cpp

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
✓   [8/10] Compiled: NkXrConfigEnv.cpp
✓   [9/10] Compiled: NkXrSession.cpp
✓   [10/10] Compiled: NkXrSimulatorBackend.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 7.71s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  44/207
Failed:         1
Not reached:    162  (arret au premier echec — voir --keep-going)
Errors:         2
Warnings:       31
Time:           4m45.2s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKXR
```
MonEssaie                    WindowedApp   C++        No     Yes
```