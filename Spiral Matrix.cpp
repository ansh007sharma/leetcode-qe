#Problem-Solution:-

Given an m x n matrix, return all elements of the matrix in spiral order.
  
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
#Solution:-
  
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count =0;
        int total=row *col;
        int strow = 0;
        int stcol= 0;
        int edrow = row-1;
        int edcol = col-1;
        while(count<total)
        {
            for(int index = stcol; count<total && index <=edcol;index++)
            {
                ans.push_back(matrix[strow][index]);
                count++;
            }
            strow++;
             for(int index = strow; count<total && index <=edrow;index++)
            {
                ans.push_back(matrix[index][edcol]);
                count++;
            }
            edcol--;
             for(int index = edcol; count<total && index >=stcol;index--)
            {
                ans.push_back(matrix[edrow][index]);
                count++;
            }
            edrow--;
             for(int index = edrow; count<total && index >=strow;index--)
            {
                ans.push_back(matrix[index][stcol]);
                count++;
            }
            stcol++;
        }
        return ans;
    }
};


