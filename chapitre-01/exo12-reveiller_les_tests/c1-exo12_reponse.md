# EXERCICE 12:

* La ligne qui desactive la compilation de test est la suivante :
```
 dutc(enable=True)
 dute(enable=True)
```
car dutc signifie ( Disable/Enable Unit Test Compilation ) et il
sert à activer la compilation des tests unitaires dans la configuration du workspace.

* j'utilise la commande   
 ```jenga build --target NKContainers_Tests --force-tests ```  
pour lancer la suite de tests de NKCountains

* resultats de la commande :

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
ℹ Workspace policy disableunittestcompilation lifted for this invocation (--force).

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (6 projects):
  1. __Unitest__ [STATIC_LIB] → 
  2. NKPlatform [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKContainers_Tests [TEST_SUITE] (depends: NKContainers, __Unitest__, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: __Unitest__                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: TestAssert.cpp
✓   [2/11] Compiled: ConsoleReport.cpp
✓   [3/11] Compiled: TestAggregator.cpp
✓   [4/11] Compiled: TestCase.cpp
✓   [5/11] Compiled: Benchmark.cpp
✓   [6/11] Compiled: Profiler.cpp
✓   [7/11] Compiled: PerformanceReporter.cpp
✓   [8/11] Compiled: TestLauncher.cpp
✓   [9/11] Compiled: Unitest.cpp
✓   [10/11] Compiled: TestReporter.cpp
✓   [11/11] Compiled: TestRunner.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\__Unitest__\Unitest.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 19.18s  │
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
│  ✓ Build Successful                                                             Time: 2.67s  │
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
│  ✓ Build Successful                                                             Time: 1.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
✓   [3/14] Compiled: NkFunction.cpp
✓   [4/14] Compiled: NkGc.cpp
✓   [5/14] Compiled: NkFunctionSIMD.cpp
✓   [6/14] Compiled: NkHash.cpp
✓   [7/14] Compiled: NkMemory.cpp
✓   [8/14] Compiled: NkProfiler.cpp
✓   [9/14] Compiled: NkPoolAllocator.cpp
✓   [10/14] Compiled: NkMultiLevelAllocator.cpp
✓   [11/14] Compiled: NkTracker.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkUtils.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.24s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBinaryTree.cpp
✓   [2/43] Compiled: NkUnorderedMap.cpp
✓   [3/43] Compiled: NkTrie.cpp
✓   [4/43] Compiled: NkFunction.cpp
✓   [5/43] Compiled: NkUnorderedSet.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkContainers.cpp
✓   [8/43] Compiled: NkBind.cpp
✓   [9/43] Compiled: NkPool.cpp
✓   [10/43] Compiled: NkTuple.cpp
✓   [11/43] Compiled: NkVector.cpp
✓   [12/43] Compiled: NkPair.cpp
✓   [13/43] Compiled: NkMap.cpp
✓   [14/43] Compiled: NkFunctional.cpp
✓   [15/43] Compiled: NkHashMap.cpp
✓   [16/43] Compiled: NkArray.cpp
✓   [17/43] Compiled: NkRingBuffer.cpp
✓   [18/43] Compiled: NkInitializerList.cpp
✓   [19/43] Compiled: NkBTree.cpp
✓   [20/43] Compiled: NkIterator.cpp
✓   [21/43] Compiled: NkPriorityQueue.cpp
✓   [22/43] Compiled: NkQuadTree.cpp
✓   [23/43] Compiled: NkDoubleList.cpp
✓   [24/43] Compiled: NkGraph.cpp
✓   [25/43] Compiled: NkDeque.cpp
✓   [26/43] Compiled: NkASCII.cpp
✓   [27/43] Compiled: NkList.cpp
✓   [28/43] Compiled: NkBase64.cpp
✓   [29/43] Compiled: NkUTF16.cpp
✓   [30/43] Compiled: NkEncoding.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkOptional.cpp
✓   [36/43] Compiled: NkStringHash.cpp
✓   [37/43] Compiled: NkString.cpp
✓   [38/43] Compiled: NkResult.cpp
✓   [39/43] Compiled: NkStringBuilder.cpp
✓   [40/43] Compiled: NkStringView.cpp
✓   [41/43] Compiled: NkVariant.cpp
✓   [42/43] Compiled: NkSpan.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.21s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers_Tests                                               Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: Entry.cpp
✓   [2/11] Compiled: test_iterator.cpp
✓   [3/11] Compiled: test_btree.cpp
✓   [4/11] Compiled: test_initializer_list.cpp
✓   [5/11] Compiled: test_map.cpp
✓   [6/11] Compiled: test_graph.cpp
✓   [7/11] Compiled: test_cpp11_gardes.cpp
✓   [8/11] Compiled: test_pair.cpp
✓   [9/11] Compiled: test_span.cpp
✓   [10/11] Compiled: test_priority_queue.cpp
✓   [11/11] Compiled: test_vector.cpp
ℹ Linking...
✓ Built: Build\Tests\Debug-Windows\NKContainers_Tests.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 8.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  6/6
Time:           40.79s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```

* **Temps de compilation: 40.79 secondes**

 * Conclusion:
 ***

A travers ce resultat on peut donc observer que 06 tests on ete effectues et on bien reussit .

