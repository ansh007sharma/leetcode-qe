#Problem-Solution:-

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the 
number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:
->1 <= temperatures.length <= 10^5
->30 <= temperatures[i] <= 100
  
  
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
#Solution:-
  
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> p_stk;
        vector<int> results(temperatures.size(), 0);
        for(int i = 0; i< temperatures.size(); ++i) {
            while(!p_stk.empty() && temperatures[i] > p_stk.top().second) {
                results[p_stk.top().first] = i - p_stk.top().first;
                p_stk.pop();
            }
            p_stk.push(make_pair(i, temperatures[i]));
        }
        return results;
    } 
    
};

