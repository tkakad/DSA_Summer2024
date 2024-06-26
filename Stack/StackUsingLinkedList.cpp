#include <iostream>

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

// Main Function

int main(){
    push(10);
    push(20);
    push(30);

    Display();

    cout << "pop(): " << pop() << endl;
    
    Display();
    
    cout << "pop(): " << pop() << endl;
    
    Display();

    return 0;
}