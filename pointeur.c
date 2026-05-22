#include <stdio.h>
#include <stdlib.h>

void afficher_membre(char **tab_nom,char **tab_nationalite,int n){
    printf("Nom ------> Nationalité \n");
    for(int i=0;i<n;i++){
        if(tab_nom[i]==NULL || tab_nationalite[i]==NULL){
            continue;
        }
        printf("%s ---> %s\n",tab_nom[i],tab_nationalite[i]);
    }
}

int main(void){
    int n=5;

    char **tab_nom=calloc(n,sizeof(char*));
    char **tab_nationalite=calloc(n,sizeof(char*));

    int run=0;

    while(run==0){
        for(int i=0;i<n && run==0;i++){

            tab_nom[i]=calloc(20,sizeof(char));
            tab_nationalite[i]=calloc(20,sizeof(char));

            printf("Nom : ");
            scanf("%19s",tab_nom[i]);

            printf("Nationalité : ");
            scanf("%19s",tab_nationalite[i]);

            if(i==n-1){
                n*=2;

                tab_nom=realloc(tab_nom,n*sizeof(char*));
                tab_nationalite=realloc(tab_nationalite,n*sizeof(char*));
            }

            printf("Continuer(0)/stop(1): ");
            scanf("%d",&run);
        }
    }

    afficher_membre(tab_nom,tab_nationalite,n);

    for(int i=0;i<n;i++){
        free(tab_nom[i]);
        free(tab_nationalite[i]);
    }

    free(tab_nom);
    free(tab_nationalite);

    return 0;
}




























/*#include <stdio.h>
#include <stdlib.h>

typedef struct{
        char nom[50];
        int numero;
    }joueur;

void afficher_joueurs(joueur *tab,int n){
    printf("Joueurs ------> Numero \n");
    for(int i=0;i<n;i++){
        printf("%s--->%d\n",tab[i].nom,tab[i].numero);
    }
}

int main(void){
    
    int n;
    printf("Combien de joueur voulez vous entré: ");
    scanf("%d",&n);
    joueur *tab=malloc(n*sizeof(joueur));

    for(int i=0;i<n;i++){
        printf("joueur-%d Nom: ",i+1);
        scanf("%s",tab[i].nom);
        printf("joueur-%d numero: ",i+1);
        scanf("%d",&tab[i].numero);
    }
    afficher_joueurs(tab,n);
    free(tab);
    return 0;
}*/


































/*#include <stdio.h>
#include <stdlib.h>
int main(void){

    int x=10;
    int y=20;
    int *p=&x;
    int *q=&y;
    int t=*q;
    *q=*p;
    *p=t;
    char *tab=calloc(10,sizeof(char));

    for(int i=0;i<10;i++){
        printf("tab[%d] Adresse: %p\n",i,tab[i]);
        
    }
    tab[0]='H';
    tab[1]='E';
    tab[2]='L';
    tab[3]='L';     
    tab[4]='O'; 
    tab[5]='t';
    tab[6]='h';
    tab[7]='e';
    tab[8]='r';
    tab[9]='e';
    for(int i=0;i<10;i++){
        printf("tab[%d]=%c Adresse: %p\n",i,tab[i],tab[i]);
    }
    

    printf("valeur de y %d-- Adresse %p\n",y,&y);
    printf("Valeur de x %d-- Adresse %p\n",x,&x);
    printf("pointeur p valeur: %d adresse: %p\n",*p,p);
    printf("pointeur q valeur: %d adresse: %p\n",*q,q);

    return 0;
}*/