/*Linked list Node structure

struct Node
{
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
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<pair<int,Node*> ,vector<pair<int,Node*>>, greater<pair<int,Node*>> > pq ;
        // priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

        int k = arr.size();
        if(k==0) return nullptr ;
        
        Node* dummy = new Node(0);
        Node* cur = dummy;
        
        for(int i=0;i<k;i++){
            if(arr[i]){
                pq.push({arr[i]->data, arr[i]});
            }
        }
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            cur->next = x.second;
            cur = cur->next;
            
            if(x.second->next){
                pq.push({x.second->next->data, x.second->next});
            }
        }
        return dummy->next;
    }
};