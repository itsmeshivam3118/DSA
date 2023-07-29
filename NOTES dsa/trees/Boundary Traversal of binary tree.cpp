//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

//https://www.youtube.com/watch?v=s1d8UGDCCN8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=70&ab_channel=CodeHelp-byBabbar


lass Solution {
    void leftBoundary(Node* root, vector<int> &ans){
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        return;
        
        ans.push_back(root->data);
        if(root->left)
        leftBoundary(root->left,ans);
        else
        leftBoundary(root->right,ans);
    }
    void leafNodes(Node* root, vector<int> &ans){
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;}
            
            leafNodes(root->left,ans);
            leafNodes(root->right,ans);
        
    }
    void rightBoundary(Node* root, vector<int> &ans){
        if(root==NULL||(root->left == NULL && root->right == NULL))
        return;
        
        if(root->right)
            rightBoundary(root->right, ans);
        else
            rightBoundary(root->left, ans);
        
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        
        if(root==NULL)
        return ans;
        
        
        ans.push_back(root->data);
        
        //left boundary
        leftBoundary(root->left,ans);
        
        //leaf nodes
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
        
        
        //right boundary
        rightBoundary(root->right,ans);
        
        return ans;
    }
};