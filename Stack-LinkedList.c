#include <stdio.h>
#include <stdlib.h>

struct Node {
   char T[30];
    struct Node* next;
};

struct Node* createNode( char T[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
strcpy(newNode->T ,T);
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, char T[]) {
    struct Node* newNode = createNode(T);
    newNode->next = *top;
    *top = newNode;
    printf("%s pushed to stack\n", T);
}

// Function to pop an element from the stack
char pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty, cannot pop\n");
        return -1; // Indicates empty stack
    }
char poppedData[30];
    *top = (*top)->next;
   strcpy(poppedData , (*top)->T);
   // free(temp);
    printf("%s popped from stack\n", poppedData);
    return poppedData;
}

// Function to get the top element of the stack
char peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1; // Indicates empty stack
    }

    return *top->T;
}

// Function to display the stack elements
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%s ", temp->T);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;

    push(&top, "ajouter");
    push(&top, "supprimer");
    push(&top, "modifier");

    display(top);
do{
        int d;
    printf("resturer:1 / annuler: 0\n");
    scanf(" %d", &d );
switch (d){

  case 0:
    //  pop(&top);
     printf(" element is %s\n", pop(&top));

    break;
  case 1:
     // peek(&top);
      printf("element is %s\n", peek(&top));

    break;
}

}while(1);

   

    return 0;
}
