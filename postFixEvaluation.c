#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXSIZE 20

int stack[MAXSIZE];
int top = -1;

void push(int n){
      if(top == (MAXSIZE - 1))
            printf("\nOverflow Error");
      else {
            top = top + 1;
            stack[top] = n;
      }
}

int pop(){
      if(top == -1)
            printf("\nUnderflow Error");
      else return stack[top--];
}

int evaluate(char input[]){
      int eval = 0;
      for(int i=0; input[i] != '\0'; i++){
            char ch = input[i];
            if(isdigit(ch)){
                  push(ch-'0');
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
                  int a = pop();
                  int b = pop();
                  switch(ch){
                        case '+':
                              push(b + a);
                              break;
                        case '-':
                              push(b - a);
                              break;
                        case '*':
                              push(b*a);
                              break;
                        case '/':
                              push(b/a);
                              break;
                        case '^':
                              push(pow(b,a));
                              break;
                  }
            }
      }
      return eval += stack[top];
}

int main(){
      char input[20];
      printf("Enter the Postfix Expression: ");
      scanf("%s", input);
      int ans = evaluate(input);
      printf("\nAnswer of the expression is: %d", ans);
      return 0;
}
