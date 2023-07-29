//https://www.geeksforgeeks.org/merge-two-sorted-lists-place/

//https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

//https://www.youtube.com/watch?v=ogmBt6f9hw8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=55


    

       
 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* solve(Node* first, Node* second){
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    
    Node*curr1=first;
    Node*next1=curr1->next;
    Node*curr2=second;
    Node*next2=curr2->next;
    
    while(next1!=NULL&&curr2!=NULL){
        if(curr1->data<=curr2->data&&next1->data>=curr2->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=curr1->next;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
Node* sortedMerge(Node* first, Node* second)  
{
    
    if(first==NULL)
        return second;
    if(second==NULL)
      return first;
    
    if(first->data<=second->data)
        return solve(first,second);
        
     else 
         return solve(second,first);
}
