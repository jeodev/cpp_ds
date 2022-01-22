
#include <iostream>
using namespace std;

const int SIZE = 5;
class Queue{
    private:
        int holder[SIZE];
        int front, rear;
    public:
        Queue();
        ~Queue();
        void Enqueue(int);
        int Dequeue();

        bool isEmpty();
        bool isFull();
        int size();

        void display();
};

Queue::Queue(){
    front = rear = -1;
    for(int index = 0; index < SIZE; index ++){
        holder[index] = 0;
    }
}

Queue::~Queue(){
    cout << "Thanks for using queue" << endl;
}

bool Queue::isEmpty(){
    if(rear == -1 && front == -1){
        return true;
    }
    return false;
}

int Queue::size(){
    return (rear - front);
}
bool Queue::isFull(){
    if(rear == (SIZE - 1)){
        return true;
    }
    return false;
}

void Queue::Enqueue(int value){
    if(isFull()){
        return;
    }else if(isEmpty()){
        front = rear = 0;
    }else{
        rear ++;
    }
    cout << endl << "REAR " << rear << endl;
    cout << "FRONT: " << front << endl << endl;
    holder[rear] = value;
}

int Queue::Dequeue(){
    int dval = 0;
    if(isEmpty()){
        return 0;
    }else if(rear == front){
        dval = holder[front];
        rear = front = -1;
    }else{
        dval = holder[front];
        front ++;
    }

    return dval;
}

void Queue::display(){
    cout << endl;
    if(isEmpty()){
        cout << "Queue is empty, add something" << endl;
        return;
    }

    for(int index = rear; index >= front; index --){
        cout << "--> " << "[" << index + 1 << "]: " << holder[index] << endl; 
    }
    cout << endl;
}

int main(){
    Queue queue;
    char confirm;
    int option, value;
    do{
        cout << "1. Enqueue " << endl
             << "2. Dequeue " << endl
             << "3. Size " << endl
             << "4. isFull " << endl
             << "5. isEmpty" << endl
             << "6. display" << endl;
        cout << "Select: ";
        cin >> option;

        switch(option){
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                queue.Enqueue(value);
                break;
            case 2:
                cout << "Dequeue: " << queue.Dequeue() << endl;
                break;
            case 3:
                cout << "Size: " << (queue.size()) << endl;
                break;
            case 4:
                if(queue.isFull()){
                    cout << "The queue is full" << endl;
                }else{
                    cout << "The queue is't full" << endl;
                }
                break;
            case 5:
                if(queue.isEmpty()){
                    cout << "The queue is empty" << endl;
                }else{
                    cout << "The queue is't empty" << endl;
                }
                break;
            case 6:
                queue.display();
                break;  
            defaul:
                cout << "Error Input" << endl;
                break;
        }


        cout << "Do you want to continue(y|n): ";
        cin >> confirm;
        cout << endl;
    }while(confirm == 'y');


    return 0;
}