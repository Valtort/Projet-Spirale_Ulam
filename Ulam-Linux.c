#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
/* Ce programme existe en deux versions, une pour windows, et une pour linux.
Celui-ci est pour Linux*/

/*Ce programme sert à afficher la spirale d'Ulam pour une taille souhaitée par
l'utilisateur, les nombres premiers s'afficheront en Jaune dans le terminal*/

//Comme je l'ai dit, il nous faut de quoi faire des couleurs dans le terminal !

//Change la couleur du texte qui s'affichera dans le terminal
void printColor(int n){
    printf("\033[1;33m"); // On peut changer la couleur en changeant 33 par d'autres nombres !
    // Ici 33 correspond, au jaune
    printf("[%d] ", n);
    printf("\033[0m"); // réinitialise la couleur
}

/*Vérifie si un nombre n est premier en testant sa divisibilité par tous les
nombres inférieurs à la valeur entière de sa racine carrée. 
Renvoie true si le nombre est premier, faux sinon*/
bool est_premier(int n){
    if(n==1){
        return false;
    }
    int racine = sqrt(n);
    for(int i=2; i<=racine; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

//Remplit une matrice de taille : n*n de manière a avoir une spirale de nombres
void genererSpirale(int n, int matrice[n][n]) {
    int x = n / 2;
    int y = n / 2;
    //Pour éviter les segmentation fault lorsque l'on entre des nombres pairs
    if(n%2==0){
        x--;
    }
    int dx; // Deplacement de x
    int dy; // Deplacement de y
    int compteur_sens=-1; // compteur qui indique le prochain sens
    // 0 : droite, 1 : haut, 2: gauche, 3: bas
    int compteur_boucle=0; // Compte le nombre de passage dans la boucle MAIS se remet à 0 parfois
    int j=0;
    for (int i = 1; i <= n*n; i++) { 
        dx=0;
        dy=0;
        // sert à pouvoir faire 1 fois vers la droite, 1 fois vers le haut puis 2 fois vers la gauche, 2 fois vers le bas, 3 droite, 3 haut etc...
        if(compteur_boucle==(j+1)/2){ 
            j++;
            compteur_boucle=0;
            compteur_sens++;
        }
        
        matrice[x][y] = i;
        if(compteur_sens==0){ // Va vers la droite
            dx = 1;
        }
        if(compteur_sens==1){ // Va vers le haut
            dy = -1;
        }
        if(compteur_sens==2){ // Va vers la gauche
            dx = -1;
        }
        if(compteur_sens==3){ // Va vers le bas
            dy = 1;
        }
        if(compteur_sens==4){
            dx = 1;
            compteur_sens=0;
        }
        compteur_boucle++;
        x+=dx;
        y+=dy;
    }
}

//Affiche une matrice de taille n*n (avec des nombres)
void afficher_mat_nb(int n, int mat[n][n]){
    bool premier;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            premier = est_premier(mat[j][i]);
            
            if(premier){
                printColor(mat[j][i]);
            }
            else{
                
                if(mat[j][i]==1){
                    printf("\033[1;31m"); //1 n'est pas premier mais sera représenté par un nombre rouge pour le démarquer
                    printf("[%d] ", mat[j][i]);
                    printf("\033[0m");
                }
                else{
                    printf("[%d] ", mat[j][i]);
                }
            }
        }
        printf("\n");
    }
}

//Affiche une matrice de taille n*n (avec des astérix)
void afficher_mat_ast(int n, int mat[n][n]){
    bool premier;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            premier = est_premier(mat[j][i]);
            
            if(premier){
                printf("\033[1;33m"); 
                printf("* ");
                printf("\033[0m");
            }
            else{
                if(mat[j][i]==1){
                    printf("\033[1;31m"); //1 n'est pas premier mais sera représenté par une étoile rouge pour le démarquer
                    printf("* ");
                    printf("\033[0m");
                }   
                else{
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

int main(){
    int taille;
    int choix;
    printf("Quelle taille de spirale voulez vous : ");
    scanf("%d", &taille);
    printf("Quelle affichage voulez vous ?\n");
    printf("1. Avec des nombres (Il y a un décalage qui fait que pour les grands nombres, c'est illisible).\n");
    printf("2. Avec des astérix et des points.\n");
    printf("Ecrivez n'importe quoi d'autre pour partir\n");
    scanf("%d", &choix);
    int matrice[taille][taille];
    genererSpirale(taille, matrice);
    if(choix ==1){
        afficher_mat_nb(taille,matrice);
    }
    else{
        if(choix ==2){
            afficher_mat_ast(taille, matrice);
        }
        else{
            printf("Au revoir !\n");
        }
    }
    return 0;
}