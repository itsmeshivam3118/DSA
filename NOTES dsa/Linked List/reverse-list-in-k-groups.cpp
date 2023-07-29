//https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0

//https://www.youtube.com/watch?v=fi2vh0nQLi0&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=51&ab_channel=CodeHelp-byBabbar

/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    if(head==NULL)
        return head;
    
    Node* forward=NULL;
    Node* curr=head;
    Node* prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(head!=NULL){
        head->next=kReverse(forward,k);
    }
    return prev;  
}