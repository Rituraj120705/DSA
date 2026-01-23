/*547. Number of Provinces
Solved
Medium
Topics
premium lock icon
Companies
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]*/



class Solution {
public:
        void dfs(int u , vector<bool>& vis, vector<vector<int>>& isConnected) {
    vis[u] = true;
    for(int v = 0; v < isConnected.size(); v++) {
        if( isConnected[u][v]==1 && !vis[v]){
            dfs(v, vis, isConnected);
        }
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<bool> vis(v, false);
        int count = 0;    
        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                count++;
               
            }
        }
        return count;
        
    }
};
































class Solution {
public:

    void dfs(int u , vector<bool> &vis, vector<vector<int>> &isConnected){
        vis[u]=true;
        for(int v=0; v<isConnected.size(); v++){
            if(isConnected[u][v]==1 && !vis[v]){
                dfs(v,vis,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<bool>vis(v,false);
        int count=0;

        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};