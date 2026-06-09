#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data1, Node *next1, Node *prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};

int main(){
    Node *firstNode = new Node(2);
    Node *secondNode = new Node(5);
    Node *thirdNode = new Node(10);

    firstNode->prev = nullptr;
    firstNode->next = secondNode;

    secondNode->prev = firstNode;
    secondNode->next = thirdNode;

    thirdNode->prev = secondNode;
    thirdNode->next = nullptr;

    // print doubly LL
    Node *temp = firstNode;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}