# EXERCICE 12:

* La ligne qui desactive la compilation de test dans Le workspace est dutc(enable=True) .sert à activer la compilation des tests unitaires dans la configuration du workspace. DUTC signifie quelque chose comme Disable/Enable Unit Test Compilation.

* L'exécution est également désactivée avec dute(enable=True) .

* Pour lancer malgré tout la suite de tests de NKMath, j'ai utilisé 

```
test --project NKMath_Tests --force.
```

Le workspace contient 61 suites de tests. La suite NKMath_Tests a été sélectionnée, mais 0 suite n'a pu être exécutée et 0 n'a réussi, car sa compilation a échoué.

L'erreur provient de test_smoke.cpp, car NkRect est inconnu.

Jenga a néanmoins construit les 6 projets précédents sur les 7 de l'ordre de construction avant de s'arrêter.

````

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
Building NKMath_Tests...
Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
ℹ Workspace policy disableunittestcompilation lifted for this invocation (--force).

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (7 projects):
  1. __Unitest__ [STATIC_LIB] → 
  2. NKPlatform [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKMath_Tests [TEST_SUITE] (depends: NKMath, __Unitest__, NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: __Unitest__                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: TestLauncher.cpp
✓   [2/11] Compiled: TestAssert.cpp
✓   [3/11] Compiled: ConsoleReport.cpp
✓   [4/11] Compiled: TestCase.cpp
✓   [5/11] Compiled: TestAggregator.cpp
✓   [6/11] Compiled: Benchmark.cpp
✓   [7/11] Compiled: Unitest.cpp
✓   [8/11] Compiled: Profiler.cpp
✓   [9/11] Compiled: PerformanceReporter.cpp
✓   [10/11] Compiled: TestReporter.cpp
✓   [11/11] Compiled: TestRunner.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\__Unitest__\Unitest.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 8.24s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkCPUFeatures.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.32s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkTraits.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.98s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGc.cpp
✓   [2/14] Compiled: NkProfiler.cpp
✓   [3/14] Compiled: NkMultiLevelAllocator.cpp
✓   [4/14] Compiled: NkMemory.cpp
✓   [5/14] Compiled: NkGlobalOperators.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkFunction.cpp
✓   [9/14] Compiled: NkContainerAllocator.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkTag.cpp
✓   [12/14] Compiled: NkUtils.cpp
✓   [13/14] Compiled: NkTracker.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.32s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkPair.cpp
✓   [2/43] Compiled: NkFunctional.cpp
✓   [3/43] Compiled: NkUnorderedSet.cpp
✓   [4/43] Compiled: NkBasicString.cpp
✓   [5/43] Compiled: NkUnorderedMap.cpp
✓   [6/43] Compiled: NkPool.cpp
✓   [7/43] Compiled: NkBase64.cpp
✓   [8/43] Compiled: NkGraph.cpp
✓   [9/43] Compiled: NkString.cpp
✓   [10/43] Compiled: NkStringBuilder.cpp
✓   [11/43] Compiled: NkUTF32.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkUTF16.cpp
✓   [14/43] Compiled: NkASCII.cpp
✓   [15/43] Compiled: NkVector.cpp
✓   [16/43] Compiled: NkEncoding.cpp
✓   [17/43] Compiled: NkPriorityQueue.cpp
✓   [18/43] Compiled: NkUTF8.cpp
✓   [19/43] Compiled: NkFunction.cpp
✓   [20/43] Compiled: NkArray.cpp
✓   [21/43] Compiled: NkIterator.cpp
✓   [22/43] Compiled: NkDoubleList.cpp
✓   [23/43] Compiled: NkSet.cpp
✓   [24/43] Compiled: NkDeque.cpp
✓   [25/43] Compiled: NkTuple.cpp
✓   [26/43] Compiled: NkBind.cpp
✓   [27/43] Compiled: NkBinaryTree.cpp
✓   [28/43] Compiled: NkInitializerList.cpp
✓   [29/43] Compiled: NkQuadTree.cpp
✓   [30/43] Compiled: NkMap.cpp
✓   [31/43] Compiled: NkStringHash.cpp
✓   [32/43] Compiled: NkFormat.cpp
✓   [33/43] Compiled: NkTrie.cpp
✓   [34/43] Compiled: NkHashMap.cpp
✓   [35/43] Compiled: NkContainers.cpp
✓   [36/43] Compiled: NkList.cpp
✓   [37/43] Compiled: NkBTree.cpp
✓   [38/43] Compiled: NkOptional.cpp
✓   [39/43] Compiled: NkStringView.cpp
✓   [40/43] Compiled: NkResult.cpp
✓   [41/43] Compiled: NkStringUtils.cpp
✓   [42/43] Compiled: NkVariant.cpp
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkFunctions.cpp
✓   [3/12] Compiled: NkEulerAngle.cpp
✓   [4/12] Compiled: NkColor.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRange.cpp
✓   [8/12] Compiled: NkSIMD.cpp
✓   [9/12] Compiled: NkRandom.cpp
✓   [10/12] Compiled: NkRectangle.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.26s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath_Tests                                                     Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 3 source file(s)
✓   [1/3] Compiled: Entry.cpp
✓   [2/3] Compiled: benchmark_smoke.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                              Compilation Error: test_smoke.cpp                               ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ test_smoke.cpp:24:2: error: unknown type     ║
║ name 'NkRect'                                                                                ║
║    24 |         NkRect r(10, 20, 100, 50);                                                   ║
║       |         ^                                                                            ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

test_smoke.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 1.72s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/7
Failed:         1
Errors:         2
Time:           21.12s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMath_Tests
```



