#Problem-Solution:

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
  
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6

------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Solution:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        vector<double> v;
        for(int i=0; i<n1.size(); i++){
            v.push_back(n1[i]);
        }
        for(int i=0; i<n2.size(); i++){
            v.push_back(n2[i]);
        }
        sort(v.begin(), v.end());
        int l=0, h=v.size()-1;
        int m = l+(h-l)/2;
        if(v.size()%2 == 0){
            return (v[m]+v[m+1])/2;
        }
        else return v[m];
    }
};

