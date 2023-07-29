https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

https://youtu.be/Tl5qbEmEQyY?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA



// --------------------------DFS APPROACH--------------------------------------------

class Solution {
  public:
  bool isCyclic(int node, vector<int> adj[], vector<bool>&visited, vector<bool>&dfsVisited){
      visited[node] = true;
      dfsVisited[node] = true;
      
      for(auto i:adj[node]){
          if(!visited[i]){
              bool cycle = isCyclic(i, adj, visited, dfsVisited);
              if(cycle)
              return true;
          }
          else if(dfsVisited[i])
          return true;
      }
      dfsVisited[node] = false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V+1, 0);
        vector<bool>dfsVisited(V+1, 0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycle = isCyclic(i, adj, visited, dfsVisited);
                if(cycle)
                return true;
            }
        }
        return false;
    }
};


//------------------------------BFS APPROACH (using kahn algo concept)----------------------------------------

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
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
	int count = 0;
	while(!q.empty()){
	    int front = q.front();
	    q.pop();
	    
	    count++;
	    
	    for(auto i:adj[front]){
	        indegree[i]--;
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	}
	if(count == V)
	return false;
	else
	return true;
    }
};

