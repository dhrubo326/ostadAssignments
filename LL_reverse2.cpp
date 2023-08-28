#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(n).
// Space Complexity: O(1). 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Function to create linked list
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}


void display(ListNode* head){
    ListNode *current = head;
    while(current != nullptr){
        cout<<current->val<<" ";
        current = current->next;
    }
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || !head->next || left == right) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *nodeBeforeSublist = dummy;
    ListNode *workingPointer = nullptr;
    ListNode *nodeToBeExtracted = nullptr;
    for(int i=1; i<left; i++){
        nodeBeforeSublist = nodeBeforeSublist->next;
    }
    workingPointer = nodeBeforeSublist->next;

    // reversering porcess
    while(left<right){
        nodeToBeExtracted = workingPointer->next;
        workingPointer->next = nodeToBeExtracted->next;
        nodeToBeExtracted->next = nodeBeforeSublist->next;
        nodeBeforeSublist->next = nodeToBeExtracted;
        left++;
    }

    return dummy->next;        
}
     
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    int arr[] = {1, 2, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, n);
    int left = 3, right = 6;
    
    ListNode* rHead = reverseBetween(head, left, right);
    display(rHead);

    return 0;
}


