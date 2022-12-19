Problem-Solution:-
  
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false

Constraints:
-2^31 <= n <= 2^31 - 1
Follow up: Could you solve it without loops/recursion?

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Solution:-
  
 class Solution {
public:
    bool isPowerOfTwo(int n) {
           return n>0 && (n& (n-1))==0;
    }
};

Explaination:-
if any number power of 2 then it's form is 00...100.. for example binary representation of 4 is 100 and 8 is 1000 and if we take "and" operation with 
it's previous number like in case of 4 , 3 is previous number so binary of 3 is 011 and as we know binary of 4 is 100 so if we take 'and' operation of
both then it will come to 0 in each case so if n is number which is power of 2 so n&(n-1)=0;

