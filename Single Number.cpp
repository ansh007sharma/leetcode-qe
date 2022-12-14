#Problem-Solution:-
  
->Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

*Example 1:
Input: nums = [2,2,1]
Output: 1

*Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

*Example 3:
Input: nums = [1]
Output: 1
 
Constraints:
1 <= nums.length <= 3 * 10^4
-3 * 104 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
#Solution:-
  
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>hash;
for(int i=0;i<nums.size();i++)
{
hash[nums[i]]++;
}
int ans=0;
map<int,int>::iterator i;
for(i=hash.begin();i!=hash.end();i++)
{
if(i->second==1)
{
ans=i->first;
}
}
return ans;
}
};

