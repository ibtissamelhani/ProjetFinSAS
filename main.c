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


void ajouter(){
    int z;
   printf("enter le nombre des taches a ajouter : ");
   scanf("%d", &z);
     for(i=0;i<z; i++){
        printf("\n\n");
        printf("ajouter une tache \n");
        printf("titre : ");
        scanf("%s", tab[i].titre);
        printf("description : ");
        scanf(" %[^\n]", tab[i].description);
        printf("deadline :\n ");
        printf("jour :");
        scanf("%d", &tab[i].deadline.jour);
        printf("mois :");
        scanf("%d", &tab[i].deadline.mois);
        printf("annee :");
        scanf("%d", &tab[i].deadline.anne);
        printf("status :\n <1> a realiser \n <2> en cours \n <3> finalisee \n ");
        scanf("%d", &tab[i].status);
        contId++;
        tab[i].id=contId;
        n++;
   }
   }

   void supprimer(){
        int a;
        printf("\n\n");
        printf("entrer id de la tache a supprimer: ");
        scanf("%d", &a);
        for(i=0;i<n;i++){
            if(tab[i].id==a){
            for(int j=i;j<n-1;j++){
                tab[j]=tab[j+1];
                n--;
        }
    }
 }
    printf("la tache est supprimee \n\n");
}


void afficher(){
    for(i=0;i<n; i++){
        printf("\n\n");
        printf(" tache %d : \n\n", tab[i].id);
        printf("titre: %s \n", tab[i].titre);
        printf(" description : %s \n", tab[i].description);
        printf(" deadline : %d/%d/%d \n", tab[i].deadline.anne, tab[i].deadline.mois, tab[i].deadline.jour);
        printf("statut : ");
        if(tab[i].status ==1) printf("a realiser\n\n");
        if(tab[i].status ==2) printf("en cours de realisation\n\n");
        if(tab[i].status ==3) printf("finalisee\n\n");

    }
}



//Trier les tâches par ordre alphabétique

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
   afficher();
 }


 //Trier les tâches par deadline

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

//Afficher les tâches dont le deadline est dans 3 jours ou moins
void triJour(){
     int jourAc, moisAc, anneAc;
     time_t currentTime=time(NULL) ;
     struct tm tm = *localtime(&currentTime);

     anneAc = tm.tm_year + 1900;
     moisAc =tm.tm_mon +1;
     jourAc = tm.tm_mday;
     int b= anneAc*365;
            b=b+moisAc*30;
            b=b+jourAc;
        for( int k=0; k<n ;k++){
            int a=(tab[k].deadline.anne)*365;
                a=a+(tab[k].deadline.mois)*30;
                a=a+(tab[k].deadline.jour);
                int result=(a-b);
            if(result<=3 && result>=0){
                printf("les taches dont le deadline est dans 3 jours ou moins :\n\n");
                printf(" tache %d : \n\n", tab[k].id);
                printf("titre: %s \n", tab[k].titre);
                printf(" description : %s \n", tab[k].description);
                printf(" deadline : %d/%d/%d \n", tab[k].deadline.anne, tab[k].deadline.mois, tab[k].deadline.jour);
                printf("statut : ");
                if(tab[k].status ==1) printf("a realiser\n\n");
                if(tab[k].status ==2) printf("en cours de realisation\n\n");
                if(tab[k].status ==3) printf("finalisee\n\n");
        }
     }

}



void affichage(){
        int choix2;
        afficher();
        while(1){
        printf("\n\n");
        printf("<1> Trier les taches par ordre alphabetique.\n");
        printf("<2> Trier les taches par deadline.\n");
        printf("<3> Afficher les taches dont le deadline est dans 3 jours ou moins.\n");
        printf("<4> Retourner au menu principal.\n");
        scanf("%d", &choix2);
        if(choix2==4) break;
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
                printf("entrer un nombre entre 1 ET 4");
                break;
    }
        }

}

void modification(){
    int choix3;
    int a;
    printf("\n\n");
    printf("entrer id de tache a modifier:  ");
    scanf("%d", &a);
    for(i=0;i<n; i++){
        if(tab[i].id==a){
            printf("<1> Modifier la description de la tache.\n");
            printf("<2> Modifier le statut de la tache.\n");
            printf("<3> Modifier le deadline de la tache.\n");
            printf("\n\n");
            scanf("%d", &choix3);
                switch(choix3){
                    case 1:
                        printf("encienne description de la tache : %s", tab[i].description);
                        printf("\n\n");
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
                        printf("entrer le nouveau deadline : \n\n");
                        printf("jour :");
                        scanf("%d", &tab[i].deadline.anne);
                        printf("mois :");
                        scanf("%d", &tab[i].deadline.mois);
                        printf("annee :");
                        scanf("%d", &tab[i].deadline.jour);
                        printf("\n\n");
                        printf("la tache est bien modifier");
                        break;
                    default:
                        printf("entrer un nombre entre 1 ET 3");
                        break;
                    }

                    }
    }

}





//Rechercher une tâche par son Identifiant.

void chercherId(){

     int a;
     printf("\n\n");
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

//Rechercher une tâche par son Titre
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
    while(1){
     printf("<1> Rechercher une tache par son Identifiant.\n");
     printf("<2> Rechercher une tache par son Titre.\n");
     printf("<3> Retourner au menu principal.\n");
     scanf("%d", &choix4);
     if(choix4==3) break;
     switch(choix4){
        case 1:
            chercherId();
            break;
        case 2:
            chercherTitre();
            break;
            }
    }

}



//Afficher le nombre de tâches complètes et incomplètes

void nbrTacheComp(){
    int count1=0;
    int count2=0;
    for(i=0;i<n;i++){
        if(tab[i].status==1 || tab[i].status==2) count1++;
        if(tab[i].status==3) count2++;
    }
    printf("le nombre des taches    completes : %d \t", count2);
    printf(" incompletes : %d", count1);

}


//Afficher le nombre de jours restants jusqu'au délai de chaque tâche
void jourREST(){
    int jourAc, moisAc, anneAc;
    time_t currentTime=time(NULL) ;
    struct tm tm = *localtime(&currentTime);

     anneAc = tm.tm_year + 1900;
     moisAc =tm.tm_mon +1;
     jourAc = tm.tm_mday;
     int b= anneAc*365;
            b=b+moisAc*30;
            b=b+jourAc;
     for( int k=0; k<n ;k++){
            int a=(tab[k].deadline.anne)*365;
                a=a+(tab[k].deadline.mois)*30;
                a=a+(tab[k].deadline.jour);
                int result=(a-b);
                printf("le delai de la tache : %d est : %d \n\n", tab[k].id,result);
                }
}


void statistique(){
    int choix4;
    while(1){
         printf("<1> afficher nombre total des tache.\n");
     printf("<2> Afficher le nombre de taches complètes et incomplètes.\n");
     printf("<3> Afficher le nombre de jours restants jusqu'au délai de chaque tache.\n");
     printf("<4> retourner au menu principal.\n");
     scanf("%d", &choix4);
     if(choix4==4) break;
     switch(choix4){

        case 1:
            printf("le nombre total des taches %d", n);
            break;
        case 2:
            nbrTacheComp();
            break;
        case 3:
            jourREST();
            break;
        default:
            printf("entrer un nombre entre 1 et 4");
            break;
     }

    }



}


int main()
{
    int choix1;
    char choix[10];
printf("====================================================================================================\n\n");
printf("\t\t\t TODO list ");
printf("\n\n================================================================================================ \n\n");
while(1){
printf("\n\n");
printf("\t[1] Ajouter des taches.\n");
printf("\t[2] Afficher la liste de toutes les taches .\n");
printf("\t[3] Modifier une tache.\n");
printf("\t[4] Supprimer une tache.\n");
printf("\t[5] Rechercher une tache.\n");
printf("\t[6] Statistiques.\n");
printf("\t[7] Quitter.\n");
printf("\n\n");
printf("===================================================================================================\n");
printf("tapez votre choix [1-7] : ");
scanf("%s", choix);
choix1 = atoi(choix);
if(choix1==7) break;

switch(choix1){
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
    break;
default:
    printf("ce choix n'existe pas entrer un nombre entre 1 et 7");
    break;

    }

}



    return 0;
}
