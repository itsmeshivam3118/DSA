//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

//https://www.youtube.com/watch?v=s1d8UGDCCN8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=70&ab_channel=CodeHelp-byBabbar

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int>TopViewNodes;
        queue<pair<Node*,int>>q;
        vector<int>ans;
        
        if(root==NULL)
        return ans;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            Node*frontNode=temp.first;
            int hl=temp.second;
            
            if(TopViewNodes.find(hl)==TopViewNodes.end())
            TopViewNodes[hl]=frontNode->data;
            
            if(frontNode->left)
            q.push(make_pair(frontNode->left,hl-1));
            if(frontNode->right)
            q.push(make_pair(frontNode->right,hl+1));
        }
        for(auto i:TopViewNodes)
        ans.push_back(i.second);
        
        return ans;
    }

};