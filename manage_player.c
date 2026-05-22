#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[20];
    unsigned int numero;
    char poste[10];
    int buts;
}joueur;
void tri(joueur tab[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(tab[j].buts<tab[j+1].buts){
                joueur temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }

}
int main(void){

    FILE *fichier=fopen("joueurs.txt","r");
    char ligne[100];
    int n=0;
    while(fgets(ligne,100,fichier)!=NULL){
        n++;
    }
    joueur *tab=calloc(n,sizeof(joueur));
    rewind(fichier);

    for(int i=0;i<n;i++){
        fscanf(fichier, "%s %u %s %d", tab[i].nom, &tab[i].numero, tab[i].poste, &tab[i].buts);
    }
    fclose(fichier);


    for(int i=0;i<n;i++){
        printf("Nom: %s, Numero: %u, Poste: %s, Buts: %d\n", tab[i].nom, tab[i].numero, tab[i].poste, tab[i].buts);
    }
    printf("\n\n");
    tri(tab,n);
    for(int i=0;i<n;i++){
        printf("%d Nom: %s, Buts: %d\n", i+1, tab[i].nom, tab[i].buts);
    }
    fichier=fopen("joueurs.txt","a");
    int run;
    printf("Voulez-vous continuer à ajouter des joueurs? (0 pour oui, 1 pour non): ");
    scanf("%d", &run);
    while(run==0){
        tab=realloc(tab, (n+1)*sizeof(joueur));
        printf("Entrez le nom du joueur %d: ", n+1);
        scanf("%s",tab[n].nom);
        printf("Entrez le numero du joueur %d: ", n+1);
        scanf("%u",&tab[n].numero);
        printf("Entrez le poste du joueur %d: ", n+1);
        scanf("%s",tab[n].poste);
        printf("Entrez le nombre de buts du joueur %d: ", n+1);
        scanf("%d",&tab[n].buts);
        n++;
        fprintf(fichier, "%s %u %s %d\n", tab[n-1].nom, tab[n-1].numero, tab[n-1].poste, tab[n-1].buts);
        printf("Voulez-vous continuer à ajouter des joueurs? (0 pour oui, 1 pour non): ");
        scanf("%d", &run);
    }
    fclose(fichier);
    free(tab);
    return 0;
}








































/*#include <stdio.h>
#include <stdlib.h>
int main(void){


    typedef struct{
        char nom[20];
        unsigned int numero;
        char poste[10];
    }joueur;
    FILE *fichier =fopen("joueurs.txt","a");
    int n=5;
    joueur *tab=calloc(n,sizeof(joueur));
    int run=0;
    while(run==0){
        for(int i=0; i<n && run==0;i++){
            printf("Entrez le nom du joueur %d: ", i+1);
            scanf("%s",tab[i].nom);
            printf("Entrez le numero du joueur %d: ", i+1);
            scanf("%u",&tab[i].numero);
            printf("Entrez le poste du joueur %d: ", i+1);
            scanf("%s",tab[i].poste);
            fprintf(fichier, "Nom: %s, Numero: %u, Poste: %s\n", tab[i].nom, tab[i].numero, tab[i].poste);
            if(i==n-1){
                n*=2;
                tab=realloc(tab, n*sizeof(joueur));
                }
            printf("Voulez-vous continuer à ajouter des joueurs? (0 pour oui, 1 pour non): ");
            scanf("%d", &run);    
        }
        
    }
    fclose(fichier);
    fichier =fopen("joueurs.txt","r");
    char ligne[100];
    while(fgets(ligne,100,fichier)!=NULL){
        printf("%s",ligne);
    }
    fclose(fichier);
    return 0;
}*/