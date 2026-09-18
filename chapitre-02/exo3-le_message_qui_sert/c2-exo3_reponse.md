# EXERCICE 3: (Le message qui sert)

* Je commence par prendre 03 commit du moteur Nkensteu .
j'ai choisit les suivants:
```
923ee16e NkPoseDebugDraw : la sphere d equilibre gagne un troisieme etat -- aucun appui n est pas un verdict

84adb070 NkAnimaEditor : le COM (M3.1) s affiche enfin — et il NOMME son propre regime

e783b8ce NKRenderer : 4 messages de journal passaient des marqueurs {0} a la famille printf -- ils sortaient litteralement, argument perdu en silence


```
*  jugeons leurs messages:
```
Concernant le commit de NkPoseDebugDraw son message est assez précis et compréhensible.

Concernant le commit de NkAnimaEditor le message est expressif et explique bien le changement, même s'il est un peu long.

concernant le commit de NKRenderer le message est Très explicite sur le bug et son origine, mais assez long .
```

* Ceux qu'ils font et pourquoi :
Le commit suivant:
```
923ee16e NkPoseDebugDraw : la sphere d equilibre gagne un troisieme etat -- aucun appui n est pas un verdict
```
 ici Le message explique  que la sphère d'équilibre possède désormais un troisième état et précise ce que représente cet état.

 le commit suivant:
 ```
 84adb070 NkAnimaEditor : le COM (M3.1) s affiche enfin — et il NOMME son propre regime
```
ici le message indique que le COM (centre de masse) est maintenant affiché et qu'il indique son propre régime.

le commit suivant:
```
e783b8ce NKRenderer : 4 messages de journal passaient des marqueurs {0} a la famille printf -- ils sortaient litteralement, argument perdu en silence

```
ici le message explique le problème : quatre messages utilisaient des marqueurs {0} avec printf, ce qui faisait apparaître les marqueurs littéralement.

* chacuns de ces commits portent un seul sujet.

* A mon avis ceux lui qui parait le plus faible des 03 est 
```
84adb070 NkAnimaEditor : le COM (M3.1) s affiche enfin — et il NOMME son propre regime

```
parce que son message est moins direct. Le passage « s'affiche enfin — et il NOMME son propre régime » n'est pas assez expressif .

moi je le reecriverais comme ceux ci:  
```
NkAnimaEditor : affiche le COM (M3.1) et son régime

```
Ce nouveau message est plus court, plus direct et reste precis.

* Conclusion
***
Les trois commits ont des messages informatifs : ils expliquent bien le contenu concerné et décrivent la modification. Le premier et le troisième expliquent particulièrement bien le problème ou le changement effectué. Le deuxième est compréhensible, mais son style differe legerement des autres.