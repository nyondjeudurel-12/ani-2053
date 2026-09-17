# EXERCICE 12:
# Ce qui sera verifier..

* La ligne qui desactive la compilation de test dans Le workspace est
``` 
dutc(enable=True)  
dutc(enable=True)
```
   elle sert à activer la compilation des tests unitaires dans la configuration du workspace. DUTC signifie quelque chose comme Disable/Enable Unit Test Compilation.

* L'exécution est  désactivée avec
``` 
dute(enable=True) .
```
* Pour savoir quelle tests pouvais build j'ai utiliser cette commande :
```
Get-ChildItem -Recurse -Directory | Where-Object { $_.Name -eq "tests" }
```
* Pour lancer quand meme le test de NKMemory, j'ai utilisé: 

```
jenga test --project NKMemory_Tests --force-test
```
* RESULTAT:
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

[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
Building NKMemory_Tests...
Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
ℹ Workspace policy disableunittestcompilation lifted for this invocation (--force).

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (5 projects):
  1. __Unitest__ [STATIC_LIB] → 
  2. NKPlatform [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKMemory_Tests [TEST_SUITE] (depends: NKMemory, __Unitest__, NKCore, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: __Unitest__                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: TestAssert.cpp
✓   [2/11] Compiled: TestAggregator.cpp
✓   [3/11] Compiled: ConsoleReport.cpp
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
│  ✓ Build Successful                                                            Time: 11.72s  │
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
│  ✓ Build Successful                                                             Time: 2.18s  │
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
│  ✓ Build Successful                                                             Time: 1.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkContainerAllocator.cpp
✓   [4/14] Compiled: NkHash.cpp
✓   [5/14] Compiled: NkGc.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkMemory.cpp
✓   [8/14] Compiled: NkProfiler.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkTracker.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkUtils.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory_Tests                                                   Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 20 source file(s)
✓   [1/20] Compiled: Entry.cpp
✓   [2/20] Compiled: benchmark_allocators.cpp
✓   [3/20] Compiled: test_allocator_buddy.cpp
✓   [4/20] Compiled: benchmark_allocator_vs_stl.cpp
✓   [5/20] Compiled: test_allocator_container.cpp
✓   [6/20] Compiled: test_allocator_arena.cpp
✓   [7/20] Compiled: benchmark_container_allocator.cpp
✓   [8/20] Compiled: test_allocator_freelist.cpp
✓   [9/20] Compiled: test_allocator_malloc.cpp
✓   [10/20] Compiled: test_allocator_stack.cpp
✓   [11/20] Compiled: test_allocator_pool.cpp
✓   [12/20] Compiled: test_allocator_linear.cpp
✓   [13/20] Compiled: test_allocator_virtual.cpp
✓   [14/20] Compiled: test_core_utility_smoke.cpp
✓   [15/20] Compiled: test_gc.cpp
✓   [16/20] Compiled: test_memory_fn.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: test_memory_utils.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\tests\test_m ║
║ emory_utils.cpp:10:36: error: use of undeclared identifier 'NkAlignUp'                       ║
║    10 |         ASSERT_EQUAL(16, static_cast<int>(NkAlignUp(13u, 8u)));                      ║
║       |                                           ^~~~~~~~~                                  ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\tests\test_m ║
║ emory_utils.cpp:11:35: error: use of undeclared identifier 'NkAlignDown'                     ║
║    11 |         ASSERT_EQUAL(8, static_cast<int>(NkAlignDown(13u, 8u)));                     ║
║       |                                          ^~~~~~~~~~~                                 ║
║ 2 errors generated.                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\tests\test_memory_utils.cpp
✓   [18/20] Compiled: test_hash_memory.cpp
✓   [19/20] Compiled: test_memory_stress.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                          Compilation Error: test_memory_system.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\tests\test_m ║
║ emory_system.cpp:4:10: warning: non-portable path to file '"NKMemory/NKMemory.h"'; specified ║
║ path differs in case from file name on disk [-Wnonportable-include-path]                     ║
║     4 | #include "NKMemory/NkMemory.h"                                                       ║
║       |          ^~~~~~~~~~~~~~~~~~~~~                                                       ║
║       |          "NKMemory/NKMemory.h"                                                       ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\tests\test_m ║
║ emory_system.cpp:84:18: error: use of undeclared identifier 'NkCompare'; did you mean        ║
║ 'NkMemCompare'?                                                                              ║
║    84 |         ASSERT_EQUAL(0, NkCompare(named.Name, "Gameplay", 8u));                      ║
║       |                         ^~~~~~~~~                                                    ║
║       |                         NkMemCompare                                                 ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Jenga\Jenga\Unitest\src/Unitest/TestMacro.h:33:5 ║
║ 2: note: expanded from macro 'ASSERT_EQUAL'                                                  ║
║ 33 |     nkentseu::test::TestAssert::Equal((expected), (actual), "", __FILE__, __LINE__,     ║
║ #expected " == " #actual)                                                                    ║
║       |                                                    ^~~~~~                            ║
║ C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\src/NKMemory ║
║ /NkUtils.h:65:12: note: 'NkMemCompare' declared here                                         ║
║ 65 |                 nk_int32 NkMemCompare(const void *a, const void *b, nk_size size)       ║
║ noexcept;                                                                                    ║
║       |                          ^                                                           ║
║ 1 warning and 1 error generated.                                                             ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Kernel\Foundation\NKMemory\tests\test_memory_system.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                Time: 10.53s  │
│ Errors: 4  | Failed files: 2                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/5
Failed:         1
Errors:         4
Time:           28.42s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMemory_Tests
```

* CONCLUSION:
***
   L'erreur vient de test_smoke.cpp, parceque NkRect est introuvable.
