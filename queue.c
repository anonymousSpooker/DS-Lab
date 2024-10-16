#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(){
      if(front = -1 && rear == -1)
            return 1;
      else return 0;
}

int isFull(){
      if(rear == MAX-1)
            return 1;
      else return 0;
}

void enqueue(int n){
      if(isFull())
            printf("\nOverflow Error");
      else if(front == rear == -1){
            front = 0;
            rear = 0;
            queue[rear] = n;
            printf("\nElement inserted successfully");
      }
      else{
            rear++;
            queue[rear] = n;
            printf("\nElement inserted succcessfully");
      }
}

int dequeue(){
      if(isEmpty())
            printf("\nUnderFlow Error");
      else return queue[front++];
}

void display(){
      if(isEmpty())
            printf("UnderFlow Error");
      else{
            printf("\nCurrent Queue is: ");
            for(int i=front; i<=rear; i++){
                  printf("%d ", queue[i]);
            }      
      }
}

void peek(){
      if(isEmpty())
            printf("\nUnderFlow Error");
      else
            printf("\nElement Peeked is: %d", queue[front]);
}

int size(){
      return (rear-front+1);
}

int main(){
      while(1){
            printf("\n\n1)Insert an Element\n2)Delete an Element\n3)Peek an Element\n4)Display Queue\n5)Display Queue Size\n6)Exit Program\n");
            printf("\nEnter the operation to perform: ");
            int n;
            scanf("%d", &n);
            switch(n){
                  case 1:
                        printf("\nEnter the element to Insert:");
                        int e;
                        scanf("%d", &e);
                        enqueue(e);
                        break;
                  case 2:
                        if(isEmpty)
                              dequeue();
                        else printf("\nElement removed successfully. Removed element is: %d", dequeue());
                        break;
                  case 3:
                        peek();
                        break;
                  case 4:
                        display();
                        break;
                  case 5:
                        printf("\nSize of Queue is: %d", size());
                  case 6:
                        exit(1);
                  default:
                        printf("Enter valid option");
            }
      }
      return 0;
}
