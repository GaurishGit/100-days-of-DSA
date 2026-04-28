/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

A Min-Heap must satisfy:
1. It is a complete binary tree
2. Every parent node is smaller than its children
*/

#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>& arr, int n) {
    for(int i = 0; i <= (n - 2) / 2; i++) {
        if(arr[i] > arr[2 * i + 1]) return false;
        if(2 * i + 2 < n && arr[i] > arr[2 * i + 2]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if(isMinHeap(arr, n)) cout << "YES";
    else cout << "NO";
    
    return 0;
}