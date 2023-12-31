https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

https://youtu.be/2BdY9fixMrM?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA


class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                Node*prev = curr->left;
                while(prev->right!=NULL&&prev->right!=curr)
                    prev=prev->right;
                    
                    prev->right = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
            }
                
                curr = curr->right;
        }
            
    }
};