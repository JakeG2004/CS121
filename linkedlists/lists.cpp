/* lists.cpp
 *
 * CS 121.Bolden.........GCC 11.4.0...........Jake Gendreau
 * Feb 16, 2024 .................My Laptop / Core i9-13900H.............gend0188@vandals.uidaho.edu
 *
 * Taking in two data sets, output the intersection and the union between the two.
 *---------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

typedef struct node* NodePtr;

void printList(NodePtr);
void addToFront(NodePtr&, int x);
void addToEnd(NodePtr&, int x);
void removeFromFront(NodePtr&);
void addSorted(NodePtr&, int);

int main(){
    NodePtr head;
    //init array
    addToFront(head, 2);
    addToFront(head, 3);


    cout << "Initial list" << endl;

    printList(head);
    addSorted(head, 1);

    cout << "Sorted list" << endl;

    printList(head);
}

void removeFromFront(NodePtr &head){
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

void printList(NodePtr head){
    NodePtr p = head;

    while(p -> next != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
}

void addToFront(NodePtr &head, int x){
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

void addToEnd(NodePtr &head, int x){
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

/*void addSorted(NodePtr &head, int x){
    cout << "addSorted" << endl;
    NodePtr n = new node;

    n -> data = x;
    n -> next = NULL;

    if(head == NULL){
        head = n;
    }

    else{
        NodePtr p = head;

        while(p != NULL && x < p -> data){
            cout << "p -> data: " << p -> data << endl;
            p = p -> next;
        }

        n -> next = p -> next;
        p -> next = n;
    }
}*/

void addSorted(NodePtr &head, int x){
    cout << "addSorted" << endl;
    NodePtr n = new node;

    n -> data = x;
    n -> next = NULL;

    if(head == NULL){
        head = n;
    }

    else{
        NodePtr curr = NULL;
        NodePtr prev = head;

        while(curr != NULL && x < curr -> data){
            cout << "curr -> data: " << curr -> data << endl;
            prev = curr;
            curr = curr -> next;
        }

        if(prev == NULL){
            n -> next = curr;
            head = n;
        } else {
            prev -> next = n;
            n -> next = curr;
        }
    }
}