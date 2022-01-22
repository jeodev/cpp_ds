
#include <iostream>
using namespace std;

const int SIZE = 5;
class Queue{
    private:
        int holder[SIZE];
        int front = -1;
        int rear = -1;
    public:
        void Enqueue(int);
        int Dequeue();

        bool isEmpty();
        bool isFull();
        int size();
};