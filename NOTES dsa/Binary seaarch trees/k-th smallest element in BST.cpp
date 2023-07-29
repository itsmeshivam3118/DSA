https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

https://youtu.be/pDURIj98e0I?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA



class Solution {
  public:
  int solve(Node* root, int &k){
    if(root == NULL)
        return -1;
    int left=solve(root->left, k);
    if(left!=-1)
        return left;
    
    k--;
    if(k==0)
        return root->data;
    
    return solve(root->right, k);  
}
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
          int ans = 0;
    ans = solve(root, K);
    return ans;
    }
};