// Circular Queue:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int cqueue[MAX];
int rear = - 1;
int front = -1;

bool isEmpty() {
    return front==-1 ;
}

bool isFull() {
    return (rear+1)%MAX == front;
}

void enqueue(){
int item;
if (isFull())
  printf("Queue Overflow \n");
else
 {
 printf("\nInset the element in queue : ");
 scanf("%d", &item);
    if(isEmpty())
       front=rear=0;
    else
      rear = (rear + 1)%MAX;
 cqueue[rear] = item;
 }
} 
void dequeue(){ 
      if(isEmpty()){
      printf("\nQueue Underflow \n");
      return;
      }
      printf("\nElement deleted from queue is : %d\n", cqueue[front]);
      if (rear == front){
      front=rear=-1;
      }
      else{
      front = (front + 1) %MAX;
      }
}

void display()
{
int i;
    if (isEmpty() )
        printf("\nQueue is empty \n");
     else
    {  printf("\nQueue is : ");
        if(front==rear)
            printf("%d\n", cqueue[front]);
        else
        {
        for (i = front; i != rear; i=(i+1)%MAX)
            printf("%d ", cqueue[i]);
        
        printf("%d ", cqueue[i]);
        printf("\n");
        }
    }
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    } else {
        return cqueue[front];
    }
}

int size() {
    if (isEmpty()) {
        return 0;
    } else {
        if (rear >= front ) return rear - front + 1;
        else return MAX-front+rear-0+1;
    }
}

int main(){
      int n;
      while (1){
            printf("\n1.Insert element to queue \n");
            printf("2.Delete element from queue \n");
            printf("3.Display all elements of queue \n");
            printf("4.Peek \n");
            printf("5.Size of the queue\n");
            printf("6.Quit \n");
            printf("\nEnter your choice : ");
            scanf("%d", &n);
                  switch (n){
                  case 1:
                      enqueue();
                      break;
                  case 2:
                      dequeue();
                      break;
                  case 3:
                      display();
                      break;
                  case 4:
                      if(peek()!=-1) 
                        printf("\nfront element is=%d\n",peek());
                      break;
                  case 5:
                      printf("\nsize of the queue is =%d\n",size());
                      break;
                  case 6:
                      exit(1);
                  default:
                  printf("\n Enter a valid option.");
                  }

      }
      return 0;
} 

