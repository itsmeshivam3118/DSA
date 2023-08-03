//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
https://leetcode.com/problems/diameter-of-binary-tree/
//https://www.youtube.com/watch?v=nHMQ33LZ6oA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=70&ab_channel=CodeHelp-byBabbar



class Solution {
    pair<int,int>diameterFast(Node* root){
        if(root==NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>left = diameterFast(root->left);
        pair<int,int>right = diameterFast(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    
    int diameter(Node* root) {
      return diameterFast(root).first;
    }
};

// alitier better way
//(leetcode format)
class Solution {
    public:
   // int diameter = 0;
    int ans(TreeNode* root,int &diameter){
        if(!root)
            return 0;
        
        int lh = ans(root -> left,diameter);
        int rh = ans(root -> right,diameter);
        
        diameter = max(diameter,rh+lh);
        return max(rh,lh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        ans(root,diameter);
        return diameter;
    }
};
