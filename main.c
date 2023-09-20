#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>



typedef struct {
    int jour;
    int heur;
    int min;

}deadline;

typedef struct {
  int id;
  char titre[10];
  char description[100];
  deadline dead;
  int status;

}Tache;


Tache tab[100];
int n, i;

void ajouterTache(){
    n=1;
  printf("ajouter une nouvelle tache \n");
  printf("id : ");
  scanf("%d", &tab[i].id);
  printf("titre : ");
  scanf("%s", tab[i].titre);
  printf("description : ");
  scanf(" %29[^\n]", tab[i].description);
  printf("deadline :\n ");
  printf("jour :");
  scanf("%d", &tab[i].dead.jour);
  printf("mois :");
  scanf("%d", &tab[i].dead.heur);
   printf("annee :");
  scanf("%d", &tab[i].dead.min);
  printf("status :\n <1> a realiser \n <2> encore \n <3> finalisee \n ");
  scanf("%d", &tab[i].status);
    }


 // if(t.status<1 || t.status>3) printf("<1> a realiser \n <2> encore \n <3> finalisee ");


void ajouterPlusieur(){

   printf("enter le nombre des taches a ajouter et entrer <0> pour finir : ");
   scanf("%d", &n);
     for(i=0;i<n; i++){
        printf("tache %d \n", i+1);
        printf("id : ");
        scanf("%d", &tab[i].id);
        printf("titre : ");
        scanf("%s", &tab[i].titre);
        printf("description : ");
        scanf(" %29[^\n]", &tab[i].description);
        printf("deadline : ");
        printf("jour :");
        scanf("%d", &tab[i].dead.jour);
        printf("mois :");
        scanf("%d", &tab[i].dead.heur);
        printf("annee :");
        scanf("%d", &tab[i].dead.min);
        printf("status :\n <1> a realiser \n <2> encore \n <1> finalisee \n ");
        scanf("%d", &tab[i].status);

   }
   }

void afficher(){
    for(i=0;i<n; i++){
    printf(" tache %d : \n", tab[i].id);
    printf("titre: %s \n", tab[i].titre);
    printf(" description : %s \n", tab[i].description);
    printf(" status %d \n\n", tab[i].status);

 }
}
void triOrdreAlpha(){
  printf("la liste des taches par ordre alphabetique : \n");
  int result;
  Tache c;
  for(i=0;i<n;i++){
      for(int j=i+1;j<n;j++){

        result=strcmp(tab[i].titre, tab[j].titre);
        if(result>0){
        c=tab[i];
        tab[i]=tab[j];
        tab[j]=c;
        }
      }
   }
    for(i=0;i<n; i++){
    printf(" tache %d : \n", tab[i].id);
    printf("titre: %s \n", tab[i].titre);
    printf(" description : %s \n", tab[i].description);
    printf(" status %d \n\n", tab[i].status);

 }
}



void affichage(){
    int choix2;
    printf("<1> Trier les taches par ordre alphabetique.\n");
    printf("<2> Trier les taches par deadline.\n");
    printf("<3> Afficher les tâches dont le deadline est dans 3 jours ou moins.\n");
    scanf("%d", &choix2);
    switch(choix2){
case 1:
    triOrdreAlpha();
    break;
case 2:
    break;
case 3:
    break;
default:
    printf("entrer un nombre entre 1 ET 3");
    break;
    }

}






int main()
{

    int choix;

    printf("=============================================================\n\n");
printf("\t\t TODO list ");
printf("\n\n============================================================ \n\n");
while(1){
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
if(choix==8) break;

switch(choix){
case 1:
    ajouterTache();
    break;
case 2:
    ajouterPlusieur();
    break;
case 3:
    affichage();
    break;
default:
    printf("ce choix n'existe pas entrer un nombre entre 1 et 7");
    break;

    }

}









    return 0;
}
