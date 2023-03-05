
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


int agelist[500000];

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;
Node* agestore[500000];


int compare_node(const void *a,const void *b){
        const Node**ia=(const Node**)a;
        const Node**ib=(const Node**)b;
        if((*ia)->age==(*ib)->age){
            return (*ia)->number-(*ib)->number;
        }
        else{
            return (*ia)->age-(*ib)->age;
        }
        

}

Node* createList(int n){
    for(int i=0;i<n;i++){
        scanf("%d",&agelist[i]);
        
    }
    //
    /*for(int i=0;i<n;i++){
        printf("%d",agelist[i]);
    }*/

    int index=1;
    head=malloc(sizeof(Node));
    Node* temp=head;
    head->number=index;

    head->age=agelist[0];
    
    head->prev=head;
    head->next=head;
    agestore[0]=head;
   
    index+=1;

    for(int i=1;i<n;i++){
        
        Node *new=malloc(sizeof(Node));
        agestore[i]=new;
         
        new->age=agelist[i];
        //printf("%d",agestore[i]->age);
        
        new->number=index;
        index+=1;
                
        
        new->next=head;
        head->prev=new;
        new->prev=temp;
        temp->next=new;
        temp=new;
    }

    qsort(agestore,n,sizeof(Node*),compare_node);

    

    return head;

}



Node* solve(int n, int m){
    int number,time;
    char direction;
    for(int i=0;i<m;i++){
        scanf("%d %d %c",&number,&time,&direction);
        Node*goal=agestore[number-1];
        
        

        Node*goal2=goal;
        Node*goal3=goal;
        

        Node *new=malloc(sizeof(Node));
        agestore[number-1]=new;
        
        new->age=goal->age;
        new->number=goal->number;
        

        

        if(time>n-1){
            time%=(n-1);
        }

        if(direction=='L'){
            //printf("enter\n");
            for(int i=0;i<time;i++){
                goal2=goal2->prev;
            }
            goal3=goal2->prev;

            new->next=goal2;
            new->prev=goal3;
            goal2->prev=new;
            goal3->next=new;
        }
        else if(direction=='R'){
            
            for(int i=0;i<time;i++){
                goal2=goal2->next;
            }
            goal3=goal2->next;
            new->next=goal3;
            new->prev=goal2;
            goal2->next=new;
            goal3->prev=new;
        }

        goal->next->prev=goal->prev;
        goal->prev->next=goal->next;
        free(goal);
    }


    Node*P=agestore[0];
    
    return P;

}

#endif
