#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>



typedef struct {
    int anne;
    int mois;
    int jour;

}date;

typedef struct {
  int id;
  char titre[10];
  char description[100];
  date deadline;
  int status;

}Tache;


Tache tab[100];
int n, i;
int contId =0;

void ajouterTache(){

  printf("ajouter une nouvelle tache \n");
  printf("titre : ");
  scanf("%s", tab[i].titre);
  printf("description : ");
  scanf(" %[^\n]", tab[i].description);
  printf("deadline :\n ");
  printf("jour :");
  scanf("%d", &tab[i].deadline.anne);
  printf("mois :");
  scanf("%d", &tab[i].deadline.mois);
  printf("annee :");
  scanf("%d", &tab[i].deadline.jour);
  printf("status :\n <1> a realiser \n <2> encore \n <3> finalisee \n ");
  scanf("%d", &tab[i].status);
    contId++;
    tab[i].id=contId;

    }


 // if(t.status<1 || t.status>3) printf("<1> a realiser \n <2> encore \n <3> finalisee ");


void ajouterPlusieur(){

   printf("enter le nombre des taches a ajouter : ");
   scanf("%d", &n);

     for(i=0;i<n; i++){
       ajouterTache();
   }
   }


void afficher(){
 for(i=0;i<n; i++){
    printf(" tache %d : \n", tab[i].id);
    printf("titre: %s \n", tab[i].titre);
    printf(" description : %s \n", tab[i].description);
    printf(" deadline : %d/%d/%d \n", tab[i].deadline.jour, tab[i].deadline.mois, tab[i].deadline.anne);
    printf(" status %d \n\n", tab[i].status);

}}

void triOrdreAlpha(){
  printf("la liste des taches par ordre alphabetique : \n");
  int result;
  Tache c;
  for(i=0;i<n;i++){
//       tab[i].titre=tolower(tab[i].titre);
      for(int j=i+1;j<n;j++){

        result=strcmp(tab[i].titre, tab[j].titre);
        if(result>0){
        c=tab[i];
        tab[i]=tab[j];
        tab[j]=c;
        }
      }
   }
   afficher();
 }




void affichage(){
    int choix2;
    printf("<1> Trier les taches par ordre alphabetique.\n");
    printf("<2> Trier les taches par deadline.\n");
    printf("<3> Afficher les tâches dont le deadline est dans 3 jours ou moins.\n");
    scanf("%d", &choix2);
    switch(choix2){
case 1:
    afficher();
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

void modification(){
    int choix3;
    int a;
    printf("entrer id de tache a modifier  ");
    scanf("%d", &a);
    for(i=0;i<n; i++){
        if(tab[i].id==a){
            printf("<1> Modifier la description d'une tache.\n");
            printf("<2> Modifier le statut d’une tache.\n");
            printf("<3> Modifier le deadline d’une tache.\n");
            scanf("%d", &choix3);
                switch(choix3){
                    case 1:
                        printf("entrer la nouvelle description : ");
                        scanf(" %[^\n]", tab[i].description);
                        break;
                    case 2:
                        printf("status :\n <1> a realiser \n <2> encore \n <3> finalisee \n ");
                        scanf("%d", &tab[i].status);
                        break;
                    case 3:
                        printf("entrer le nouveau deadline : \n");
                        printf("jour :");
                        scanf("%d", &tab[i].deadline.anne);
                        printf("mois :");
                        scanf("%d", &tab[i].deadline.mois);
                        printf("annee :");
                        scanf("%d", &tab[i].deadline.jour);
                        break;
                    default:
                        printf("entrer un nombre entre 1 ET 3");
                        break;
                    }
        }else{
        printf("la tache n'existe pas");
        }
    }

}


void supprimer(){
    int a;
 printf("entrer id de la tache a supprimer: ");
 scanf("%d", &a);
 for(i=0;i<n;i++){
    if(tab[i].id==a){
        for(int j=i;j<n-1;j++){
            tab[j]=tab[j+1];
            n--;
            i--;
        }
    }
 }


}


void chercherId(){

     int a;
     printf("entrer id de la tache  : ");
     scanf("%d", &a);
     for(i=0;i<n;i++){
        if(tab[i].id==a){
             printf(" tache %d : \n", tab[i].id);
             printf("titre: %s \n", tab[i].titre);
             printf(" description : %s \n", tab[i].description);
             printf(" deadline : %d/%d/%d \n", tab[i].deadline.jour, tab[i].deadline.mois, tab[i].deadline.anne);
             printf(" status %d \n\n", tab[i].status);

        }
     }

}

void chercherTitre(){
    char temp[10];
    printf("entrer le titre de la tache : ");
    scanf("%s", temp);
    for(i=0;i<n;i++){
        int result =strcmp(tab[i].titre,temp);
        if(result==0){
             printf(" tache %d : \n", tab[i].id);
             printf("titre: %s \n", tab[i].titre);
             printf(" description : %s \n", tab[i].description);
             printf(" deadline : %d/%d/%d \n", tab[i].deadline.jour, tab[i].deadline.mois, tab[i].deadline.anne);
             printf(" status %d \n\n", tab[i].status);

        }
    }



}

void rechercher(){
    int choix4;
    int a;
     printf("<1> Rechercher une tache par son Identifiant.\n");
     printf("<2> Rechercher une tache par son Titre.\n");
     scanf("%d", &choix4);
     switch(choix4){
 case 1:
     chercherId();
    break;
 case 2:
     chercherTitre();
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
printf("tapez votre choix [1-6] : ");
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
    afficher();
    break;
case 4:
    modification();
    break;
case 5:
    supprimer();
    break;
case 6:
    rechercher();
default:
    printf("ce choix n'existe pas entrer un nombre entre 1 et 7");
    break;

    }

}









    return 0;
}
