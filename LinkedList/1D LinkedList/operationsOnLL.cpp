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
        void createLL(vector<int> &arr){
            head = new Node(arr[0]);
            Node *current = head;

            if(arr.empty())     return;

            for(int i=1; i<arr.size(); i++){
                current->next = new Node(arr[i]);
                current = current->next;
            }
        }

        // print LL
        void printLL(){
            Node *temp = head;

            while(temp != nullptr){
                cout << temp->data;
                if(temp->next == nullptr)   cout << " -> Null";
                else    cout << " -> ";
                temp = temp->next;
            }
        }

        // insert at head
        void insertHead(int data){
            Node *newNode = new Node(data, head);
            head = newNode;
        }

        // insert at last
        void insertLast(int data){
            Node *newNode = new Node(data);
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        // insert after value
        void insertAfterValue(int value, int data){
            Node *temp = head;
            while(temp != nullptr){
                if(temp->data == value){
                    Node *newNode = new Node(data);
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            }
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

        // delete by value
        void deleteByValue(int value){
            if(head == nullptr) return;

            if(head->data == value){
                Node *temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node *current = head;
            while(current->next != nullptr){
                if(current->next->data == value){
                    Node *temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
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
    ll.insertHead(1);
    // ll.deleteHead();
    ll.insertLast(32);
    // ll.deletelast();
    ll.insertAfterValue(55, 99);
    // ll.deleteByValue(12);
    ll.printLL();
    cout << endl;
    cout << ll.findLength() << endl;
    cout << ll.search(45) << endl;

    return 0;
}