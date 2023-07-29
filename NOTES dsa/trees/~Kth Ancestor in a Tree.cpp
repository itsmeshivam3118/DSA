https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1


bool solve(Node*root, int&k, int node, int &ans){
    if(root == NULL)
    return false;
    
    if(root->data==node)
     return true;
    
    if(solve(root->left, k, node, ans)||solve(root->right, k, node, ans)){
        k--;
        if(k==0)
            ans = root->data;
            
            return true;
        
    }
    return false;
    
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=0;
     solve(root, k, node, ans);
    if(ans == NULL||ans == node)
    return -1;
    else
    return ans;
}
