https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

https://youtu.be/eccAKrmffh8?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

class compare{
    public: 
    bool operator()(Node*a, Node*b){
        return a->data > b->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
    priority_queue<Node*, vector<Node*>, compare>pq;
    
    for(int i=0;i<K;i++){
        if(arr[i] != NULL)
        pq.push(arr[i]);
    }
    Node*head = NULL;
    Node*tail = NULL;
    while(!pq.empty()){
        Node*temp = pq.top();
        pq.pop();
        
        if(temp->next != NULL)
        pq.push(temp->next);
        
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
    }
};