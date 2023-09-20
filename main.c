#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  char titre[10];
  char description[100];
  int status;
}Tache;

Tache tab[100];

void ajouterTache(){
  Tache t;
  printf("ajouter une nouvelle tache \n");
  printf("id : ");
  scanf("%d", t.id);
  printf("titre : ");
  scanf("%s",t.titre);
  printf("description : ");
  scanf("%s",t.description);
  printf("status :\n <1> a realiser \n <2> encore \n <3> finalisee \n ");
  scanf("%d",t.status);

 // if(t.status<1 || t.status>3) printf("<1> a realiser \n <2> encore \n <3> finalisee ");
}

void ajouterPlusieur(){
   int nbr;
   printf("enter le nombre des taches a ajouter et entrer <0> pour finir : ");
   scanf("%d \n", &nbr);

   while(nbr != 0){
     for(int i=0; i<nbr; i++){
    printf("tache %d \n", i);
    printf("id : ");
    scanf("%d", tab[i].id);
    printf("titre : ");
    scanf("%s", tab[i].titre);
    printf("description : ");
    scanf("%s", tab[i].description);
    printf("status :\n <1> a realiser \n <2> encore \n <1> finalisee \n ");
    scanf("%d", tab[i].status);
   }
   }

}

void affichage(){
 for(int i=0; i<100; i++){
    printf(" tache %d :", tab[i].id);
    printf("titre: %s", tab[i].titre);
    printf(" description : %s", tab[i].description);
     printf(" tache %d :",i);

 }
}






int main()
{
    int choix;

    printf("=============================================================\n\n");
printf("\t\t TODO list ");
printf("\n\n============================================================n\n");
printf("\t[1] Ajouter une nouvelle tache.\n");
printf("\t[2] Ajouter plusuiers taches.\n");
printf("\t[3] Afficher la liste de toutes les taches .\n");
printf("\t[4] Modifier une tache.\n");
printf("\t[5] Supprimer une tache.\n");
printf("\t[6] Rechercher une tache.\n");
printf("\t[7] Statistiques.txt\n");
printf("\t[8] Quitter.\n");
printf("==============================================================\n");
printf("tapez votre choix [1-6] \n");
scanf("%d", &choix);

switch(choix){
case 1:
    ajouterTache();
    break;
case 2:
    ajouterPlusieur();
    break;


    }




    return 0;
}
