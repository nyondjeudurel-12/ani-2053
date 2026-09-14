# DEBUG AND RELEASE 
# EXERCICE 8:

j'utilise le projet NKMath je le construit avec les configurations Debug et Release:

                        RELEASE:
                        
PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> Measure-Command {
>>     py "C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Jenga\Jenga\Jenga.py" build --target NKMath --config Release
>> }
>> 


Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 13
Milliseconds      : 466
Ticks             : 134667238
TotalDays         : 0,000155864858796296
TotalHours        : 0,00374075661111111
TotalMinutes      : 0,224445396666667
TotalSeconds      : 13,4667238
TotalMilliseconds : 13466,7238

PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> Get-ChildItem ".\Build\Lib" -Recurse -File |
>>     ForEach-Object {
>>         "{0} | {1} octets | {2} Mo" -f $.Name, $.Length, [math]::Round($_.Length / 1MB, 3)
>>     }
>> 
NKContainers.lib | 879442 octets | 0,839 Mo
NKCore.lib | 70802 octets | 0,068 Mo
NKMath.lib | 950766 octets | 0,907 Mo
NKMemory.lib | 694710 octets | 0,663 Mo
NKPlatform.lib | 40906 octets | 0,039 Mo
NKContainers.lib | 292472 octets | 0,279 Mo
NKCore.lib | 16516 octets | 0,016 Mo
NKMath.lib | 153822 octets | 0,147 Mo
NKMemory.lib | 219266 octets | 0,209 Mo
NKPlatform.lib | 12488 octets | 0,012 Mo


                      DEBUG:
                      
S C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> Measure-Command {
>>     py "C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Jenga\Jenga\Jenga.py" build --target NKMath --config Debug
>> }
>> 


Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 14
Milliseconds      : 496
Ticks             : 144961340
TotalDays         : 0,000167779328703704
TotalHours        : 0,00402670388888889
TotalMinutes      : 0,241602233333333
TotalSeconds      : 14,496134
TotalMilliseconds : 14496,134

PS C:\Users\cloth\OneDrive\Bureau\Nouveau dossier\Nkentseu> Get-ChildItem ".\Build\Lib" -Recurse -File |
>>     ForEach-Object {
>>         "{0} | {1} octets | {2} Mo" -f $.Name, $.Length, [math]::Round($_.Length / 1MB, 3)
>>     }
>> 
NKContainers.lib | 879442 octets | 0,839 Mo
NKCore.lib | 70802 octets | 0,068 Mo
NKMath.lib | 950766 octets | 0,907 Mo
NKMemory.lib | 694710 octets | 0,663 Mo
NKPlatform.lib | 40906 octets | 0,039 Mo

* **CONCLUSION**:
* **

La configuration Debug a effectue 14,496 s, et a eu 950 766 octets (0,907 Mo) de taille en binaire.

La configuration Release a effectue 13,467 s, et a eu 153 822 octets (0,147 Mo) de taille en binaire.

La configuration Release est donc plus rapide de 1,029 seconde. Elle produit également un binaire beaucoup plus petit : 153 822 octets contre 950 766 octets en Debug.

Les différences sont expliquées dans "Kernel/Foundation/NKMath/NKMath.jenga" par les lignes suivantes :


63:     with filter("config:Debug"):
64:         defines(["_DEBUG", "DEBUG"])
65:         optimize("Off")
66:         symbols(True)
67:     with filter("config:Release"):
68:         defines(["NDEBUG"])
69:         optimize("Speed")
70:         symbols(False)

En Debug, l'optimisation est désactivée avec "optimize("Off")" et les symboles de débogage sont activés avec "symbols(True)".

En Release, le projet est optimisé pour la vitesse avec "optimize("Speed")" et les symboles de débogage sont désactivés avec "symbols(False)".

