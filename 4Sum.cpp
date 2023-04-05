#Problem-Solution:-

Given an array nums of n integers, return an array of all the
unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
 
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

---------------------------------------------------------------------------------------------------------------------

#Solution:-

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end()); 
        set<vector<int>> ans;
        vector<vector<int>> v;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newtarget= (long long) target - nums[i]- nums[j];
                int s=j+1, e=n-1;
                while(s<e){
                    if(nums[s]+nums[e]<newtarget)
                        s++;
                    else if(nums[s] + nums[e]> newtarget)
                        e--;
                    else{
                        ans.insert({nums[i], nums[j], nums[s], nums[e]});
                        s++;
                        e--;
                    }
                }
            }
        }
        for(auto i: ans){
            v.push_back(i);
        }
        return v;
    }
};


