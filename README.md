-Les codes de la partie opértive se trouvent dans le dossier "PO"
-Les codes de la partie de la simulation se trouvent dans le dossier "Simulation"
-Les codes de la partie contrôle se trouvent dans le dossier "PC"

###Lancement de la simulation
1. se mettre dans le dossier "Simulation"
2. lancer la commande suivante:
```bash
 lv6 -ec -node top16 -o top.ec top.lus
 luciole -comp top.ec
```