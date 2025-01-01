#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node * left;
    struct node *right;
    int height ;
}node;

 int max(node *nod) {
    int a = (nod->left != NULL) ? nod->left->height : 0;
    int b = (nod->right != NULL) ? nod->right->height : 0;
    return (a > b) ? a : b;
}

int height(node * nod){
  if (nod ==NULL)
      return 0;
  return nod->height;
}

int Blance(node *nod){
    if(nod == NULL)
    return 0;
    return height(nod->left)-height(nod->right);
}

node * leftrotation( node * root){                                                                                    /*
           Before Left Rotation (Imbalance at root)
               root                         (right-heavy root)
                 \
                 child
                   \
                    T2
            Left Rotation at root
               child                      (new root)
              /    \
           root      T2            (root becomes left child)
                                                                                         */
node *child = root->right;
node *T2 = child->left;

child->left= root;
root->right = T2;

root->height= max(root) + 1 ;
child->height = max(child) + 1 ;
    return child;
}
node * rightrotation( node * root){
/*           Before Right Rotation (Imbalance at root)

                root                        (left-heavy root)
                 /
            child
             /
            T2

           Right Rotation at root

                child                        (new root)
               /    \
           root      T2            (root becomes right child)

*/
node *child = root->left;
node *T2 = child->right;

child->right= root;
root->left = T2;

root->height= max(root) + 1 ;
child->height = max(child) + 1 ;
    return child;
}

node* creatnode(int key){
    node * newnode = malloc(sizeof(node));
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1 ;
        return newnode;
}

node * insert(node *nod , int key){
if(nod == NULL)
    return( creatnode(key));

 if(key > nod->key){
    nod->right = insert(nod->right,key);

 }else if( key < nod->key){
 nod->left = insert(nod->left,key);
 }else{
        return nod;
 }

nod->height = 1 + max(nod) ;

int balance = Blance(nod);

 if(balance > 1 && key < nod->left->height){
                                             /*
       x
     /
    y
   /
  z*/
  return rightrotation(nod);

}
if(balance > 1 && key > nod->left->height){
                                            /*
      x
     /
    y
     \
      z   */
     nod->left = leftrotation(nod->left);
     return rightrotation(nod);
}
if(balance < -1  && key > nod->right->height){
                                              /*
    x
     \
      y
       \
        z   */
      return leftrotation(nod);
}
if(balance <-1 && key < nod->right->height){
                                              /*
    x
     \
      y
     /
    z */
    nod->right = rightrotation(nod->right);
    return leftrotation(nod);
}
return nod;
}

void perorder(node *nod){
    if(nod != NULL){
        printf("%d\n",nod->key);
        perorder(nod->left);
        perorder(nod->right);
    }
}
int main(){

node* start= NULL;
start = insert(start,1);
start = insert(start,2);
start = insert(start,3);
start = insert(start,4);
start = insert(start,5);

perorder(start);

    return 0;
}
