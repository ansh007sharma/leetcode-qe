Problem-Solution:-
  
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes. 

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

Example 2:
Input: n = 1, edges = []
Output: [0]

Example 3:
Input: n = 2, edges = [[1,0]]
Output: [1,1]

Constraints:
1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.
  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Solution:-
  
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>>g(N, vector<int>());
        for(auto& e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int>res(N), child(N), visited(N);
        dfs(g, res, child, 0, 0, visited);
        for(auto& x: visited) x = 0;
        dfs(g, res, child, 0, visited, N);
        return res;
    }
    // Sum of the distances of node 0
    void dfs(vector<vector<int>>& g, vector<int>& res, vector<int>& child, int len, int root, vector<int>& visited){
        visited[root] = 1;
        res[0] += len++;
        for(auto& x: g[root]){
            if(visited[x]) continue;
            dfs(g, res, child, len, x, visited);
            child[root] += child[x];
        }
        child[root] += 1;
    }
    // Sum of the distances of node 1 to N - 1
    void dfs(vector<vector<int>>& g, vector<int>& res, vector<int>& child, int root, vector<int>& visited, int N){
        visited[root] = 1;
        for(auto& x: g[root]){
            if(visited[x]) continue;
            res[x] = res[root] - child[x] + N - child[x];
            dfs(g, res, child, x, visited, N);
        }
    }
};

Explaination:-
  
We can regard this tree as a rooted tree.
For each node, if we can get the sum of distance to it's child node (son_dist), and to it's father node (fa_dist). And sum them up, then we have our answer.
ans = son_dist + fa_dist.
The method to calculate son_dist and fa_dist: O(n)

By using dfs one time, we can calculate son_dist.
By using dfs the second time, we can calculate fa_dist based on the information we get in first step.
Sum them up, for each node, ans = son_dist + fa_dist.
The details of getting son_dist and fa_dist needs a bit careful thinking, I suggest you figuring it out on your own. Anyway, I provide my solution below,
I hope it helps!

