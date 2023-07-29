////https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

//https://takeuforward.org/data-structure/rat-in-a-maze/

//https://www.youtube.com/watch?v=GqtyVD-x_jY&ab_channel=CodeHelp-byBabbar

//https://www.geeksforgeeks.org/rat-in-a-maze-problem-when-movement-in-all-possible-directions-is-allowed/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    
    bool isSafe(int x,int y,int n,vector<vector<int>>&vis,vector<vector<int>> &m){
        if((x>=0&&x<n)&&(y>=0&&y<n)&&(vis[x][y]==0)&&(m[x][y]==1)){
        return true;
        else{
        return false;
        }
    }
    
    void solve(int x,int y,vector<vector<int>> &m,int n,vector<string>&ans,string move,vector<vector<int>>&vis){
        if(x==n-1&&y==n-1){
            ans.push_back(move);
            return;
        }
        vis[x][y]=1;
        if(isSafe(x+1,y,n,vis,m)){
            solve(x+1,y,m,n,ans,move+'D',vis);
        }
         if(isSafe(x,y+1,n,vis,m)){
            solve(x,y+1,m,n,ans,move+'R',vis);
        }
         if(isSafe(x-1,y,n,vis,m)){
            solve(x-1,y,m,n,ans,move+'U',vis);
        }
         if(isSafe(x,y-1,n,vis,m)){
            solve(x,y-1,m,n,ans,move+'L',vis);
        }
        vis[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0)
        return ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        solve(0,0,m,n,ans,"",vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  