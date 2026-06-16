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
            cout << endl;
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

        // find middle node
        Node *findMiddle(){
            if(head == nullptr) return nullptr;

            Node *hare = head;
            Node *tortoise = head;

            while(hare != nullptr && hare->next != nullptr){
                hare = hare->next->next;
                tortoise = tortoise->next;
            }
            return tortoise;
        }

        // reverse a LL
        void reverseLL(){
            Node *prev = nullptr;
            Node *current = head;
            Node *next = nullptr;

            while(current != nullptr){
                next = current->next;
                current->next = prev;

                prev = current;
                current = next;
            }
            head = prev;
        }
};

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.push_back(ip);

    LinkedList ll;
    ll.createLL(arr);
    ll.printLL();

    // Node *middleNode = ll.findMiddle();
    // if(middleNode)  cout << middleNode->data;

    // ll.reverseLL();
    // ll.printLL();
    return 0;
}