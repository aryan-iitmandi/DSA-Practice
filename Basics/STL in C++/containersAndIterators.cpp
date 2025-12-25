#include<bits/stdc++.h>
using namespace std;

void pair_example(){
    // properties: stores two heterogeneous objects
    // underlying implementation: struct with two public data members
    // average time complexity for insert, erase, find: O(1)
    // data structure: linear
    cout << "--- Pair Example ---" << endl;

    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[2].second << endl;

    pair<int, int> p2 = make_pair(5, 6);
    cout << p2.first << " " << p2.second << endl;

    pair p3 = make_pair(7.5, 'A'); // C++17 feature: Class Template Argument Deduction
    cout << p3.first << " " << p3.second << endl;

    pair<string, int> p4 = {"Hello", 10};
    cout << p4.first << " " << p4.second << endl;
}

// Print vector function
void printVector(const vector<int> &v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl << endl;
}

void vector_example(){
    // properties: dynamic array
    // underlying implementation: dynamic array
    // average time complexity for insert, erase, find: O(1) for insert/find at end, O(n) for erase/find elsewhere
    // data structure: linear
    cout << endl << "--- Vector Example ---" << endl;
    
    vector<int> v; // Declaration

    // Insertion
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.emplace_back(4); // More efficient than push_back
    // Insert multiple elements
    for(int i = 5; i <= 10; i++){
        v.emplace_back(i);
    }
    cout << "Vector v: ";
    printVector(v);
    cout << "Size: " << v.size() << endl;

    vector<int> v2(5, 10); // Vector of size 5, all elements initialized to 10
    cout << "Vector v2: ";
    printVector(v2);

    vector<int> v3(10); // Vector of size 10, default initialized with 0
    cout << "Vector v3 (default initialized): ";
    printVector(v3);

    // Deletion
    v.pop_back(); // Removes last element   
    printVector(v);
    cout << "Size after pop_back: " << v.size() << endl << endl;

    // Accessing elements
    cout << "Element at index 1: " << v[1] << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max size: " << v.max_size() << endl << endl;

    // Iterators
    cout << "Elements using iterators: ";
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " "; 
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    it++;
    cout << "Element at iterator position 1: " << *(it) << endl << endl;
    
    // Erasing elements
    v.erase(v.begin() + 1); // Erase element at index 1
    cout << "After erasing element at index 1: ";
    printVector(v);
    v.erase(v.begin() + 1, v.begin() + 6); // Erase elements from index 1 to 5
    cout << "After erasing elements from index 1 to 5: ";
    printVector(v);

    // difference between size and capacity
    cout << "Final Size: " << v.size() << endl;
    cout << "Final Capacity: " << v.capacity() << endl;

    // difference between begin/end and front/back
    cout << "First element using front(): " << v.front() << endl;
    cout << "First element using begin(): " << *(v.begin()) << endl;
    cout << "Last element using back(): " << v.back() << endl;
    cout << "Last element using end(): " << *(v.end() - 1) << endl;

    // Insert function
    v.insert(v.begin(), 100); // Insert 100 at the beginning
    cout << "After inserting 100 at the beginning: ";
    printVector(v);

    v.insert(v.begin() + 1, 2, 50); // Insert two 50s at index 1
    cout << "After inserting two 50s at index 1: ";
    printVector(v);

    vector<int> v4 = {200, 300, 400};
    v.insert(v.begin() + 2, v4.begin(), v4.end()); // Insert elements of v4 starting at index 2
    cout << "After inserting elements of v4 at index 2: ";
    printVector(v);

    // Resize Vector
    v.resize(10); // Resize to 10 elements
    cout << "After resizing to 10 elements: ";
    printVector(v);

    // Reserve Capacity
    v.reserve(20); // Reserve capacity for at least 20 elements
    cout << "Capacity after reserving space for 20 elements: " << v.capacity() << endl;

    // Pop back
    v.pop_back();
    cout << "After pop_back: " << endl;
    printVector(v);

    // Clear Vector
    v.clear();
    cout << "After clearing, is vector empty? " << (v.empty() ? "Yes" : "No") << endl;
}

void list_example(){
    // properties: doubly linked list
    // underlying implementation: doubly linked list
    // average time complexity for insert, erase, find: O(1) for insert/erase, O(n) for find
    // data structure: linear   
    cout << endl << "--- List Example ---" << endl;
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(0);  
    lst.emplace_back(3);
    lst.emplace_front(-1);
    cout << "List elements: ";
    for(auto it : lst){
        cout << it << " ";
    }
    cout << endl;
    printVector(vector<int>(lst.begin(), lst.end()));

    //rest functions are similar to vector
}

void deque_example(){
    // properties: double-ended queue
    // underlying implementation: dynamic array or doubly linked list
    // average time complexity for insert, erase, find: O(1) at both ends
    // data structure: linear
    cout << "--- Deque Example ---" << endl;
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(0);
    dq.emplace_back(2);
    dq.emplace_front(-1);
    cout << "Deque elements: ";
    for(auto it : dq){
        cout << it << " ";
    }
    cout << endl;
    printVector(vector<int>(dq.begin(), dq.end()));

    //rest functions are similar to vector  
}

void stack_example(){
    // properties: LIFO
    // underlying implementation: deque (by default)
    // average time complexity for insert, erase, find: O(1)
    // data structure: linear
    cout << "--- Stack Example ---" << endl;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);
    //multiple pushs
    for(int i = 5; i <= 10; i++){
        st.push(i);
    }
    // Print stack elements (not directly possible, so we use a temporary stack)
    stack<int> temp = st;
    cout << "Stack elements (top to bottom): ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element after pop: " << st.top() << endl;
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Stack size: " << st.size() << endl;
}

void queue_example(){
    // properties: FIFO
    // underlying implementation: deque (by default)
    // average time complexity for insert, erase, find: O(1)
    // data structure: linear
    cout << endl << "--- Queue Example ---" << endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);
    //multiple pushs
    for(int i = 5; i <= 10; i++){
        q.push(i);
    }
    // Print queue elements (not directly possible, so we use a temporary queue)
    queue<int> temp = q;
    cout << "Queue elements (front to back): ";
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    q.pop(); // removes front element
    cout << "Front element after pop: " << q.front() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Queue size: " << q.size() << endl;
}
    
void priority_queue_example(){
    // properties: ordered (sorted), allows duplicates
    // underlying implementation: binary heap
    // average time complexity for insert, erase, find: O(log n)
    // data structure: heap-based

    // Max-heap by default
    cout << endl << "--- Priority Queue Example ---" << endl;
    priority_queue<int> pq; // Max-heap by default
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(3);
    cout << "Priority Queue elements (from top to bottom): ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(5);
    min_pq.push(1);
    min_pq.push(10);
    min_pq.push(3);
    cout << "Min-Heap Priority Queue elements (from top to bottom): ";
    while(!min_pq.empty()){
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl;
}

void set_example(){
    cout << endl << "--- Set Example ---" << endl;
    // properties: ordered (sorted), unique elements
    // underlying implementation: balanced BST (typically Red-Black Tree)
    // average time complexity for insert, erase, find: O(log n)
    // data structure: tree-based
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(1); // Duplicate, will be ignored
    s.insert(10);
    s.emplace(2);
    s.insert(3);
    cout << "Set elements: ";
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;
    auto it = s.find(3); // returns iterator to element if found, else s.end()
    cout << "Finding 3 in set: " << (it != s.end() ? "Found" : "Not Found") << endl;
    auto it2 = s.find(7);
    cout << "Finding 7 in set: " << (it2 != s.end() ? "Found" : "Not Found") << endl;  

    int count = s.count(10); // returns 1 if found, else 0
    cout << "Count of 10 in set: " << count << endl;
    s.erase(2); // erase element 2 // takes O(log n)
    auto it3 = s.find(2);
    if(it3 != s.end()){
        s.erase(it3);
    } // erase using iterator // takes O(1)

    auto it4 = s.lower_bound(3); // >= 3
    cout << "Lower bound of 3: " << (it4 != s.end() ? to_string(*it4) : "Not Found") << endl;
    auto it5 = s.upper_bound(3); // > 3
    cout << "Upper bound of 3: " << (it5 != s.end() ? to_string(*it5) : "Not Found") << endl;
}

void multi_set_example(){
    // properties: ordered (sorted), allows duplicates
    // underlying implementation: balanced BST (typically Red-Black Tree)
    // average time complexity for insert, erase, find: O(log n)
    // data structure: tree-based
    cout << endl << "--- Multi-Set Example ---" << endl;
    multiset<int> ms;
    ms.insert(5);
    ms.insert(1);
    ms.insert(1); // Duplicate, will be stored
    ms.insert(10);
    ms.emplace(2);
    ms.insert(3);
    cout << "Multi-Set elements: ";
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;
    auto it = ms.find(1); // returns iterator to first occurrence if found, else ms.end()
    cout << "Finding 1 in multi-set: " << (it != ms.end() ? "Found" : "Not Found") << endl;
    auto it2 = ms.find(7);
    cout << "Finding 7 in multi-set: " << (it2 != ms.end() ? "Found" : "Not Found") << endl;

    int count = ms.count(1); // returns number of occurrences
    cout << "Count of 1 in multi-set: " << count << endl;
    ms.erase(1); // erase all occurrences of element 1 // takes O(log n)
    cout << "After erasing all occurrences of 1, multi-set elements: ";
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;

    ms.erase(ms.find(2), ms.find(2)); // erase using iterators // takes O(k) where k is number of elements erased
    cout << "After erasing elements from 2 to 5, multi-set elements: ";
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;
}

void unordered_set_example(){
    // properties: unordered, unique elements
    // underlying implementation: hash table
    // average time complexity for insert, erase, find: O(1)
    // data structure: hash-based
    // random order of elements
    cout << endl << "--- Unordered Set Example ---" << endl;
    unordered_set<int> us;
    // rest of the implementation similar to set
}

void map_example(){
    // properties: ordered (sorted) key-value pairs, unique keys
    // underlying implementation: balanced BST (typically Red-Black Tree)
    // average time complexity for insert, erase, find: O(log n)
    // data structure: tree-based
    // keys are unique and sorted, values can be duplicate
    cout << endl << "--- Map Example ---" << endl;
    map<int, int> mp;
    mp[1] = 100;
    mp.emplace(2, 200); // More efficient than mp[2] = 200
    mp[3] = 300;
    mp[2] = 250; // Update value for key 2
    mp[4] = 400;
    mp[5] = 500;
    cout << "Map elements (key-value pairs): " << endl;
    for(auto it : mp){
        cout << it.first << " -> " << it.second << endl;
    }
    auto it = mp.find(2); // returns iterator to key-value pair if found, else mp.end()
    auto it2 = mp.find(5);
    cout << it2->first << " -> " << it2->second << endl;

    auto it3 = mp.lower_bound(3); // >= key 3
    cout << "Lower bound of key 3: " << (it3 != mp.end() ? to_string(it3->first) + " -> " + to_string(it3->second) : "Not Found") << endl;
    auto it4 = mp.upper_bound(3); // > key 3
    cout << "Upper bound of key 3: " << (it4 != mp.end() ? to_string(it4->first) + " -> " + to_string(it4->second) : "Not Found") << endl;
}

void multimap_example(){
    // properties: ordered (sorted) key-value pairs, allows duplicate keys
    // rest of the implementation similar to map
    cout << endl << "--- Multi-Map Example ---" << endl;
}

void unordered_map_example(){
    // properties: unordered key-value pairs, unique keys
    // rest of the implementation similar to map
    cout << endl << "--- Unordered Map Example ---" << endl;
}

int main(){
    pair_example();
    vector_example();
    list_example();
    deque_example();
    stack_example();
    queue_example();
    priority_queue_example();
    set_example();
    multi_set_example();
    unordered_set_example();
    map_example();
    multimap_example();
    unordered_map_example();
    return 0;
}