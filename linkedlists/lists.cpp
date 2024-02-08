/*
list.cpp
Jake Gendreau
Feb 2, 2024
*/

#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

typedef struct node* NodePtr;

NodePtr head;

void printList();
void addToFront(int x);
void addToEnd(int x);
void removeFromFront();

int main(){
    //init array
    int A[] = {1, 2, 3};
    int nA = sizeof(A) / sizeof(int);

    cout << "nA: " << nA << endl;

    cout << "Initial list: " << endl;

    //add all values from A to linked lists
    for(int i = 0; i < nA; i++){
        addToFront(A[i]);
    }

    while(head){
        printList();
        removeFromFront();
        cout << endl;
    }

    printList();
}

void removeFromFront(){
    NodePtr p = head;

    if(p == NULL){
        cout << "List is empty!" << endl;
        exit(1);
    }

    else{
        head = p -> next; //move head to next item

        p -> next = NULL; //break link

        delete p; //delete the old head
    }
    

}

void printList(){
    NodePtr p = head;

    while(p != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
}

void addToFront(int x){
    NodePtr n = new node;

    n -> data = x;
    n -> next = NULL;

    if(head == NULL){
        head = n;
    } else {
        n -> next = head;
        head = n;
    }
}

void addToEnd(int x){
    NodePtr n = new node;

    n -> data = x;
    n -> next = NULL;

    if(head == NULL){
        head = n;
    } else {
        NodePtr p = head;
        while (p -> next != NULL){
            p = p-> next;
        }

        p -> next = n;
    }
}