//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//https://www.youtube.com/watch?v=YTTdLgyqOLY&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=15&ab_channel=CodeHelp-byBabbar





bool ispossible(vector<int> arr, int n, int m,int mid){
        int stucnt=1;
        int pagecnt=0;
        for(int i=0;i<n;i++){
            if(pagecnt+arr[i]<=mid)
                pagecnt+=arr[i];
            else{
                stucnt++;
                if(stucnt>m||arr[i]>mid)
                    return false;
                pagecnt=arr[i];
            }
        }return true;
    }

int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.  
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int s=0;
    int e=sum;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ispossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
           }
    return ans;
}