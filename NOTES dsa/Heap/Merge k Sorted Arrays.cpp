https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

https://youtu.be/VV19JFP6-0c

https://www.geeksforgeeks.org/merge-k-sorted-arrays/


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>ind(K,0);
        vector<int>ans;
    
    for(int i=0;i<K;i++){
        pq.push({arr[i][0], i});
    }
    while(!pq.empty()){
        pair<int,int>temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);
        
        if(ind[temp.second]+1 < arr[temp.second].size()){
            pq.push({arr[temp.second][ind[temp.second]+1], temp.second});
            ind[temp.second]+=1;
        }
        
    }
    return ans;
    }
};