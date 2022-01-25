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

        void pushNode(Node*);
        void shiftNode(Node*);

        void popNode();
        void unshiftNode();

        void insertNodeByIndex(int, Node*);
        void deleteNodeByIndex(int);
        void updateNodeByIndex(int, int);
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

void SingleLinkedList::pushNode(Node* nod_e){
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


void SingleLinkedList::popNode(){
    if(head == NULL){
        cout << endl << "The list is empty" << endl << endl;
    }else{
        Node* prevNode = head;
        Node* currentNode = head->next;
        while(currentNode != NULL){
            if(currentNode->next == NULL){
                prevNode->next = NULL;
                currentNode = NULL;
            }else{
                prevNode = prevNode->next;
                currentNode = currentNode->next;
            }
        }
    }
}

void SingleLinkedList::shiftNode(Node* nod_e){
    if(head == NULL){
        head = nod_e;
        cout << endl << "Node shifted to the head" << endl << endl;
    }else{
        if(nodeExisted(nod_e->key) != NULL){
            cout << endl << "Node key already existed!!" << endl << endl;
        }else{
            nod_e->next = head;
            head = nod_e;
            cout << endl << "Node shifted to the head" << endl << endl;
        }
    }
}

void SingleLinkedList::unshiftNode(){
    if(head == NULL){
        cout << endl << "The list is empty" << endl << endl;
    }else{
        head = head->next;
        cout << endl << "Node unshifted from the head" << endl << endl;
    }
}

void SingleLinkedList::insertNodeByIndex(int ke_y, Node* nod_e){
    Node* ptr = nodeExisted(ke_y);
    if(ptr == NULL){
        cout << endl << "Node key dosen't existed!!" << endl << endl;
    }else{

        if(nodeExisted(nod_e->key) != NULL){
            cout << "Node key already existed!!" << endl;
        }else{
            nod_e->next = ptr->next;
            ptr->next = nod_e;
            cout << endl << "Node inserted on key: " << nod_e->key << endl << endl;
        }

    }
}


void SingleLinkedList::updateNodeByIndex(int ke_y, int dat_a){
    if (head == NULL){
        cout << endl << "The list is empty" << endl << endl;
    }else{
        Node* ptr = nodeExisted(ke_y);
        if(ptr){
            ptr->data = dat_a;
        }else{
            cout << endl << "Node key dosen't existed!!" << endl << endl;
        }
    }
}


void SingleLinkedList::deleteNodeByIndex(int ke_y){
    if(head == NULL){
        cout << endl << "The list is empty" << endl << endl;
    }else{
        if(head->key == ke_y){
            head = head->next;
            cout << endl << "Unlinking the head" << endl << endl;
        }else{
            Node* temp = NULL;
            Node* prevNode = head;
            Node* currentNode = head->next;

            while(currentNode != NULL){
                if(currentNode->key == ke_y){
                    temp = currentNode;
                    currentNode = NULL;
                }else{
                    prevNode = prevNode->next;
                    currentNode = currentNode->next;
                }
            }

            if(temp != NULL){
                prevNode->next = temp->next;
                cout << endl << "Unlinking the data from key: " << ke_y << endl << endl;
            }else{
                cout << endl << "Node key dosen't existed!!" << endl << endl;
            }

        }

    }
    
}


void SingleLinkedList::display(){
    if(head == NULL){
        cout << endl << "The list is empty" << endl << endl;
    }else{
        Node* ptr = head;
        cout << endl;
        while(ptr != NULL){
            cout << "(" << ptr->key << ", " << ptr->data << ")";
            if(ptr->next != NULL){
                cout << "-->";
            }else{
                cout << endl;
            }

            ptr = ptr->next;
        }

        cout << endl;
    }
}

int main(){

    SingleLinkedList s;
    int ke_y, dat_a, position, option;
    ke_y = dat_a = position = 0;

    do{
        cout << "0. Exit" << endl
             << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Shift" << endl
             << "4. Unshift" << endl
             << "5. InsertByIndex" << endl
             << "6. UpdateByIndex" << endl
             << "8. DeleteByIndex" << endl
             << "9. Display" << endl;

        cout << "Select: ";
        cin >> option;

        Node* node = new Node();
        switch(option){
            case 1:
                cout << "Enter the key : ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                node->key = ke_y;
                node->data = dat_a;
                s.pushNode(node);
                break;

            case 2:
                s.popNode();
                break;

            case 3:
                cout << "Enter the key: ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                node->key = ke_y;
                node->data = dat_a;
                s.shiftNode(node);
                break;

            case 4:
                s.unshiftNode();
                break;

            case 5:
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the key: ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                node->data = dat_a;
                node->key = ke_y;
                s.insertNodeByIndex(position, node);

                break;

            case 6:
                cout << "Enter the key: ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                s.updateNodeByIndex(ke_y, dat_a);
                break;

            case 7:
                cout << "Enter the key: ";
                cin >> ke_y;

                s.deleteNodeByIndex(ke_y);
                break;
            case 8:
                s.display();
                break;
            
            default:
                break;
        }

    }while(option != 0);

    return 0;
}