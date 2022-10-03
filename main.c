//=======================================================================================================//
// Projet : Jeu de Nim                                                                                   //
// Version : 0.1                                                                                         //
// Fichier : main.c                                                                                      //
// Auteurs : Rémy (CAROTORO) & Tiziano (Tizaming)                                                        //
// Date de création : 16/09/2022                                                                         //
// Date de la dernière modification : 30/09/2022                                                         //
//=======================================================================================================//

#include <stdio.h>
#include <stdlib.h>  

int matches = 12; // Nombre d'allumettes
int nb_matches_out_player = 0, nb_matches_out_AI = 0, nb_matches_out_playertwo = 0;
int aws = 0; // Si la réponse est bonne aws = 1 autrement aws = 0
int gamemode;

int basicIA(){
    printf("Tu as choisi le mode simple !");
    while (matches > 0) // Tant que le nombre d'allumette est superieur à 0
    {
        while (!aws) // Tant que aws est différent de 0 
        {
            printf("Joueur\n");
            printf("Combien d'allumettes voulez-vous enlever ?\n->");
            scanf("%d", &nb_matches_out_player); // Demande le nombre d'allumette que l'on veut retirer
            if(nb_matches_out_player==1 || nb_matches_out_player==2 || nb_matches_out_player==3){ // Si le nombre d'allumette vaut 1, 2 ou 3 alors 
                matches -= nb_matches_out_player;                                                 // enlever le nombre d'allumette qu'on a voulu retirer au nombre d'allumette "total" (valeur par défaut = 12)
                aws = 1;                                                                          // mettre aws à 1 ce qui nous permet de sortir de la boucle
            }else{
                printf("Entrez une valeur comprise entre 1 et 3\n"); // Message d'erreur
            }
        }
        aws=0; // On remet aws à 0 pour afin de répeter ce qui précède 
        printf("Il reste maintenant %d allumettes\n", matches); 
        
        if(matches == 0){ // Si le nombre d'allumette est de 0 alors on a perdu et on met le nombre d'allumette à 0 pour sortir de la boucle
            printf("Vous avez perdu :(\n");
            matches=0;
        }else{
            if (matches == 1){ // Si le nombre d'allumette est de 1 alors on a gagné et on met le nombre d'allumette à 0 pour sortir de la boucle
                printf("Vous avez gagné !");
                matches=0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
            }else{ 
                printf("IA\n");
                nb_matches_out_AI = rand() % 4; // "L'IA" tire aléatoirement un nombre d'allumette compris entre 0 et 4 (1, 2 ou 3) 
                matches -= nb_matches_out_AI; // On soustrait au nombre d'allumette le nombre d'allumette tiré aléatoirement par "l'IA"
                printf("Il reste maintenant %d allumettes\n", matches); 
                if(matches == 0  || matches < 0){ // Si le nombre d'allumette vaut 0 ou est inférieur à 0 alors "l'IA" a perdu
                    printf("L'ordi a perdu ! [:)]\n");
                } else {
                    if(matches == 1  || matches < 1){ // Si le nombre d'allumette vaut 1 ou est inférieur à 1 alors le joueur (nous) a perdu
                        printf("Vous avez perdu :(((((\n");
                        matches=0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
                    }
                }
            }
        }
    }
}

int hardIA(){
    printf("Tu as choisi le mode difficile !\n");
    while (matches > 0) // Tant que le nombre d'allumette est superieur à 0
    {
        while (!aws) // Tant que aws est différent de 0 
        {
            printf("Joueur\n");
            printf("Combien d'allumettes voulez-vous enlever ?\n->");
            scanf("%d", &nb_matches_out_player); // Demande le nombre d'allumette que l'on veut retirer
            if(nb_matches_out_player==1 || nb_matches_out_player==2 || nb_matches_out_player==3){ // Si le nombre d'allumette vaut 1, 2 ou 3 alors 
                matches -= nb_matches_out_player;                                                 // enlever le nombre d'allumette qu'on a voulu retirer au nombre d'allumette "total" (valeur par défaut = 12)
                aws = 1;                                                                          // mettre aws à 1 ce qui nous permet de sortir de la boucle
            }else{
                printf("Entrez une valeur comprise entre 1 et 3\n"); // Message d'erreur
            }
        }
        aws=0; // On remet aws à 0 pour afin de répeter ce qui précède 
        printf("Il reste maintenant %d allumettes\n", matches); 
        if(matches == 0){ // Si le nombre d'allumette est de 0 alors on a perdu et on met le nombre d'allumette à 0 pour sortir de la boucle
            printf("Vous avez perdu :(\n");
            matches=0;
        }else{
            if (matches == 1){ // Si le nombre d'allumette est de 1 alors on a gagné et on met le nombre d'allumette à 0 pour sortir de la boucle
                printf("Vous avez gagné !");
                matches=0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
            }else{ 
                if(nb_matches_out_player == 1){
                    nb_matches_out_AI = 3;
                }else if(nb_matches_out_player == 2){
                    nb_matches_out_AI = 2;
                }else if(nb_matches_out_player == 3){
                    nb_matches_out_AI = 1;
                }
                matches -= nb_matches_out_AI;
                printf("Il reste maintenant %d allumettes\n", matches); 
                if(matches == 0  || matches < 0){ // Si le nombre d'allumette vaut 0 ou est inférieur à 0 alors "l'IA" a perdu
                    printf("L'ordi a perdu ! [:)]\n");
                } else {
                    if(matches == 1  || matches < 1){ // Si le nombre d'allumette vaut 1 ou est inférieur à 1 alors le joueur (nous) a perdu
                        printf("Vous avez perdu :(((((\n");
                        matches=0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
                    }
                }
            }  
        }                                                       
    }
}

int onevsone(){
    printf("Tu as choisi le mode un contre un !\n");
    while(matches>0){
        while(!aws){
            printf("Joueur 1\n");
            printf("Combien d'allumettes voulez-vous enlever ?\n->");
            scanf("%d", &nb_matches_out_player); // Demande le nombre d'allumette que l'on veut retirer
            if(nb_matches_out_player==1 || nb_matches_out_player==2 || nb_matches_out_player==3){ // Si le nombre d'allumette vaut 1, 2 ou 3 alors 
                matches -= nb_matches_out_player;                                                 // enlever le nombre d'allumette qu'on a voulu retirer au nombre d'allumette "total" (valeur par défaut = 12)
                aws = 1;                                                                          // mettre aws à 1 ce qui nous permet de sortir de la boucle
            }else{
                printf("Entrez une valeur comprise entre 1 et 3\n"); // Message d'erreur
            }
        }
        aws = 0;
        printf("Il reste maintenant %d allumettes\n", matches);
        if(matches == 0){ // Si le nombre d'allumette est de 0 alors on a perdu et on met le nombre d'allumette à 0 pour sortir de la boucle
            printf("Le joueur 2 a gagné !\n");
            matches=0;
        }else{
            if (matches == 1){ // Si le nombre d'allumette est de 1 alors on a gagné et on met le nombre d'allumette à 0 pour sortir de la boucle
                printf("Le joueur 1 a gagné !");
                matches=0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
            }else{ 
                printf("Joueur 2\n");
                printf("Combien d'allumettes voulez-vous enlever ?\n->");
                scanf("%d", &nb_matches_out_playertwo); // Demande le nombre d'allumette que l'on veut retirer
                if(nb_matches_out_playertwo==1 || nb_matches_out_playertwo==2 || nb_matches_out_playertwo==3){ // Si le nombre d'allumette vaut 1, 2 ou 3 alors 
                matches -= nb_matches_out_playertwo;                                                 // enlever le nombre d'allumette qu'on a voulu retirer au nombre d'allumette "total" (valeur par défaut = 12)
                printf("Il reste maintenant %d allumettes\n", matches);
            }else{
                printf("Entrez une valeur comprise entre 1 et 3\n"); // Message d'erreur
            } 
                if(matches == 0  || matches < 0){ // Si le nombre d'allumette vaut 0 ou est inférieur à 0 alors "l'IA" a perdu
                    printf("Le joueur 1 a gagné !\n");
                } else {
                    if(matches == 1  || matches < 1){ // Si le nombre d'allumette vaut 1 ou est inférieur à 1 alors le joueur (nous) a perdu
                        printf("Le joueur 2 a gagné !\n");
                        matches=0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
                    }
                }
            }
        }
    }   
}

int main(int argc, char *argv[])
{
    printf("Choisissez un mode de jeu :\n");
    printf("[1] Basic IA\n");
    printf("[2] Hard IA\n");
    printf("[3] 1 vs 1\n\n");
    scanf("%d", &gamemode);

    switch(gamemode){
        case 1 :
            basicIA();
            break;
        case 2 :
            hardIA();
            break;
        case 3 :
            onevsone();
            break;
    }
}
