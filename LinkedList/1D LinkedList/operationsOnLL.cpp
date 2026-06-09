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

class LinkedList{
    private:
        Node *head;

    public:

        LinkedList(){
            head = nullptr;
        }

        // convert arr/vector to LL
        Node *createLL(vector<int> &arr){
            head = new Node(arr[0]);
            Node *current = head;

            if(arr.empty())     return nullptr;

            for(int i=1; i<arr.size(); i++){
                current->next = new Node(arr[i]);
                current = current->next;
            }
            return head;
        }

        // print LL
        void printLL(){
            Node *temp = head;

            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "Null";
        }

        // insert at head
        void insertAtHead(int data){
            Node *newNode = new Node(data, head);
            head = newNode;
        }

        // delete at head
        void deleteHead(){
            if(head == nullptr) return;

            Node *temp = head;
            head = temp->next;
            delete temp;
        }

        // delete last node
        void deletelast(){
            if(head == nullptr) return;
            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }

            Node *temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

        // find length of LL
        int findLength(){
            int len = 0;
            Node *temp = head;

            while(temp != nullptr){
                len++;
                temp = temp->next;
            }
            return len;
        }

        // search in a LL
        int search(int value){
            int index = 0;
            Node *temp = head;

            while(temp != nullptr){
                if(temp->data == value) return index;
                index++;
                temp = temp->next;
            }
            return -1;
        }
};

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.push_back(ip);

    LinkedList ll;
    ll.createLL(arr);
    ll.insertAtHead(1);
    ll.deleteHead();
    ll.deletelast();
    ll.printLL();
    cout << endl;
    cout << ll.findLength() << endl;
    cout << ll.search(45) << endl;

    return 0;
}