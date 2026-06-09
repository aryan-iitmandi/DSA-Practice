#include<bits/stdc++.h>
using namespace std;

// LL using class with constructor
class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

// LL using struct
// struct Node{
//     int data;
//     Node *next;
// };

int main(){
    // creating nodes of constructor based LL
    // creation and initialization happen at same time
    Node *firstNode = new Node(5);
    Node *secondNode = new Node(10);
    Node *thirdNode = new Node(12);

    firstNode -> next = secondNode;
    secondNode -> next = thirdNode;


    // creating nodes of struct based LL (without constructor)
    // need to create nodes then initialize it
    // Node *firstNode = new Node();
    // Node *secondNode = new Node();
    // Node *thirdNode = new Node();

    // firstNode -> data = 2;
    // secondNode -> data = 3;
    // thirdNode -> data = 5;

    // firstNode -> next = secondNode;
    // secondNode -> next = thirdNode;
    // thirdNode -> next = nullptr;

    // print LL
    Node *temp = firstNode;
    while(temp !=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}