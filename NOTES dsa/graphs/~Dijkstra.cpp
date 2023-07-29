https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

https://takeuforward.org/data-structure/dijkstras-algorithm-shortest-distance/

https://youtu.be/dVUR3Rm6biE?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

https://youtu.be/jbhuqIASjoM


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V+1,INT_MAX);
        dist[S] = 0;
        pq.push(make_pair(0,S));
        while(!pq.empty()){
            int distTopNode = pq.top().first;
            int topNode = pq.top().second;
            pq.pop();
            for(auto i:adj[topNode]){
                if(distTopNode + i[1] < dist[i[0]]){
                    
                    dist[i[0]] = distTopNode + i[1];
                    pq.push(make_pair(dist[i[0]], i[0]));
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends