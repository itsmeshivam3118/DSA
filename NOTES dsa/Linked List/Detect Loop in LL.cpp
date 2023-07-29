//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

//https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/S

//https://www.youtube.com/watch?v=VxOFflTXlXo&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=52&ab_channel=CodeHelp-byBabbar

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

}
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* fastPtr=head;
        Node*slowPtr=head;
        while(fastPtr&&slowPtr&&fastPtr->next){
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
            if(slowPtr==fastPtr)
            return true;
        }
        return false;
    }
};