#include <stdio.h>
#include <stdlib.h>

typedef struct dlist
{
    int data ;
    struct dlist *next;
    struct dlist *prev;
} Dlist;
/////////////////
void assignN(Dlist* list){
    list->next = NULL;
    list->prev = NULL;
}
////////////////////////
Dlist *createnode(Dlist *list ,int val){
    Dlist *newnode = malloc(sizeof(Dlist));
    newnode->data = val;
        newnode->next = NULL;
        newnode->prev = NULL;
    return newnode;
}
////////////////////////
Dlist *insertnode(Dlist* list ,int val){
    Dlist* newnode = createnode(list,val);
     Dlist* p =list;
     if(list== NULL){
      list =newnode;
      list->prev = NULL;
     }else{
     while(p->next!=NULL){
        p= p->next;

     }
     p->next = newnode;
     newnode->prev = p;
      }
     return list;
  }
  ///////////////////////////////////
int option(Dlist* list ,int val){
    Dlist* p = list;
    if (list == NULL){
       return -1;
    }else{
        while(p!= NULL){
            if( p->data == val){
               return  1;
            }
            p = p->next;
        }
    }
    return 0;
    }
    ////////////////////////////////
 void searchnode(Dlist* list, int val){
   switch(option(list,val)){
   case -1:
       printf("\nthe list is empty ");
       break;
   case 1 :
       printf("\n%d found",val);
       break;
    case 0:

       printf("\n%d not found",val);
       break;
   }
 }

void affiche(Dlist *list){
    Dlist *p = list;
if ( list== NULL){
    printf("the list is empty\N");
    return NULL;
}
while (p != NULL ){
    printf("%d_",p->data);
    p = p->next;
}
return NULL;
}
//////////////////////////
Dlist * delete(Dlist* list , int val ){



}
int main()
{
    Dlist * TEST =NULL;
   // affiche(TEST);
   TEST = insertnode(TEST,5);
     TEST =insertnode(TEST,3);
      TEST =insertnode(TEST,2);
     TEST =  insertnode(TEST,1);
affiche(TEST);

    searchnode(TEST, 5);


    return 0;
}
