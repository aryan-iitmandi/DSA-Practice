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

Node *reverseLL(Node *head){
    
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

bool isPlaindrome(Node *head){
    if(head == nullptr || head->next == nullptr)    return true;

    Node *slow = head;
    Node *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *firstHalf = head;
    Node *secondHalf = reverseLL(slow);

    while(secondHalf != nullptr){
        if(firstHalf->data != secondHalf->data) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << isPlaindrome(head);

    // Node *temp = head;
    // while(temp!=nullptr){
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    return 0;
}