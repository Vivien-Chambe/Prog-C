## DESCRIPTION:

Le but de ce programme et de tester et comparer des implémentations d'algorithmes de tri
par base (Radix Sort) et de tri rapide (Quick Sort)

## COMPILATION:

Le programme est prévu pour lancer les différents tests demandés.

Pour ce faire il suffit d'écrire `make run test=nb` avec `nb` pouvant valoir:

`1` : Pour tester si qsort tri bien les éléments 
`2` : Pour tester la vitesse de tri de Qsortu avec un pivot à la fin sur des tableaux décroissants
`3` : Pour vérifier que qsortu avec un pivot aleatoire fonctionne correctement
`4` : Comparatif de qsortu avec un pivot aléatoire et pivot à la fin sur des tableaux décroissants
`5` : Pour vérifier que qsortg fonctionne correctement
`6` : Pour avoir le comparatif de vitesse de tri entre qsort standard, qsortg et qsortu
`7` : Pour le test de radix_sort mais on a une erreur de segmentation

 ## OPTIONS: à bien rajouter sans espaces
17
Il est conseillé de lancer la compilation avec une option à la fois pour commencer avant de les ajouter.
18
Il est possible d'ajouter les options suivantes a la suite de make run:
19
​
20
- `debug=1`   | Permets d'obtenir des informations sur le jeu non utiles au joueur
21
- `rainbow=1` | Mets un peu de couleur au canyon
22
- `ap=1`      | Active l'autopilote
23
- `boss=1`    | Mode qui désactive les précédentes si activées et lance un mode "Histoire"
24
​
25
## VARIABLES:
26
​
27
Il est également possible de modifier certaines variables de départ du jeu:
28
​
29
- `cn=int`    | Modifie la taille initiale du canyon (doit être supérieur ou égal à 3),                   par défaut cn=20
30
- `hz=int`    | Permets de modifier le taux de rafraichissement (doit être supérieur ou égal à 3),        par défaut sinon hz=50
31
- `border=c`  | Permets de modifier le caractère utilisé pour les murs du canyon (à mettre sans "" ni '') par défaut border=*
32
- `skin=c`    | De même pour changer le caractère du personnage                                           par défaut skin=T
33
​


Auteurs : Chambe Vivien et Adjamé Rozen


 