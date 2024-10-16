// Double Ended Queue:

#include<stdio.h>
#define MAX 10
 
int deque_arr[MAX];
int front=-1;
int rear=-1;

void insertFront(int item);
void insertRear(int item);
int deleteFront();
int deleteRear();
void display();
int isEmpty();
int isFull();

int main(){
      int choice,item;
      while(1)
      {
          printf("\n\n1.Insert at the front end\n");
          printf("2.Insert at the rear end\n");
          printf("3.Delete from front end\n");
          printf("4.Delete from rear end\n");
          printf("5.Display\n");
          printf("6.Quit\n");
          printf("\nEnter your choice : ");
          scanf("%d",&choice);
          
          switch(choice){
          case 1:
                  printf("\nInput the element for adding in queue : ");
                  scanf("%d",&item);
                  insertFront(item);
                  break;
          case 2:
                  printf("\nInput the element for adding in queue : ");
                  scanf("%d",&item);
                  insertRear(item);
                  break;
           case 3:item=deleteFront();
                  if(item!=-1)
                      printf("\nElement deleted from front end is : %d\n",item);
                  break;
           case 4:
                  item=deleteRear();
                  if(item!=-1)
                      printf("\nElement deleted from rear end is : %d\n",item);
                  break;
           case 5:
                  display();
                  break;
           case 6:
                  exit(1);
           default:
                  printf("\nWrong choice\n");
          }
          printf("\nfront = %d, rear =%d\n", front , rear);
          display();
      }
}
 
void insertFront(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front==-1 )/*If queue is initially empty*/
        {
                front=0;
                rear=0;
        }
        else if(front==0)
                front=MAX-1;
        else
                front=front-1;
        deque_arr[front]=item ;
}
 
void insertRear(int item)
{
        if(isFull()){
                printf("\nQueue Overflow\n");
                return;
        }
        if(front==-1)  /*if queue is initially empty*/
        {
                front=0;
                rear=0;
        }
        else if(rear==MAX-1)  /*rear is at last position of queue */
                rear=0;
        else
                rear=rear+1;
        deque_arr[rear]=item ;
}/*End of insert_rearEnd()*/
 
int deleteFront()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                return -1;
        }
        item=deque_arr[front];
        if(front==rear) /*Queue has only one element */
        {
                front=-1;
                rear=-1;
        }
        else
                if(front==MAX-1)
                        front=0;
                else
                        front=front+1;
        return item;
}/*End of deleteFront()*/
 
int deleteRear()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                return -1;
        }
        item=deque_arr[rear];
 
        if(front==rear) /*queue has only one element*/
        {
                front=-1;
                rear=-1;
        }
        else if(rear==0)
                rear=MAX-1;
        else
                rear=rear-1;
        return item;
}/*End of delete_rearEnd() */
 
int isFull(){
        if ( (front==0 && rear==MAX-1) || (front==rear+1) )
                return 1;
        else
                return 0;
}
 
int isEmpty(){
        if(front == -1)
                return 1;
        else
                return 0;
}
 
void display()
{
      int i;
      if(isEmpty()){
          printf("\nQueue is empty\n");
          return;
      }
      printf("\nQueue elements :\n");
      i=front;
      if( front<=rear )
      {
          while(i<=rear)
                  printf("%d ",deque_arr[i++]);
      }
      else
      {
          while(i<=MAX-1)
                  printf("%d ",deque_arr[i++]);
          i=0;
          while(i<=rear)
                  printf("%d ",deque_arr[i++]);
      }
      printf("\n");
}

