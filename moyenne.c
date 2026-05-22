#include <stdio.h>

float Calcul_moyenne(float tab[],int m,int c/*c pour la somme des coefs*/){
    float som_notes=0;
    float moyenne;
    for(int i=0;i<m;i++){
        som_notes+=tab[i];
        
        }
        
   
    return  som_notes/c;
    
    }
void mention(float moyenne){
    if (moyenne>=16){
        printf("Mention: Tres Bien");
    }
    else if (moyenne>=14){
        printf("Mention: Bien");
    }
    else if (moyenne>=12){
        printf("Mention: Assez Bien");
    }
    else if (moyenne>=10){
        printf("Mention: Passable");
    }
    else {
        printf("Mention: Echec");
    }
}    



int main(void){
    int n;   //nombre de matieres
    float note;
    int coef;
    int som_coef=0;
    float moyenne;
    
    printf("Entrer le nombre de matiere dont vous voulez calculer la moyenne:  ");
    scanf("%d",&n);
    while (n<=0){
        printf("Nombre de matieres invalide, entrer un nombre positif: ");
        scanf("%d",&n);
    }
    float tab[n];
    for (int i=0;i<n;i++){
        printf("Matiere %d: Note obtenu: ",i+1);        
        scanf("%f",&note);
        while(note<0 || note>20){
            printf("Note invalide, entrer une note entre 0 et 20: ");
            scanf("%f",&note);
        }
        printf("Matiere %d: coefficient: ",i+1);           
        scanf("%d",&coef);
        while (coef<=0){
            printf("Coefficient invalide, entrer un coefficient positif: ");
            scanf("%d",&coef);
        }
        som_coef+=coef;
        tab[i]=note*coef;
        } 
    printf("Somme des coefficients: %d\n",som_coef);  

    moyenne=Calcul_moyenne(tab,n,som_coef);
    printf("Moyenne: %.2f /20\n",moyenne);

    mention(moyenne);

    
    
    
    return 0;
    }