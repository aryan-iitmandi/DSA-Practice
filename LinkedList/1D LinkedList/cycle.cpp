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

struct cycleInfo{
    bool hasCycle;
    Node *startNode;
    int cycleLenght;
};

class LinkedList{
private:
    Node* head;

public:

    LinkedList(){
        head = nullptr;
    }

    void createLL(vector<int>& arr){
        if(arr.empty()) return;
        head = new Node(arr[0]);
        Node* current = head;

        for(int i = 1; i < arr.size(); i++){
            current->next = new Node(arr[i]);
            current = current->next;
        }
    }

    // For testing
    // Connect last node to node at position pos (1-based)
    void createCycle(int pos){
        if(head == nullptr) return;
        Node* cycleNode = nullptr;
        Node* temp = head;

        int count = 1;
        while(temp->next != nullptr){
            if(count == pos)    cycleNode = temp;
            temp = temp->next;
            count++;
        }

        if(count == pos)    cycleNode = temp;
        if(cycleNode)   temp->next = cycleNode;
    }

    cycleInfo getCycleInfo(){
        Node *slow = head;
        Node *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                
                // find length
                int length = 1;
                Node *temp = slow->next;
                while(temp != slow){
                    length++;
                    temp = temp->next;
                }

                // find cycle start
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }

                return {true, slow, length};
            }
        }
        return {false, nullptr, -1};
    }
};

int main(){
    vector<int> arr;
    int x;
    while(cin >> x) arr.push_back(x);

    LinkedList ll;
    ll.createLL(arr);
    // Example:
    // 1 -> 2 -> 3 -> 4 -> 5
    //      ^            |
    //      |____________|
    ll.createCycle(2);

    cycleInfo info = ll.getCycleInfo();
    if(info.hasCycle){
        cout << "Cycle Found\n";
        cout << "Cycle Start Node = " << info.startNode->data << endl;
        cout << "Cycle Length = " << info.cycleLenght << endl;
    }
    else    cout << "No Cycle\n";

    return 0;
}