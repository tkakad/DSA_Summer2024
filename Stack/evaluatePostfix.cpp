#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaring Node structure

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

// Declaring Stack ADT functions

void push(int x){
    struct Node *t = new Node;

    if (t == NULL)
        cout << "Stack Overflow!" << endl;

    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    int x = -1;
    struct Node *t;

    if (top == NULL)
        cout << "Stack Underflow!" << endl;
    else{
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }

    return x;
}

void Display(){
    struct Node *p = top;
    
    cout << "Stack: ";

    while(p){
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Functions to check character precedence

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int precedence(char x){
    if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    return 0;
}

// Function to convert Infix to Postfix

int evaluate(char *postfix){
    int x1, x2, r;

    for(int i = 0; postfix[i] != '\0'; i++){
        
    }
}

// Main Function        

int main(){
    char *postfix = "234*+82/-";

    return 0;
}