Problem-Solution:-
  
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that 
exactly one of the tilings has both squares occupied by a tile.

Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 1000
  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Solution:-
 
class Solution {
    private static final int MOD = 1000000007;
    public int numTilings(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;
        long[] dp = new long[N + 1];
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= N; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
        }
        return (int) dp[N];
    }
}

