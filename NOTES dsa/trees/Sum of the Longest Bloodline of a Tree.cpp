//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

//https://www.youtube.com/watch?v=QG0hE0R_ng4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=71&t=351s&ab_channel=CodeHelp-byBabbar

class Solution
{
public:
    void solve(Node*root, int len, int &maxlen, int sum, int &maxsum){
        if(root == NULL){
            if(len > maxlen)
            {
                maxlen = len;
                maxsum = sum;
            }
            else if(len == maxlen)
            maxsum = max(sum,maxsum);
            
            return;
        }
        
        sum += root->data;
        
        solve(root->left, len+1, maxlen, sum, maxsum);
        solve(root->right, len+1, maxlen, sum, maxsum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int maxsum = INT_MIN;
        solve(root, len, maxlen, sum, maxsum);
        return maxsum;
    }
};