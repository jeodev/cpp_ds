#include <iostream>
using namespace std;

class Node{
    public:
        int data, key;
        Node* next;
        Node();
        Node(int, int);
};

Node::Node(){
    key = 0;
    data = 0;
    next = NULL;
}

Node::Node(int ke_y, int dat_a){
    key = ke_y;
    data = dat_a;
}

class SingleLinkedList{
    public:
        Node* head;

        SingleLinkedList();
        SingleLinkedList(Node*);
        Node* nodeExisted(int);

        void appendNode(Node*);
        void display();
};

SingleLinkedList::SingleLinkedList(){
    head = NULL;
}

SingleLinkedList::SingleLinkedList(Node* nod_e){
    head = nod_e;
}

Node* SingleLinkedList::nodeExisted(int ke_y){
    Node* temp = NULL;
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->key == ke_y){
            temp = ptr;
            break;
        }
        ptr = ptr->next;
    }

    return temp;
}

void SingleLinkedList::appendNode(Node* nod_e){
    if(nodeExisted(nod_e->key) != NULL){
        cout << endl << "Node already existed with the key: " << nod_e->key << endl << endl;
    }else{
        if(head == NULL){
            head = nod_e;
            cout << endl << "Node added to the head" << endl << endl;
        }else{
            Node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }

            ptr->next = nod_e;
            cout << endl << "Node added to the end" << endl << endl;
        }
    }
}

void SingleLinkedList::display(){
    if(head == NULL){
        cout << endl << "The list is empty" << endl << endl;
    }else{
        Node* ptr = head;
        while(ptr != NULL){
            cout << "(" << ptr->key << ", " << ptr->data << ")";
            if(ptr->next != NULL){
                cout << "-->";
            }else{
                cout << endl;
            }

            ptr = ptr->next;
        }
    }
}

int main(){

    Node* node = new Node();
    SingleLinkedList s;
    int ke_y, dat_a, option;
    ke_y = dat_a = 0;

    do{
        cout << "0. Exit" << endl
             << "1. Append" << endl
             << "2. Display" << endl;

        cout << "Select: ";
        cin >> option;

        switch(option){
            case 1:
                cout << "Enter the key : ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                node->key = ke_y;
                node->data = dat_a;
                s.appendNode(node);
                break;
            
            case 2:
                s.display();
                break;
            
            default:
                break;
        }

    }while(option != 0);

    return 0;
}