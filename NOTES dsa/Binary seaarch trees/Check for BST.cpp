https://practice.geeksforgeeks.org/problems/check-for-bst/1

https://youtu.be/pDURIj98e0I?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA



class Solution
{
    public:
    bool checkBst(Node* root,int min,int max){
        if(root == NULL)
        return true;
        
        if(root->data>min && root->data<max){
         bool left = checkBst(root->left, min, root->data);
         bool right = checkBst(root->right, root->data, max);
            return left && right;
        }
        else return false;  
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        bool ans = checkBst(root, INT_MIN, INT_MAX);
        return ans;
    }
};