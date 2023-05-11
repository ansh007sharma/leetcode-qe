# Problem - Solution:

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
  
Example 2:

Input: height = [1,1]
Output: 1
 
Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Solution:

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxi = 0;
        while(i<j)
        {
            int lh = height[i];
            int rh = height[j];
            int min_h = min(lh,rh);
            maxi = max(maxi,min_h*(j-i));
            if(lh<rh)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxi;
    }
};

