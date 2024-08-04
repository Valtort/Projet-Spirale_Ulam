#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>
/* Ce programme existe en deux versions, une pour windows, et une pour linux.
Celui-ci est pour Windows*/

/*Ce programme sert à afficher la spirale d'Ulam pour une taille souhaitée par
l'utilisateur, les nombres premiers s'afficheront en Jaune dans le terminal*/

//Comme je l'ai dit, il nous faut de quoi faire des couleurs dans le terminal !

//Change la couleur du texte qui s'affichera dans le terminal (Code trouvé sur internet, pour la version Linux, je l'ai fait moi même)
void setColor(int couleurTexte, int couleurTerminal) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (couleurTerminal << 4) | couleurTexte);
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
void genererSpirale(int n, int mat[n][n]){
    int x = n/2; 
    int y = n/2; // On place x et y au centre de la spirale
    int deplace_x = 0; 
    int deplace_y = -1; // Car pour le second "mouvement", on remonte de 1
    for(int i=1; i<=(n*n);i++){
        mat[x][y]=i;
        if((x == y) || ((x<y) && (x+y == (n-1))) || ((x>y) && (x+y == n))){
            // Il s'agit là des trois conditions pour changer de directions, une seule remplie et c'est le changement de direction
            // La première correspond à être sur la diagonale qui part d'en haut à gauche de la matrice.
            // La deuxième et le troisième correspondent à être sur la diagionale qui part d'en bas à gauche.
            // La deuxième est pour quand on est en dessous du 1 (du centre) et la troisième pour quand on est au dessus.
            int sauv = deplace_x;
            deplace_x = -deplace_y;
            deplace_y = sauv;
        }
        x = x + deplace_x;
        y = y + deplace_y;
    }
    
}

//Affiche une matrice de taille n*n (avec des nombres)
void afficher_mat_nb(int n, int mat[n][n]){
    bool premier;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            premier = est_premier(mat[j][i]);
            if(premier){
                setColor(14, 0); 
                printf("[%d] ", mat[j][i]);
                setColor(7, 0);
            }
            else{
                printf("[%d] ", mat[j][i]);
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
                setColor(14, 0); 
                printf("* ");
                setColor(7, 0);
            }
            else{
                printf(". ");
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