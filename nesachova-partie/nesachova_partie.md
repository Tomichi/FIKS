## Nešachová Partie
Jendá se o problem šachovnice o velikosti n * n, na které se nachází na každém políčku body a naším úkolem je umísti 2 střelce bílého a černého tak aby aby součet bodů v diagonálách byl co největší. S podmínou že se diagonály nesmí křížit.

### Let is thinking
Mým prvotním zvykem z progtestu (na FITu) je si vzít čtverečkovaný papír (má hodně výhod oproti čistému) a důkladně si několikrát přečíst zadání a zjístit co opravdu se po mě chce. Po tom se podíván na vstupy začnu si kreslit ukázkový vstup a přemýšlet o hlupém řešení, které mě napadne jako první a snažit se ho zpochybnit, že určitě existuje lepší.

Následně nejsem tlačen časem tak si úlohu nechávám na odpolední dýchánky ve vlaku kde trávím poměrně hodně času. Prvotní námět byl uložit si pole bodů do pole a pak ho procházet a pro každý bod spočítat diagonály.  Což po chvíli přemýšlení mi dojde, že tohle asi není úplně nejlepší nápad a že některé body se opakují a zjístím že vlastně pole potřebuji jen na spočítání a na nic víc. Tudíž pole si nakonec vytvoříme ale bude obsahovat součet bodu na diagonálách v daném směru a výpočet maximalních bodů máme hotový. Zde je jedninou záludností napsat fci která proleze diagonály, jak v kladném, tak i záporném směru. Pro mně efektivním způsobem je vynulovat si pole a přičítat vždy načtený bod diagonálám na kterých leží. Tohle načítání počítání má složisto O(n^2) neboť ukážem si že pro každé políčko musíme projít maximálně f(n) = n * n/2 což o(f(n)) = n^2 

viz ukázka co se stane po přičitávání čísel po diagonálách

input.txt

```
4
1 1 1 1
2 1 1 0
1 1 1 0
1 0 0 1
```

output.txt

```
4 4 3 4
4 6 5 2
3 6 4 2
4 2 3 4
```

A můžeme si všimnout, že se nám vytvořili 2 extremy o ohodnocení 6 pokud. Teď se náš problém už ubirá jen k vyřešení nalezení maxima v poli. Můžeme využít vestavěný quick short algoritmus v knihovnách. A po té vyvstává poslední problem, jak zaručit že střelci neohrožují jedno tlačítko dvakrát. Tento problem není úplně zřejmý, ale máme náš známý čtverečkovaný papír. Pokud si vybarvíme šachovnici dle standartního rozvržení, uvidíme, že pokud by stal střelec na stejné barvě musel by jednou překřížit šachovnici => druhý střelec musí být na druhé barvě. Řešení je už triviální, označit první největší prvek maximem a hledat opačnou barvu na šachnovnici viz kód.
