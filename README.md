# Projet: Spirale d'Ulam
Ce petit projet affiche la spirale d’Ulam d'une taille souhaitée par l'utilisateur. Il s'agit d'un projet codé entièrement en C. 

## Compilation
> [!IMPORTANT]
>Lorsque vous compilez avec gcc, attention ! On #include <math.h>, il faut donc compiler avec -lm.

## Informations générales

Notre spirale tournera dans le sens anti-horaire.

![image](https://github.com/user-attachments/assets/8469d79d-4407-4bf3-a987-7403b20f4f78)

*Source : https://fr.wikipedia.org/wiki/Spirale_d%27Ulam*

## Particularité

Ce programme est disponible en deux versions, une pour Windows et une pour Linux.

Quand on éxecute le programme on a le choix de la taille de la spirale ainsi que deux options:

- Écrire les nombres et colorier en jaune les nombres premiers (peu pratique pour de grandes tailles de spirale).
- Mettre des astérisque colorié en jaune pour les nombres premiers et des points pour les non premiers (très jolies).

> [!NOTE]
> Le 1 sera toujours colorié en rouge, bien que 1 n'est pas premier.

# Exemples
![image](https://github.com/user-attachments/assets/fd60dc7e-4138-4af2-9949-ea542883e201)

*Spirale d'Ulam de taille 2x2 avec chiffres*

![image](https://github.com/user-attachments/assets/02172b5b-7edf-417a-aa11-4aaaedab2949)

*Spirale d'Ulam de taille 3x3 avec chiffres*

![image](https://github.com/user-attachments/assets/7c6175c8-2a86-4eee-b551-7a4d99031813)

*Spirale d'Ulam de taille 100x100 avec astérisque*

## Ce que ce projet m'a apporté

Grâce à ce projet j'ai appris à colorié du texte dans le terminal pour un utilisateur Linux et pour un utilisateur Windows.
J'ai également appris à afficher des spirales de nombres en partant du centre.

## Difficultés rencontrées

La première difficulté que j’ai rencontrée était de devoir distinguer le cas d’une taille paire et d’une taille impaire. En effet, le “centre” de la spirale se décale en fonction de la parité de la taille. Une simple disjonction de cas ainsi que des tests faits sur papier ont permis de vaincre cette difficulté.

La seconde difficulté était de devoir tracer la spirale en partant du centre et en tournant dans le sens anti-horaire. Pour venir à bout de celle-ci, j’ai remarqué qu’on faisait des mouvements du type : 1 droite, 1 haut, 2 gauche, 2 bas, 3 droite, 3 haut, etc.

J’ai donc créé un compteur, compteur_boucle, celui-ci est remis à zéro à chaque fois que l’on passe 1 fois dans la boucle qui crée la spirale, puis à chaque fois que l’on passe 1 fois, puis à chaque fois que l’on passe 2 fois, etc.

Cela permet donc d’avoir un compteur_boucle qui nous indique le nombre de fois où l’on doit aller dans la même direction.

De plus, à chaque fois que ce compteur est remis à zéro, on incrémente compteur_sens de 1. Celui-ci dicte le sens dans lequel on doit aller et il est remis à zéro à chaque fois que compteur_sens atteint 4. (Pour compteur_sens : 0 correspond à droite, 1 à haut, 2 à gauche, 3 à bas)

