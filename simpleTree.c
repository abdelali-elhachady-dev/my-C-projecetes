#include <stdio.h>
#include <stdlib.h>
typedef struct node node;

struct node{
    int data;
    node* FG;
    node * FD;
};

//ode roote ={NULL,0,NULL};
node* createnode(int data){
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->FG = NULL;
    newnode->FD = NULL;
    return newnode;
}

node* addnode(node *root,int val){

    if(root == NULL){
       return  createnode(val);

    }

    if( val > root->data){
        root->FD = addnode(root->FD,val);
    }else{
        root->FG = addnode(root->FG ,val);
    }

   return root;
}

void affiche(node *root){
    if (root != NULL){
        affiche(root->FG);
    printf("the valeur is : %d\n",root->data);
    affiche(root->FD);

    }
}

void search(node *roote ,int valeu){
    if (roote== NULL){
   printf(" %d i didn't found it \n",valeu);
   return;
    }
     if (roote->data == valeu){
            printf("i found  : %d\n",roote->data);
            return;

    } else{
    if( valeu  >= roote->data){
     search(roote->FD,valeu);
     }else{

  //  printf("the valeur is : %d",root->data);
    search(roote->FG,valeu);


     }

    }

}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
   node * roote = NULL;
   roote = addnode(roote, 6);  // Update roote after each insertion
   roote = addnode(roote, 5);
   roote = addnode(roote, 4);
   roote = addnode(roote, 7);
   roote = addnode(roote, 2);
  search(roote ,44);
  search(roote ,4);
  search(roote ,7);

  affiche(roote);

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
