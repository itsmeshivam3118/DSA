//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

//https://www.youtube.com/watch?v=s1d8UGDCCN8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=70&ab_channel=CodeHelp-byBabbar

//https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        vector<int>ans;
        
        if(root == NULL)
        return ans;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            
            Node*frontNode=temp.first;
            int hl=temp.second.first;
            int lvl=temp.second.second;
            
            nodes[hl][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(hl-1,lvl+1)));
            if(frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(hl+1,lvl+1)));
        }
        
          for(auto i: nodes) {
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

//Alternate without using levels
//better

 vector<int> verticalOrder(Node *root)
    {
         map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(!root)
        return ans;
        
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int> p = q.front();
            q.pop();
            
            Node *curr = p.first;
            int hd = p.second;
            
            mp[hd].push_back(curr->data);
            
            if(curr->left)
            q.push(make_pair(curr->left,hd-1));
            if(curr->right)
            q.push(make_pair(curr->right,hd+1));
        }
         for(auto it: mp)
        {
            for(auto i : it.second)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }