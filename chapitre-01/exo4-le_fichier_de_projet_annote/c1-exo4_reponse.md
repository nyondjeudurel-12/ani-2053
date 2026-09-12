# REPERTORIER LES INCOMPREHENSIONS:
# EXERCICE 4:


 
```

from Jenga import *
from jengaconfig import *

with project("NKMemory"):
    language("C++")
    cppdialect("C++17")
    location(".")

    nkentseudependson(
        ["NKCore", "NKPlatform"],
        selfexport="NKMemory",
        extra_includes=["src", "pch"],
    )

    pchheader("pch/pch.h")
    pchsource("pch/pch.cpp")

    files([
        "src/NKMemory/**.cpp",
        "src/NKMemory/**.h",
    ])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")???????????
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")

    with filter("system:Windows && options:windows-runtime=uwp"):
        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")??????
        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp") ????????

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        usetoolchain(TC_WINDOWS)
    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
        usetoolchain("xbox-clang")
    with filter("system:Linux"):
        links(["pthread"])
    with filter("system:macOS"):
        usetoolchain("clang-native")
    with filter("system:Android"):
        # Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
        pchheader("")
        pchsource("")
        usetoolchain("android-ndk")
        links(["log"])
    with filter("system:HarmonyOS"):
        # PCH desactive (NDK OHOS clang, meme contrainte qu'Android)
        pchheader("")
        pchsource("")
        usetoolchain("ohos-ndk")
        links(["hilog_ndk.z"])
    with filter("system:Web"):
        usetoolchain("emscripten")
    with filter("system:XboxSeries || system:XboxOne"):
        usetoolchain("xbox-clang")

    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG", "NKENTSEU_DEBUG"])
        optimize("Off")
        symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)

    # Tests unitaires/stress (desktop uniquement)
    with filter("(system:Linux || system:macOS || (system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS || system:Web"):
        with test():
            testfiles(["tests/**.cpp"])
```

## INFORMATIONS DEMANDES 
### type
Type de NKMemory: "StaticLib"

#### sources
```


NkAllocator.cpp                  
NkAllocator.h                    
NkContainerAllocator.cpp         
NkContainerAllocator.h           
NkFunction.cpp                   
NkFunction.h                     
NkFunctionSIMD.cpp               
NkFunctionSIMD.h                 
NkGc.cpp                         
NkGc.h                           
NkGlobalOperators.cpp            
NkHash.cpp                       
NkHash.h                         
NkIntrusivePtr.h                 
NkMemory.cpp                     
NKMemory.h                       
NkMemoryApi.h                    
NkMultiLevelAllocator.cpp        
NkMultiLevelAllocator.h          
NkPoolAllocator.cpp              
NkPoolAllocator.h                
NkPoolAllocatorTyped.h           
NkProfiler.cpp                   
NkProfiler.h                     
NkSharedPtr.h                    
NkStlAdapter.h                   
NkTag.cpp                        
NkTag.h                          
NkTracker.cpp                    
NkTracker.h                      
NkUniquePtr.h                    
NkUtils.cpp                      
NkUtils.h 


```
je l'est obtenus apres avoir taper la commande :                                                           
 Get-ChildItem .\Kernel\Foundation\NKPlatform -Recurse -Include *.cpp,*.h -File | Select-Object Name
qui sont des noms obtenus apres avoir taper la commande:

Get-ChildItem .\Kernel\Foundation\NKPlatform -Recurse -Include *.cpp,*.h -File | Select-Object Name

Cependant je n'ai tenu compte que de ceux qui etaient dans le dossier src.

#### dependances
Des analyses NKMemory  depend de NKCore et NKPlateform .
#### filtres

On observe tous les filters de NKMemory.jenga, et  on remarque que les differents filtres sont:

Windows
UWP
macOS
Android
HarmonyOS
Web
XboxSeries
XboxOne
Debug
Release


#### Tests

benchmark_allocators.cpp         
benchmark_allocator_vs_stl.cpp   
benchmark_container_allocator.cpp
test_allocator_arena.cpp         
test_allocator_buddy.cpp         
test_allocator_container.cpp     
test_allocator_freelist.cpp      
test_allocator_linear.cpp        
test_allocator_malloc.cpp        
test_allocator_pool.cpp          
test_allocator_stack.cpp         
test_allocator_virtual.cpp       
test_core_utility_smoke.cpp      
test_gc.cpp                      
test_hash_memory.cpp             
test_memory_fn.cpp               
test_memory_stress.cpp           
test_memory_system.cpp           
test_memory_utils.cpp            


