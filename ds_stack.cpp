#include <iostream>
using namespace std;

const int SIZE = 5;
class Stack{
    private:
        int holder[SIZE];
        int top;
    public:
        Stack();
        void push(int);
        void change(int, int);
        int peek(int);

        int pop();
        bool isEmpty();
        bool isFull();
        int count();
        void display();
};


Stack::Stack(){
    top = -1;
    for(int index = 0; index < SIZE; index ++){
        holder[index] = 0;
    }
}

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool Stack::isFull(){
    if(top == (SIZE - 1)){
        return true;
    }
    return false;
}

void Stack::push(int value){
    if(isFull()){
        cout << "Stack is full" << endl;
        return ;   
    }
    top ++;
    holder[top] = value;
} 

int Stack::pop(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    int popValue = holder[top];
    holder[top] = 0;
    top --; 
    return popValue;
} 

int Stack::count(){
    return top;
}

int Stack::peek(int index){
    if(isEmpty() && index > -1 && index < count()){
        return holder[index];
    }
    cout << "index not found" << endl;
    return ;
}

void Stack::change(int index, int value){
    if (index > -1 && index < count()){
        holder[index] = value;
        return;   
    }
    cout << "index out of boundary" << endl;
}

void Stack::display(){
    for(int index = (SIZE - 1); index >=0 ; index --){
        cout << holder[index] << endl;
    }
}