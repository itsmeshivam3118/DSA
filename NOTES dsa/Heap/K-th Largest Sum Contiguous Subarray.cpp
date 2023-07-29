https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/


class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int, vector<int>, greater<int>>pq;
       
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=i;j<N;j++){
                sum += Arr[j];
                if(pq.size()<K){
                pq.push(sum);
                }
                else{
                    if(pq.top()<sum){
                    pq.pop();
                    pq.push(sum);
                }
                
            }
        }
     }
        
    
    return pq.top();
    }
};