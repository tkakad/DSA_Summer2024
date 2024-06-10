#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaring Node structure

struct Node{
    char data;
    struct Node *next;
}*top = NULL;

// Declaring Stack ADT functions

void push(char x){
    struct Node *t = new Node;

    if (t == NULL)
        cout << "Stack Overflow!" << endl;

    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    char x = -1;
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

// Function to check if the parenthesis set are valid or not

bool isBalanced(char *exp){
    for (int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(')
            push(exp[i]);

        else if (exp[i] == ')'){
            if (top == NULL)
                return 0;
            pop();
        }
    }

    if (top == NULL)
        return true;

    return false;
}

// Main Function

int main(){
    char *exp = "((a+b)*(c-d))";

    cout << isBalanced(exp) << endl;

    return 0;
}