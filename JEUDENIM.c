#include <stdio.h>
#include <stdlib.h>

int matches = 12; // Nombre d'allumettes
int nb_matches_out_AIH = 0, nb_matches_out_AIB = 0;
int aws = 0; // Si la réponse est bonne aws = 1 autrement aws = 0
int choice; 

int basicIAStart() { //fonction qui fait commencer l'IA "nulle" en première
  while (matches > 0) { // Tant que le nombre d'allumette est superieur à 0
    printf("\nl'ordinateur nul joue :\n\n");
    nb_matches_out_AIB = rand() % 4; // "L'IA" tire aléatoirement un nombre d'allumette compris entre 0 et 4 (1, 2 ou 3)
    matches -= nb_matches_out_AIB; // On soustrait au nombre d'allumette le nombre d'allumette tiré aléatoirement par "l'IA nulle"
    printf("Il reste maintenant %d allumettes\n", matches);
    if (matches == 0) { // Si le nombre d'allumette est de 0 alors "l'IA nulle" a gagnée 
      printf("\nIA nulle a gagnée\n\n");
      matches = 0; // On met le nombre d'allumette à 0 afin de sortir de la boucle, ce qui arretera le jeu

    } else { // autrement :
      if (matches == 1) { // Si le nombre d'allumette est de 1 alors "l'IA forte" a gagnée
        printf("\nIA forte a gagnée\n\n");
        matches = 0;
      } else {  // autrement :
        printf("\nl'ordinateur fort joue: \n\n");
        if (nb_matches_out_AIB == 1) {  //Si le nombre d'allumettes choisi par "l'IA nulle" est de 1 alors "l'IA forte" choisie de retirer 3 allumettes
          nb_matches_out_AIH = 3;
        } else if (nb_matches_out_AIB == 2) { //Si le nombre d'allumettes choisi par "l'IA nulle" est de 2 alors "l'IA forte" choisie de retirer 2 allumettes
          nb_matches_out_AIH = 2;
        } else if (nb_matches_out_AIB == 3) { //Si le nombre d'allumettes choisi par "l'IA nulle" est de 3 alors "l'IA forte" choisie de retirer 1 allumettes
          nb_matches_out_AIH = 1;
        }
        matches -= nb_matches_out_AIH; //Soustraire au nombre d'allumettes restantes le nombre d'allumettes choisi par "l'IA forte"
        printf("Il reste maintenant %d allumettes\n", matches);
        if(matches == 0  || matches < 0){ // Si le nombre d'allumette est de 0 ou est inférieur à 0 alors "l'IA forte" a gagnée
                    printf("\nIA forte a gagnée\n\n");
                } else { // autrement :
                    if(matches == 1){ // Si le nombre d'allumette est de 1 alors "l'IA nulle" a gagnée 
                        printf("\nIA nulle a gagnée\n\n");
                        matches=0; 
                    }
                }
            }
        }
    }
}

int hardIAStart() { //fonction qui fait commencer l'IA "forte" en première
  while (matches > 0) { // Tant que le nombre d'allumette est superieur à 0
    printf("\nl'ordinateur fort joue: \n\n");
    if (nb_matches_out_AIB == 1) { //Si le nombre d'allumettes choisi par "l'IA nulle" est de 1 alors "l'IA forte" choisie de retirer 3 allumettes
      nb_matches_out_AIH = 3;
    } else if (nb_matches_out_AIB == 2) { //Si le nombre d'allumettes choisi par "l'IA nulle" est de 2 alors "l'IA forte" choisie de retirer 2 allumettes
      nb_matches_out_AIH = 2;
    } else if (nb_matches_out_AIB == 3) { //Si le nombre d'allumettes choisi par "l'IA nulle" est de 3 alors "l'IA forte" choisie de retirer 1 allumettes
      nb_matches_out_AIH = 1;
    } else {  // autrement le nombre d'allumettes retiré par "l'IA forte" est de 3
      nb_matches_out_AIH = 3;
    }
    matches -= nb_matches_out_AIH; //Soustraire au nombre d'allumettes restantes le nombre d'allumettes choisi par "l'IA forte"
    printf("Il reste maintenant %d allumettes\n", matches);

    if (matches == 0) { // Si le nombre d'allumette est de 0 alors "l'IA nulle" a gagnée 
      printf("\nIA nulle a gagnée\n\n");
      matches = 0; // On met le nombre d'allumette à 0 afin de sortir de la boucle, ce qui arretera le jeu
    } else { // autrement :
      if (matches == 1) { // Si le nombre d'allumette est de 1 alors "l'IA forte" a gagnée
        printf("\nIA forte a gagnée\n\n");
        matches = 0;
      } else { // autrement :
        printf("\nl'ordinateur nul joue :\n\n");
        nb_matches_out_AIB = rand() % 4; // "L'IA" tire aléatoirement un nombre d'allumette compris entre 0 et 4 (1, 2 ou 3)
        matches -= nb_matches_out_AIB; // On soustrait au nombre d'allumette le nombre d'allumette tiré aléatoirement par "l'IA nulle"
        printf("Il reste maintenant %d allumettes\n", matches);
        if(matches == 0  || matches < 0){ // Si le nombre d'allumette est de 0 ou est inférieur à 0 alors "l'IA forte" a gagnée
                    printf("\nIA forte a gagnée\n\n");
                } else { // autrement :
                    if(matches == 1){ // Si le nombre d'allumette est de 1 alors "l'IA nulle" a gagnée 
                        printf("\nIA nulle a gagnée\n\n");
                        matches=0; 
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) { //fonction main qui traite le choix de l'utilisateur
  printf("[1] IA FAIBLE COMMENCE \n\n");
  printf("[2] IA FORTE COMMENCE \n\n");
  printf("-->");
  scanf("%d", &choice); //récupere le nombre entré

  switch (choice) { //création d'un menu selon le nombre entré
  case 1: //le nombre entré est 1 alors on éxecute la fonction "basicIAStart()"
    basicIAStart();
    break;
  case 2:
    hardIAStart(); //le nombre entré est 2 alors on éxecute la fonction "hardIAStart()"
    break;
  }
}
