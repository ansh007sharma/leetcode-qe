Problem-Solution:-
  
You are given an integer array nums. You are initially positioned at the arrays first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Solution:-
  
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> maxJump(nums.size(),0);
        maxJump[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(maxJump[i-1] < i) return false;
            maxJump[i] = max(maxJump[i-1],nums[i]+i);
        }
        return true;
    }
};

