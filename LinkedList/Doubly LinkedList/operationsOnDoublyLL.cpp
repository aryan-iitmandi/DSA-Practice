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

class DoublyLL{
    private:
        Node *head;
    
    public:
        DoublyLL(){
            head = nullptr;
        }

        // convert arr/vector to doubly LL
        void createDoublyLL(vector<int> &arr){
            if(arr.empty()) return;

            head = new Node(arr[0]);
            Node *current = head;
            for(int i=1; i<arr.size(); i++){
                Node *newNode = new Node(arr[i]);
                current->next = newNode;
                newNode->prev = current;
                current = newNode;
            }
        }

        // print forward
        void printForward(){
            Node *temp = head;
            while(temp != nullptr){
                if(temp->prev == nullptr)   cout << "Null <--> ";
                cout << temp->data << " <--> ";
                if(temp->next == nullptr)   cout << "Null\n";
                temp = temp->next;
            }
        }

        // print backward
        // first goto last node then move backward using prev
        void printBackward(){
            if(head == nullptr) return;
            Node *temp = head;
            while(temp->next != nullptr)    temp = temp->next;
            while(temp != nullptr){
                if(temp->next == nullptr)   cout << "Null <--> ";
                cout << temp->data << " <--> ";
                if(temp->prev == nullptr)   cout << "Null\n";
                temp = temp->prev;
            }
        }

        // <<<------------------------------------------------->>>
        // insert at head
        void insertHead(int value){
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        
        // insert at tail
        void insertTail(int value){
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr)    temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }

        // <<<-------------------------------------------------->>>
        // delete at head/tail has similar logic
        // delete by value
        void deleteByValue(int value){
            Node *temp = head;
            while(temp != nullptr && temp->data != value)   temp = temp->next;

            // not found
            if(temp == nullptr) return;

            // only one node
            if(temp == head && temp->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }

            // value found at head
            if(temp == head){
                head = head->next;
                head->prev = nullptr;
                delete temp;
                return;
            }

            // value found at tail
            if(temp->next == nullptr){
                temp->prev->next = nullptr;
                delete temp;
                return;
            }

            // somewhere in middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

        // <<<---------------------------------------------------->>
        // length
        int length(){
            Node *temp = head;
            int len = 0;
            while(temp != nullptr){
                len++;
                temp = temp->next;
            }
            return len;
        }

        // reverse DLL
        void reverseDLL(){
            if(head == nullptr || head->next == nullptr)    return;

            Node *temp = head;
            Node *visited = nullptr;
            
            while(temp != nullptr){
                swap(temp->prev, temp->next);
                visited = temp;
                temp = temp->prev;
            }
            head = visited;
        }
};

int main(){
    int ip;
    vector<int> arr;
    while(cin >> ip)    arr.push_back(ip);

    DoublyLL dll;
    dll.createDoublyLL(arr);
    dll.printForward();
    // dll.printBackward();

    // dll.insertHead(1);
    // dll.insertTail(99);
    // dll.deleteByValue(22);

    dll.reverseDLL();
    dll.printForward();
    // cout << dll.length();

    return 0;
}