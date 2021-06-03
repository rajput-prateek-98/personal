#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void creation(int x){
    struct node *temp=head,*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
        newNode->prev=NULL;
    }
    else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}
void insert(int x,int pos){
    struct node *temp=head,*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(pos==1){  //first element
        if(head==NULL){
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
            newNode->prev=NULL;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }

}
void Remove(int pos){
    struct node *temp_prev=head,*temp_next;
    for(int i=0;i<pos-1;i++){
            temp_prev=temp_prev->next;

    }
    temp_next=temp_prev->next->next;
    temp_prev->next=temp_next;
    free(temp_prev->next);
}
int Search(int num){
    struct node *temp=head;
    int flag=0;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->data==num){
            flag=1;
            break;
        }
    }
    if(flag==1){
        return(1);
    }
    else{
        return(0);
    }

}
void print(){
    struct node *temp=head;
    printf("The linked list is\n");
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;

    }
    printf("\n");
}
int main(){
    int n,i,num,ch,pos;
    head=NULL;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the apace separated elements");
    for(i=0;i<n;i++){
        scanf("%d",&num);
        creation(num);
    }
    print();
    printf("Press 1 to enter at a specific position\n");
    printf("Pres 2 to Remove at any specific position\n");
    printf("Press 3 to search for an element\n");
    printf("Press 4 to exit\n");
    while(1){
        printf("Press the required number");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter the number and its respective position");
            scanf("%d %d",&num,&pos);
            insert(num,pos);
            print();
            break;
        case 2:
            printf("Enter the position of element to be deleted\n");
            scanf("%d",&pos);
            Remove(pos);
            print();
            break;
        case 3:
            printf("Enter the number to search\n");
            scanf("%d",&num);
            n=Search(num);
            if(n==0){
                print("Element not found\n");
            }
            else{
                print("Element Found\n");
            }
            break;
        case 4:
            exit(0);
            break;
        }

    }



}

