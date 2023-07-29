https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1


class Solution{
  public:
    
    void inOrder(struct Node* root, vector<int>&v){
    if(root == NULL)
        return;
    
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
    int isPairPresent(struct Node *root, int target)
    {
     vector<int>v;
    inOrder(root, v);
    int s = v.size();
    int i = 0;
    int j = s-1;
    while(i<j){
        if(v[i]+v[j] == target)
            return true;
        else if(v[i]+v[j] > target)
            j--;
        else 
            i++;
    }
    return false;
    }