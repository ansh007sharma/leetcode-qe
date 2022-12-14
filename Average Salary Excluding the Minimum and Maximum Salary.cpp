# Problem-Solution:-

You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

*Example 1:

>Input: salary = [4000,3000,1000,2000]
>Output: 2500.00000
>Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
  
*Example 2:

>Input: salary = [1000,2000,3000]
>Output: 2000.00000
>Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 
*Constraints:

3 <= salary.length <= 100
1000 <= salary[i] <= 106
All the integers of salary are unique.
  
  
-> Solution:-
  
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
       double sum1=0, avg=0,sum=0;
        int count =0,nc= 0, n = salary.size();
        for(int i = 0;i<n;i++)
        {
            sum1 = sum1+salary[i];
            count++;
        }
        nc = count -2;
      if(n<4){
        sum = sum1 - (salary[0]+salary[n-1]);
        avg = sum;
        }
        else{
        sum = sum1 -(salary[0]+salary[n-1]);
        avg = sum/nc;}
        return avg ;
    }
};
