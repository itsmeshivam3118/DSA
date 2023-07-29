https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/#:~:text=Given%20a%20binary%20search%20tree,is%20the%20height%20of%20BST.


void inOrder(TreeNode<int>* root, TreeNode<int>* &prev){
    if(root == NULL)
        return;
    
    inOrder(root->left, prev);
    prev->left=NULL;
    prev->right=root;
    prev=root;
    inOrder(root->right, prev);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    
    // Dummy node
    TreeNode<int>* dummy = new TreeNode<int>(-1);
 
    // Pointer to previous element
    TreeNode<int>* prev = dummy;
 
    // Calling in-order traversal
    inOrder(root, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    TreeNode<int>* ret = dummy->right;
 
    // Delete dummy node
    free(dummy);
    return ret;
    
}