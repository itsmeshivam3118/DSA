//https://leetcode.com/problems/subsets/

//https://www.youtube.com/watch?v=Yg5a2FxU4Fo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=12&ab_channel=AdityaVerma


class Solution {
public:
         vector<vector<int>>nums2;
        vector<int>nums1;
       void prntsbst(int ind,vector<int>&nums)
        {
               
               
                if(ind==nums.size())
                {
                nums2.push_back(nums1);
                      return;
                }
                nums1.push_back(nums[ind]);
                prntsbst(ind+1,nums);
                nums1.pop_back();
                prntsbst(ind+1,nums);
                        
        }
        
    vector<vector<int>> subsets(vector<int>& nums) {
            
            prntsbst(0,nums);
                    return nums2;
    }
};