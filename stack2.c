#include <stdio.h>
#define MAX 100


int stack[MAX];
int top=-1;

void push(int value){
    if(top==MAX-1){
        printf("Stackoverflo\n");
    }
    top++;
    stack[top]=value;
}

void pop(){
    if(top==-1){
        printf("Stackunderflow\n");
    }
    printf("Removed: %d\n",stack[top]);
    top--;
}

void peek(){
    if(top==-1){
        printf("Stackunderflow\n");
    }
    printf("%d\n",stack[top]);
}

int main(){
    for(int i=0;i<100;i++){
        push(i*10);
    }
    return 0;
}