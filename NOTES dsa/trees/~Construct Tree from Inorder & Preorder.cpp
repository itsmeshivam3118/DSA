https://practice.geeksforgeeks.org/problems/construct-tree-1/1

https://www.youtube.com/watch?v=ffE1xj51EBQ&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=72&ab_channel=CodeHelp-byBabbar


class Solution{
    public:
    void createMapping(int in[], unordered_map<int,int>&nodeToIndex, int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
    
    Node*solve(int in[], int pre[], int&index, int inOrderStart, int inOrderEnd, int n, unordered_map<int,int>&nodeToIndex){
        
        if(index>=n|| inOrderStart>inOrderEnd )
        return NULL;
        
        int element = pre[index];
        Node*root = new Node(element);
        int position = nodeToIndex[element];
        index++;
        
        
        root->left = solve(in, pre, index, inOrderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, index, position+1, inOrderEnd, n, nodeToIndex);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int,int>nodeToIndex;
        int preOrderIndex = 0;
        createMapping(in, nodeToIndex, n);
        Node*ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};