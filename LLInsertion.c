#include <stdio.h>
#include <stdlib.h>

struct Node{
      int data;
      struct Node *next;
};

struct Node *head = NULL;

struct Node *enqueueFront(struct Node *head, int newData){
      struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode -> data = newData;
      newNode -> next = head;
      head = newNode;
      return head;
}

void displayLinkedList(){
      if(head == NULL){
            printf("List Empty!");
      }
      else{
            struct Node *current = head;
            printf("\nCurrent List is: ");
            while(current != NULL){
                  printf(" %d ->", current->data);
                  current = current->next;
            }
            printf(" NULL");
      }
}

int main(){
      while(1){
            printf("\n1)Insert\n2)Display Linked List\n3)Exit\nChoose the operation:");
            int opr;
            scanf("%d", &opr);
            switch(opr){
                  case 1:
                        printf("Enter element to insert: ");
                        int elm;
                        scanf("%d",&elm);
                        head = enqueueFront(head,elm);
                        break;
                  case 2:
                        displayLinkedList();
                        break;
                  case 3:
                        exit(1);
                        break;
                  default:
                        printf("\nChoose a valid option!");
            }
      }
}
