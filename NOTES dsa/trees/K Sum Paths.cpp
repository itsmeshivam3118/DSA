https://practice.geeksforgeeks.org/problems/k-sum-paths/1

https://www.youtube.com/watch?v=QG0hE0R_ng4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=71&t=1217s&ab_channel=CodeHelp-byBabbar

class Solution{
  public:
  void solve(Node*root, int k, vector<int>v, int &count, int sum){
      if(root == NULL)
      return ;
      
      v.push_back(root->data);
      
      solve(root->left, k, v, count, sum);
      solve(root->right, k, v, count, sum);
      
      for(int i=v.size()-1; i>=0; i--){
          sum += v[i];
          if(sum == k)
          count++;
      }
      
      v.pop_back();
  }
    int sumK(Node *root,int k)
    {
        vector<int>v;
        int count = 0;
        solve(root, k, v, count, 0);
        return count;
    }
};