https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/

https://www.geeksforgeeks.org/detect-cycle-undirected-graph/#:~:text=Approach%3A%20Run%20a%20DFS%20from,edge%20present%20in%20the%20graph.

https://youtu.be/1cSzxlhxOw8?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA


// --------------USING BFS----------------------------------------

class Solution {
  public:
  bool isCyclic(vector<int> adj[], int node, vector<bool>&visited){
      unordered_map<int,int>parent;
      
      parent[node] = -1;
      visited[node] = true;
      queue<int>q;
      q.push(node);
      
      while(!q.empty()){
          int temp = q.front();
          q.pop();
          for(auto i:adj[temp]){
              if(visited[i] == true && i != parent[temp])
              return true;
              else if(visited[i] == false){
                  q.push(i);
                  visited[i] = true;
                  parent[i] = temp;
              }
          }
      }
      return false;
          
      }
  
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V+1,0);
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                bool ans = isCyclic(adj, i, visited);
                if(ans == 1)
                return 1;
            }
        }
        return 0;
    }
};

// ----------------------------USING DFS-----------------------------------------------

class Solution {
  public:
  bool isCyclicDFS(vector<int> adj[], int node, int parent, vector<bool>&visited){
      visited[node] = true;
      
      for(auto i:adj[node]){
          if(!visited[i]){
              bool cycle = isCyclicDFS(adj, i, node, visited);
              if(cycle)
              return true;
          }
          else if(i != parent)
          return true;
      }
      return false;
          
      }
  
    /
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V+1,0);
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                bool ans = isCyclicDFS(adj, i, -1, visited);
                if(ans == 1)
                return 1;
            }
        }
        return 0;
    }
};