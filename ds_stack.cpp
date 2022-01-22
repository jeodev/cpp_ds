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
        return;
    }
    top ++;
    holder[top] = value;
} 

int Stack::pop(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return 0;
    }
    int popValue = holder[top];
    holder[top] = 0;
    top --; 
    return popValue;
} 

int Stack::count(){
    return (top + 1);
}

int Stack::peek(int index){
    if(!isEmpty() && index > -1 && index < (count() + 1)){
        return holder[index];
    }
    cout << "index not found" << endl;
    return 0;
}

void Stack::change(int index, int value){
    if (index > -1 && index < (count() + 1)){
        holder[index] = value;      
        return;
    }
    cout << "index out of boundary" << endl;    
}

void Stack::display(){
    if(isEmpty()){
        cout << "Stack is empty, add something to the stack" << endl;
        return;
    }
    cout << endl << "Display the stack" << endl;
    for(int index = (count() - 1); index >=0 ; index --){
        cout << "--> " << holder[index] << endl;
    }
    cout << endl;
}

int main(){

    Stack stack;
    int option, position, value;
    do{
        cout << "0. Exit" << endl
             << "1. Add" << endl
             << "2. Remove" << endl
             << "3. isEmpty" << endl
             << "4. isFull" << endl
             << "5. peek" << endl
             << "6. size" << endl
             << "7. replace" << endl
             << "8. display all" << endl
             << "9. clear screen" << endl;
        cout << "Select: ";
        cin >> option;

        cout << endl;
        switch(option){
            case 1:
                cout << "Enter the value you want to store: ";
                cin >> value;

                if(stack.isFull()){
                    cout << "Stack is full" << endl;
                    break;
                }
                    stack.push(value);
                break;
            case 2:
                if(stack.isEmpty()){
                    cout << "Stack is empty" << endl;
                    break;
                }
                cout << "Removed value: " << stack.pop() << endl;
                break;
            case 3:
                if(stack.isEmpty()){
                    cout << "The stack is empty" << endl;
                }else{
                    cout << "The stack is't empty" << endl;
                }
                break;
            case 4:
                if(stack.isFull()){
                    cout << "The stack is full" << endl;  
                }else{
                    cout << "The stack is't full" << endl;
                }
                break;
            case 5:
                cout << "Enter the position number: ";
                cin >> position;
                cout << "The value is " << stack.peek(position - 1) << endl;
                break;
            case 6:
                cout << "Total occupied space: " << stack.count() << endl;
                break;
            case 7:
                cout << "Enter the position number: ";
                cin >> position;
                cout << "Enter the value: ";
                cin >> value;

                stack.change((position - 1), value);
                break;
            case 8:
                stack.display();
                break;
            case 9:
                system("clear");
                break;
            default:
                cout << "Error Selecion" << endl;
                break;
        }

    }while(option != 0);

    return 0;
}