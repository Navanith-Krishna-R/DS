#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}
// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}
// Function to get the precedence of an operator
int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // Default precedence for operands
    }
}
// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[]) {
    char postfix[MAX_SIZE];
    int i, j;
    i = j = 0;
    while (infix[i] != '\0') {
        char symbol = infix[i];

        if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid Expression: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            pop(); // Pop '(' from the stack
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }

        i++;
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid Expression: Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix);

    return 0;
