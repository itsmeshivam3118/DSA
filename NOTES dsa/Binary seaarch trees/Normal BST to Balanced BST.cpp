https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

https://youtu.be/IGHyX15fLI8?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

void inOrder(Node* root, vector<int>&v){
    if(root == NULL)
        return;
    
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
Node*solve(vector<int>v, int s, int l){
    
     if(s>l)
         return NULL;
    
         int mid = (s+l)/2;
        Node* temp = new Node(v[mid]);
         temp->left = solve(v, s, mid-1);
         temp->right = solve(v, mid+1, l);
         return temp;
    
}
Node* buildBalancedTree(Node* root)
{
	vector<int>v;
    inOrder(root, v);
    int n = v.size();
    
    Node*ans;
    ans = solve(v, 0, n-1);
    return ans;
}