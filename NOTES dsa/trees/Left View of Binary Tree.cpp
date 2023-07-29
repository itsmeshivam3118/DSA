//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

//https://www.youtube.com/watch?v=s1d8UGDCCN8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=70&ab_channel=CodeHelp-byBabbar

void solve(Node*root,vector<int>&ans,int lvl){
    if(root==NULL)
    return;
    
    if(lvl==ans.size())
    ans.push_back(root->data);
    
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   solve(root,ans,0);
   return ans;
   
}
