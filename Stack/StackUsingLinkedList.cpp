#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

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
        free(t);
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