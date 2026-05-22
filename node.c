#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* ajouter(struct Node *noeud1,int value){
    struct Node *new=malloc(sizeof(struct Node));
    new->next=noeud1;
    new->data=value;
    new->prev=NULL;
    if(noeud1!=NULL){
        noeud1->prev=new;
    }

    return new;
}

void supprimer_liste(struct Node* head){
    struct Node* temp=head->next;
    free(head);
    while(temp!=NULL){
        struct Node* temp1=temp->next;
        free(temp);
        temp=temp1;
    }
}

int main(void){
    struct Node *n1=malloc(sizeof(struct Node));
    struct Node *n2=malloc(sizeof(struct Node));
    struct Node *n3=malloc(sizeof(struct Node));

    if((n1==NULL) || (n2==NULL) || (n3==NULL)){
        printf("Memory allocation failed\n");
        return 1;
    }
    n1->data=10;
    n1->next=n2;
    n1->prev=NULL;
    n2->data=20;
    n2->next=n3;
    n2->prev=n1;
    n3->data=30;
    n3->next=NULL;
    n3->prev=n2;


//""""""""""""""""""""""""""""1"""""""""""""""""""""""""""""""
    struct Node *current=n1;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("\n");

    current=n1;
    while(current!=NULL){
        printf("Node adress: %p    Next adress: %p\n",current,current->next);
        current=current->next;
    }

   
    struct Node* head;
    head=ajouter(n1,0);
    current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("\n");

    current=head;
    while(current!=NULL){
        printf("Node adress: %p    Next adress: %p\n",current,current->next);
        current=current->next;
    }

    printf("AFFICHAGE IINVERSE\n");
    current=n3;
    while(current!=NULL){
        printf("Node adress: %p    prev adress: %p\n",current,current->prev);
        current=current->prev;
    }
    current=n3;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->prev;
    }
    printf("\n");
    

    free(n1);
    free(n2);
    free(n3);
    free(head);
    return 0;
}