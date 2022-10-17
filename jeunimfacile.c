#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int matches = 12; // Nombre d'allumettes
  int nb_matches_out_player = 0, nb_matches_out_AI = 0;
  int aws = 0; // Si la réponse est bonne aws = 1 autrement aws = 0

  while (matches > 0) // Tant que le nombre d'allumette est superieur à 0
  {
    while (!aws) // Tant que aws est différent de 0
    {
      printf("Combien d'allumettes voulez-vous enlever ?\n->");
      scanf("%d", &nb_matches_out_player); // Demande le nombre d'allumette que
                                           // l'on veut retirer
      if (nb_matches_out_player == 1 || nb_matches_out_player == 2 ||
          nb_matches_out_player ==
              3) { // Si le nombre d'allumette vaut 1, 2 ou 3 alors
        matches -=
            nb_matches_out_player; // enlever le nombre d'allumette qu'on a
                                   // voulu retirer au nombre d'allumette
                                   // "total" (valeur par défaut = 12)
        aws = 1; // mettre aws à 1 ce qui nous permet de sortir de la boucle
      } else {
        printf("Entrez une valeur comprise entre 1 et 3\n"); // Message d'erreur
      }
    }
    aws = 0; // On remet aws à 0 pour afin de répeter ce qui précède
    printf("Il reste maintenant %d\n", matches);

    if (matches ==
        0) { // Si le nombre d'allumette est de 0 alors on a perdu et on met le
             // nombre d'allumette à 0 pour sortir de la boucle
      printf("Vous avez perdu :(\n");
      matches = 0;
    } else {
      if (matches ==
          1) { // Si le nombre d'allumette est de 1 alors on a gagné et on met
               // le nombre d'allumette à 0 pour sortir de la boucle
        printf("Vous avez gagné !\n");
        matches =
            0; // On met le nombre d'allumette à 0 afin de sortir de la boucle
      } else {
        nb_matches_out_AI =
            rand() % 4; // "L'IA" tire aléatoirement un nombre d'allumette
                        // compris entre 0 et 4 (1, 2 ou 3)
        matches -=
            nb_matches_out_AI; // On soustrait au nombre d'allumette le nombre
                               // d'allumette tiré aléatoirement par "l'IA"
        printf("Il reste maintenant %d\n", matches);
        if (matches == 0 ||
            matches < 0) { // Si le nombre d'allumette vaut 0 ou est inférieur à
                           //à 1 alors le joueur (nous) a perdu
          printf("Vous avez perdu :(((((\n");
        } else {
          if (matches == 1 ||
              matches < 1) { // Si le nombre d'allumette vaut 1 ou est inférieur
                             // 0 alors "l'IA" a perdu
            printf("L'ordi a perdu ! [:)]\n");
            matches = 0; // On met le nombre d'allumette à 0 afin de sortir de
                         // la boucle
          }
        }
      }
    }
  }
  printf("     ┌─────────────┐\n");
  printf("     │    AUTHOR   │\n");
  printf("┌──┬─┤     REMY    │\n");
  printf("│┼┼│ │   TIZIANO   │\n");
  printf("└──┴─┴──┬────────┬─┘\n");
  printf("        │        │\n");
  printf("       ─┘       ─┘\n");
}