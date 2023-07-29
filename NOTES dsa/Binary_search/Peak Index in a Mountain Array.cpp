//https://leetcode.com/problems/peak-index-in-a-mountain-array/

//https://www.youtube.com/watch?v=zD2Jg3alZV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=13&t=2096s&ab_channel=CodeHelp-byBabbar

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0, e=arr.size()-1, m=s+(e-s)/2;
        while(s<e){
            if(arr[m]<arr[m+1]){
                s=m+1;
            }
            else{
                e=m;
            }
            m=s+(e-s)/2;
        }
        return s;
    }
};