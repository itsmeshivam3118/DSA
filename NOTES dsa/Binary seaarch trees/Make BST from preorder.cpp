https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0

https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

https://youtu.be/IGHyX15fLI8?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

BinaryTreeNode<int>* solve(vector<int> &preorder, int min, int max, int &i){
    if(i>=preorder.size())
        return NULL;
    if(preorder[i]<min || preorder[i]>max)
        return NULL;
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, min, root->data,i);
   root->right = solve(preorder, root->data, max, i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(preorder, min, max, i);
}