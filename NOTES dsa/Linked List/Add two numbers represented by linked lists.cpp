//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

//https://www.youtube.com/watch?v=HiRlTPf9aCg&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=56&t=18s&ab_channel=CodeHelp-byBabbar

//https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/


class Solution
{
    public:
    Node* reverse(Node* head){
        Node*prev=NULL;
        Node*curr=head;
        Node*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
       void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        
        Node* temp = new Node(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    Node* add(struct Node* first, struct Node* second){
        int carry=0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1=0;
            if(first!=NULL)
            val1=first->data;
            
            int val2=0;
            if(second!=NULL)
            val2=second->data;
            
            int sum=carry+val1+val2;
            int digit=sum%10;
            
            //create a node and add in answer LL
            insertAtTail(ansHead, ansTail, digit);
            
            carry=sum/10;
            if(first!=NULL)
            first=first->next;
            
            if(second!=NULL)
            second=second->next;
        }
        return ansHead;
        
        
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step1=reverse the LL
       first= reverse(first);
       second= reverse(second);
        
        //step2=add both LL
        Node*ans=add(first,second);
        
        //step3=reverse the ans LL
        
        ans=reverse(ans);
        
        return ans;
        
        
    }
};