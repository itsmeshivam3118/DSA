//https://leetcode.com/problems/permutations/

//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

//https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13&ab_channel=takeUforward

class Solution {
public:
        
        void solve(int ind,vector<int>& nums,vector<vector<int>>&ans){
                if(ind==nums.size()){
                        ans.push_back(nums);
                        return;
                }
                for(int i=ind;i<nums.size();i++){
                        swap(nums[ind],nums[i]);
                        solve(ind+1,nums,ans);
                        swap(nums[i],nums[ind]);
                }
        }
        
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
            solve(0,nums,ans);
                    return ans;
    }
};