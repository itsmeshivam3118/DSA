//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

//https://www.youtube.com/watch?v=zD2Jg3alZV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=13&ab_channel=CodeHelp-byBabbar

class Solution {
public:
        // Binary search approach
        int first_occurrence(vector<int>&nums, int target){
                int start=0;
                int end=nums.size()-1;
                int mid=start+(end-start)/2;
                int ans=-1;
                while(start<=end){
                        if(nums[mid]==target){
                                ans=mid;
                                end=mid-1;
                        }
                        else if(target>nums[mid]){
                                start=mid+1;
                        }
                        else
                                end=mid-1;
                        
                        mid=start+(end-start)/2;
                }
                return ans;
        }
        
           int last_occurrence(vector<int>&nums, int target){
                int start=0;
                int end=nums.size()-1;
                int mid=start+(end-start)/2;
                int ans=-1;
                while(start<=end){
                        if(nums[mid]==target){
                                ans=mid;
                                start=mid+1;
                        }
                        else if(target>nums[mid]){
                                start=mid+1;
                        }
                        else
                                end=mid-1;
                        
                        mid=start+(end-start)/2;
                }
                return ans;
        }
        
    vector<int> searchRange(vector<int> nums, int target) {
           
            vector<int>v;
            int f=first_occurrence(nums,target);
            int l=last_occurrence(nums,target);
            v.push_back(f);
            v.push_back(l);
            return v;
            
    }
};