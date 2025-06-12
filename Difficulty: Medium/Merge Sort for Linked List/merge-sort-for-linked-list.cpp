/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        vector<int> arr;
        Node* temp = head;
        while(temp){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        temp = head;
        for(int i=0;i<arr.size();i++){
            temp->data = arr[i];
            temp = temp->next ;
        }
        return head;
    }
};