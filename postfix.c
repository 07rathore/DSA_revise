// program to convert infix to postfix
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(int data){
    stack[++top]=data;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    if(op=='^') return 3;
    else if(op=='*'|| op=='/') return 2;
    else if(op=='+'|| op=='-') return 1;
    else return 0;
}

int infixToPostfix(char infix[]){
    char postfix[MAX];
    int i,j=0;
    char c;

    for(i=0;i<strlen(infix); i++){
        c=infix[i];

        // if alphanumeric push directly to postfix
        if(isalnum(c)){
            postfix[j++]=c;
        }
        else if(c == '('){
            push(c);
        }
        else if(c==')'){
            while(c != '('){
                postfix[j++]=pop();
            }
            pop(); //to ignore '('
        }

        else{
            while(top!=-1 && precedence(peek())>= precedence(c)){
                postfix[j++]=pop();
            }
            push(c);
        }
    }

    // for remaining item
    while(top!=-1){
        postfix[j++]=pop();
    }

    postfix[j]='\0';
    printf("Postfix Expression: %s",postfix);
}

int main(){
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s",infix);

    infixToPostfix(infix);
}