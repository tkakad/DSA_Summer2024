#include <iostream>

using namespace std;

// Stack structure declaration

struct Stack{
    int size, top, *s;
};

// Stack ADT Operations

void push(Stack *st, int x){
    if (st->top == st->size - 1)
        cout << "Stack Overflow!" << endl;

    else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st){
    int x = -1;

    if (st->top == -1)
        cout << "Stack Underflow!" << endl;

    else{
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

int peek(Stack *st, int pos){
    int x = -1;
    
    if (st->top - pos + 1)
        cout << "Invalid Position!" << endl;

    else
        x = st->s[st->top - pos + 1];

    return x;
}

int stackTop(Stack st){
    if (st.top == -1)
        return -1;
    
    else
        return st.s[st.top];
}

int isEmpty(Stack st){
    if (st.top == -1)
        return 1;
    
    else
        return 0;
}

int isFull(Stack st){
    if(st.top == st.size - 1)
        return 1;
    
    else
        return 0;
}

void Display(Stack st){
    for (int i = st.top; i >= 0; i--)
        cout << st.s[i] << " ";
    
    cout << endl;
}

// Main funciton

int main(){
    struct Stack st;
    int size;

    cout << "Enter the stack size: ";
    cin >> st.size;

    st.s = new int[st.size];
    st.top = -1;

    // Performing the above declared operations on Stack

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    Display(st);

    return 0;
} 