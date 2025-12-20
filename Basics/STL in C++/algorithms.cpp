#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first > b.first; // Descending order of first if seconds are equal
    }
    return a.second < b.second; // Ascending order of second
}

void sort_example(){
    //properties: sorts elements in a range
    //underlying implementation: IntroSort (combination of QuickSort, HeapSort, and InsertionSort)
    //average time complexity: O(n log n)
    //data structure: linear
    cout << "--- Sort Example ---" << endl;
    vector<int> v = {5, 2, 9, 1, 5, 6};
    cout << "Original vector: ";
    for(int i : v){
        cout << i << " ";   
    }
    cout << endl;

    sort(v.begin(), v.end()); // Ascending order
    cout << "Sorted vector (ascending): ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>()); // Descending order
    cout << "Sorted vector (descending): ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    // Sorting a vector of pairs based on second element, then first element descending
    vector<pair<int, int>> vp = {{1, 3}, {2, 2}, {1, 2}, {2, 1}, {3, 3}, {1, 1}, {3, 1}};
    sort(vp.begin(), vp.end(), comparator);
    cout << "Sorted vector of pairs based on custom comparator: ";
    for(auto p : vp){
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;

    // Sorting an array
    int arr[] = {4, 2, 7, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]); // Calculate size of array // sizeof gives size in bytes
    sort(arr, arr + n); // Sort array in ascending order
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting a portion of an array
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    sort(arr2 + 1, arr2 + 5); // Sort elements from index 1 to 4
    cout << "Partially sorted array (index 1 to 4): ";
    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Sorting a string
    string str = "dcbalpearyan";
    sort(str.begin(), str.end());
    cout << "Sorted string: " << str << endl;   

    // built-in functions to get min and max elements
    int a = 10, b = 20;
    cout << "Min of " << a << " and " << b << ": " << min(a, b) << endl;
    cout << "Max of " << a << " and " << b << ": " << max(a, b) << endl;

    // built-in function to swap two elements
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // built-in function to reverse a range
    reverse(v.begin(), v.end());
    cout << "Reversed vector: ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;

    // built-in function to rotate a range
    // rotate(first, middle, last): rotates the range [first, last) such that the element at middle becomes the first element
    vector<int> v2 = {1, 2, 3, 4, 5};
    rotate(v2.begin(), v2.begin() + 2, v2.end()); // Rotate left by 2 positions
    cout << "Rotated vector (left by 2): ";
    for(int i : v2){
        cout << i << " ";
    }
    cout << endl;

    string str2 = "abcdef";
    rotate(str2.begin(), str2.begin() + 3, str2.end()); // Rotate left by 3 positions
    cout << "Rotated string (left by 3): " << str2 << endl;

    // built-in popcount function to count set bits in an integer
    unsigned int num = 234534; // Binary: 11101
    int set_bits = __builtin_popcount(num);
    cout << "Number of set bits in " << num << ": " << set_bits << endl;
    long long num2 = 1234567890123;
    int set_bits2 = __builtin_popcountll(num2);
    cout << "Number of set bits in " << num2 << ": " << set_bits2 << endl;

    //next permutation
    string perm = "3214";
    sort(perm.begin(), perm.end()); // Start from the lowest permutation
    cout << "All permutations of " << perm << ": ";
    do{
        cout << perm << " ";
    }while(next_permutation(perm.begin(), perm.end())); 
    cout << endl;

    //max element and min element in a range
    vector<int> v3 = {5, 3, 8, 1, 4};
    auto max_it = max_element(v3.begin(), v3.end());    
    auto min_it = min_element(v3.begin(), v3.end());
    cout << "Max element in v3: " << *max_it << endl;
    cout << "Min element in v3: " << *min_it << endl;
}

int main(){
    sort_example();
    return 0;
}