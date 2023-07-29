//https://leetcode.com/problems/combination-sum/

//https://takeuforward.org/data-structure/combination-sum-1/

//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8&t=161s&ab_channel=takeUforward


class Solution {
public:
        void solve(int ind,vector<int>& candidates,int target,vector<int>&nums1,vector<vector<int>>&ans){
                if(ind==candidates.size()){
                        if(target==0){
                                ans.push_back(nums1);
                        }
                                return;
                }
                if(candidates[ind]<=target){
                        nums1.push_back(candidates[ind]);
                        solve(ind,candidates,target-candidates[ind],nums1,ans);
                        nums1.pop_back();
                }
                solve(ind+1,candidates,target,nums1,ans);
        }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>>ans;
            vector<int>nums1;
            solve(0,candidates,target,nums1,ans);
            return ans;
    }
};