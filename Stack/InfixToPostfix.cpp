#include <iostream>
#include <cstring>

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

char* convert(char *infix){
    int len = strlen(infix);
    char *postfix = new char[len + 2];

    int i = 0, j = 0;

    while (infix[i] != '\0'){
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }

    while (top)
        postfix[j++] = pop();

    postfix[j] = '\0';

    return postfix;
}

// Main Function        

int main(){
    char *infix = "a+b*c";
    push('#'); // Just to intialize the Stack with a random character (Neither an operator, nor operand)

    char *postfix = convert(infix);

    cout << postfix << endl;

    return 0;
}