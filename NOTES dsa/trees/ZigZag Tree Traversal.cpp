//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//https://www.youtube.com/watch?v=s1d8UGDCCN8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=70&ab_channel=CodeHelp-byBabbar

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>result;
    	if(root == NULL)
    	return result;
    	
    	bool leftToRight = true;
    	
    	queue<Node*>q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    
    	    int size = q.size();
    	    vector<int>level(size);
    	    
    	    for(int i=0;i<size;i++){
    	        Node*node = q.front();
    	        q.pop();
    	        
    	        if(node -> left)
    	        q.push(node -> left);
    	        
    	        if(node -> right)
    	        q.push(node -> right);
    	        
    	        //normal insert or reverse insert
    	        int index = leftToRight ? i :size-i-1;
    	        level[index] = node -> data;
    	    }
    	    
    	    //change direction
    	    leftToRight = !leftToRight;
    	    
    	    for(auto i:level)
    	    result.push_back(i);
    	}
    	return result;
    }
};