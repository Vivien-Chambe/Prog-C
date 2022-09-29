## DESCRIPTION:



## COMPILATION:

Pour lancer le jeu sans aucune option : `make run`

 ## OPTIONS: à bien rajouter sans espaces

Il est possible d'ajouter les options suivantes a la suite de make run:

- `debug=1`   | Permets d'obtenir des informations sur le jeu non utiles au joueur
- `rainbow=1` | Mets un peu de couleur au canyon
- `ap=1`      | Active l'autopilote
- `boss=1`    | Mode qui désactive les précédentes si activées et lance un mode "Histoire"

## VARIABLES:

Il est également possible de modifier certaines variables de départ du jeu:

- `cn=int`    | Modifie la taille initiale du canyon (doit être supérieur ou égal à 3),                   par défaut cn=20
- `hz=int`    | Permets de modifier le taux de rafraichissement (doit être supérieur ou égal à 3),        par défaut sinon hz=50
- `border=c`  | Permets de modifier le caractère utilisé pour les murs du canyon (à mettre sans "" ni '') par défaut border=*
- `skin=c`    | De même pour changer le caractère du personnage                                           par défaut skin=T


Auteurs : Chambe Vivien et Adjamé Rozen

