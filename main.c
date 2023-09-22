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
int n=0, i;
int contId =0;

/*void ajouterTache(){

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
    n++;

    }*/


 // if(t.status<1 || t.status>3) printf("<1> a realiser \n <2> encore \n <3> finalisee ");


void ajouter(){
    int z;
   printf("enter le nombre des taches a ajouter : ");
   scanf("%d", &z);
     for(i=0; i<z; i++){
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
    n++;
   }
   }


void afficher(){
 for(i=0;i<n; i++){
    printf(" tache %d : \n", tab[i].id);
    printf("titre: %s \n", tab[i].titre);
    printf(" description : %s \n", tab[i].description);
    printf(" deadline : %d/%d/%d \n", tab[i].deadline.anne, tab[i].deadline.mois, tab[i].deadline.jour);
    printf(" status %d \n\n", tab[i].status);

}}

void triOrdreAlpha(){
  printf("la liste des taches par ordre alphabetique : \n");
  int result;
  Tache c;
  for(i=0;i<n;i++){
    //  tab[i].titre[i]=tolower(tab[i].titre[i]);
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


void triDeadline(){
    printf("la liste des taches par deadline : \n");
    Tache t;
    for(i=0;i<n;i++){
        int result1=(tab[i].deadline.anne*365) + (tab[i].deadline.mois*30)+ tab[i].deadline.jour;
        for(int j=i+1;j<n; j++){
              int result2=(tab[j].deadline.anne*365) + (tab[j].deadline.mois*30)+ tab[j].deadline.jour;
            if(result1>result2){
               t=tab[j];
               tab[j]=tab[i];
               tab[i]=t;
            }
        }
    }
    afficher();
}

void triJour(){
    int jourAc, moisAc, anneAc;
    time_t dateActuel;
    struct tm* local = localtime(&dateActuel);
    time(&dateActuel);
    jourAc=local->tm_mday;
    moisAc=local->tm_mon +1;
    anneAc=local->tm_year + 1900;
    for(i=0; i<n;i++){
        int jousRestants=(tab[i].deadline.anne - anneAc)*365 +(tab[i].deadline.mois - moisAc)*30 +(tab[i].deadline.jour);
        if(jousRestants<4){
            printf("les  les taches dont le deadline est dans 3 jours ou moins ");
            printf(" tache %d : \n", tab[i].id);
            printf("titre: %s \n", tab[i].titre);
            printf(" description : %s \n", tab[i].description);
            printf(" deadline : %d/%d/%d \n", tab[i].deadline.anne, tab[i].deadline.mois, tab[i].deadline.jour);
            printf(" status %d \n\n", tab[i].status);
        }
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
    triDeadline();
    break;
case 3:
    triJour();
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
                        printf("la tache est bien modifier");
                        break;
                    case 2:
                        printf("status :\n <1> a realiser \n <2> encore \n <3> finalisee \n ");
                        scanf("%d", &tab[i].status);
                        printf("la tache est bien modifier");
                        break;
                    case 3:
                        printf("entrer le nouveau deadline : \n");
                        printf("jour :");
                        scanf("%d", &tab[i].deadline.anne);
                        printf("mois :");
                        scanf("%d", &tab[i].deadline.mois);
                        printf("annee :");
                        scanf("%d", &tab[i].deadline.jour);
                        printf("la tache est bien modifier");
                        break;
                    default:
                        printf("entrer un nombre entre 1 ET 3");
                        break;
                    }
                       }else{
                               printf("la tache n'existe pas");}
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
 printf("la tache est supprimee");
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
void nbrTacheComp(){
    int count1=0;
    int count2=0;
    for(i=0;i<n;i++){
        if(tab[i].status==1 || tab[i].status==2) count1++;
        if(tab[i].status==3) count2++;
    }
    printf("le nombre des taches    completes : %d \t", count2);
    printf(" incomplètes : %d", count1);

}
void statistique(){
    printf("le nombre total des tache: %d \n\n", n);
    nbrTacheComp();
}





int main()
{

    int choix;

    printf("=============================================================\n\n");
printf("\t\t TODO list ");
printf("\n\n============================================================ \n\n");
while(1){
printf("\t[1] Ajouter des taches.\n");
printf("\t[2] Afficher la liste de toutes les taches .\n");
printf("\t[3] Modifier une tache.\n");
printf("\t[4] Supprimer une tache.\n");
printf("\t[5] Rechercher une tache.\n");
printf("\t[6] Statistiques\n");
printf("\t[7] Quitter.\n");
printf("==============================================================\n");
printf("tapez votre choix [1-6] : ");
scanf("%d", &choix);
if(choix==7) break;

switch(choix){
case 1:
    ajouter();
    break;
case 2:
    affichage();
    break;
case 3:
    modification();
    break;
case 4:
    supprimer();
    break;
case 5:
    rechercher();
    break;
case 6:
    statistique();
default:
    printf("ce choix n'existe pas entrer un nombre entre 1 et 7");
    break;

    }

}









    return 0;
}
