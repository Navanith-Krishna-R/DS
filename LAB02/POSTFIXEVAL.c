#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20
void push(float a);
int pop();
int stack[max],top =-1;
float compute(int a,int b,char c);

void main(){
    char postfix[max];
    int a,b;
    char c,d;
    printf("Enter numerical postfix expression: ");
    scanf("%s",postfix);
    int j=0;
    for(int i=0;i<strlen(postfix);i++){
        d=postfix[i];
        if(isdigit(d)){
            push(d-'0');
        }
       else if((postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='/' || postfix[i]=='*')){
                a=pop();
                b=pop();
                c=compute(a,b,postfix[i]);
                push(c);
                }
        }
    printf("%d",pop());
}
void push(float a){
    if(top>max-1){
        printf("Stack overflow");
    }
    else{
        ++top;
        stack[top]=a;
    }
}

int pop(){
    if(top==-1){
        printf("Stack underflow:");
    }
    else{
        return stack[top--];

    }
}
float compute(int m,int n,char o)
{
float res;
switch(o)
{
case '+':res=m+n; break;
case '-':res=m-n;break;
case'*':res=m*n;break;
case'/':res=m/n;break;
}
return res;
}
