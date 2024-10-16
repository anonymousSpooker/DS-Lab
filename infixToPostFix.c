#include <stdio.h>
#define MAX 20

int stack[MAX];
char pF[MAX];
int top = -1;

void push(char n){
      if(top == MAX-1)
            printf("OverFlow Error");
      else{
            top++;
            stack[top] = n;
      }
}
char pop(){}
void convert(char input[]){}

int main(){
      printf("Enter the Infix Expression: ");
      char input[20];
      scanf("%s", input);
      convert(input);
}
