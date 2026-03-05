#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

int main(){
    int n,c,e;
    scanf("%d",&n);

    struct Node *head=NULL,*tail=NULL;

    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);

        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->coeff=c;
        temp->exp=e;
        temp->next=NULL;

        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }

    struct Node* curr=head;

    while(curr){
        if(curr->exp>1)
            printf("%dx^%d",curr->coeff,curr->exp);
        else if(curr->exp==1)
            printf("%dx",curr->coeff);
        else
            printf("%d",curr->coeff);

        if(curr->next)
            printf(" + ");

        curr=curr->next;
    }

    return 0;
}