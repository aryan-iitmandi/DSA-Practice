#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data1, Node *next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node *nthNodeFromLast(Node *head, int n){
    if(head == nullptr || n<=0) return nullptr;
    Node *first = head;
    Node *second = head;

    for(int i=0; i<n; i++){
        if(first == nullptr)  return nullptr;
        first = first->next;
    }
    while(first != nullptr){
        first = first->next;
        second = second->next;
    }
    return second;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(12);
    head->next->next = new Node(30);
    head->next->next->next = new Node(92);
    head->next->next->next->next = new Node(11);
    head->next->next->next->next->next = new Node(19);

    Node *result = nthNodeFromLast(head, 3);
    if(result)  cout << result->data;

    // Node *temp = head;
    // while(temp!=nullptr){
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    return 0;
}