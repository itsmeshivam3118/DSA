https://practice.geeksforgeeks.org/problems/largest-bst/1

https://youtu.be/fqx8z3VepMA?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

class Solution{
    public:
    
     class info{
    public:
    int maxi;
    int mini;
    int size;
    bool isBST;
};
info solve(Node* root, int &ans){
    if(root == NULL)
       return {INT_MIN, INT_MAX, 0, true};
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info currNode;
    
    currNode.size = left.size + right.size + 1;
    currNode.mini = min(root->data, left.mini);
    currNode.maxi = max(root->data, right.maxi);
    
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else
        currNode.isBST = false;
    
    if(currNode.isBST)
        ans = max(ans, currNode.size);
    
    return currNode;
}
    int largestBst(Node *root)
    {
        int maxSize = 0;
        info temp = solve(root, maxSize);
        return maxSize;
    }
};