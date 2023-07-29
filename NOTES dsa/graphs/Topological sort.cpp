https://practice.geeksforgeeks.org/problems/topological-sort/1

https://youtu.be/T_boOrr0rvk?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

https://www.geeksforgeeks.org/topological-sorting/


// --------------------------USING DFS-------------------------------------------

class Solution
{
	public:
	void topoSort(vector<int> adj[], int node, vector<bool>&visited, stack<int>&st){
	    visited[node] = true;
	    
	    for(auto i:adj[node]){
	        if(!visited[i])
	        topoSort(adj, i, visited, st);
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V+1,0);
	    stack<int>st;
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	        topoSort(adj, i, visited, st);
	    }
	    vector<int>ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
};


//------------------------------BFS APPROACH(KAHN'S ALGORITHM)------------------------

https://youtu.be/6XmzL04mlgQ?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V);
	      for (int u = 0; u < V; u++) {
        vector<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
            indegree[*itr]++;
    }
	    
	    	queue<int>q;
	for(int i=0;i<V;i++){
	    if(indegree[i] == 0)
	    q.push(i);
	}
	vector<int>ans;
	while(!q.empty()){
	    int front = q.front();
	    q.pop();
	    
	    ans.push_back(front);
	    
	    for(auto i:adj[front]){
	        indegree[i]--;
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	}
	return ans;
	}
	

};