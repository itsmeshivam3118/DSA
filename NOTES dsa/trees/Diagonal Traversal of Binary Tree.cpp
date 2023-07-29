//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

vector<int> diagonal(Node *root)
{
   queue<Node*>q;
   vector<int>ans;
   
   if(root==NULL)
   return ans;
   
   q.push(root);
   while(!q.empty()){
       Node*temp=q.front();
       q.pop();
       while(temp){
           ans.push_back(temp->data);
           
           if(temp->left)
           q.push(temp->left);
           
           temp=temp->right;
       }
   }
   return ans;
}