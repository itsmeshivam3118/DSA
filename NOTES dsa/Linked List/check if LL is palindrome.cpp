//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

//https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

//https://www.youtube.com/watch?v=aD7mBVnKFEU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=55&ab_channel=CodeHelp-byBabbar


/*struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* temp=head;
        stack<int>st;
        while(temp){
            st.push(temp->data);
            temp=temp->next;
        }
        temp =head;
        while(temp){
           
            if(temp->data!=st.top())
            return false;
            
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};