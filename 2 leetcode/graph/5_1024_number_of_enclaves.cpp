/*1020. Number of Enclaves
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.*/



class Solution {
public:

    void dfshelper(int u, int v, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[u][v]=true;

        int dx[]= {-1,1,0,0};
        int dy[]= {0,0,-1,1};

        for(int d=0; d<4; d++){
            int nrow= u + dx[d];
            int ncol= v + dy[d];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfshelper(nrow,ncol,grid,vis);
            }
        }
    }




    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            if (grid[i][0]==1 && !vis[i][0]){
                dfshelper(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfshelper(i,m-1,grid,vis);
            }
        }

        for(int j=0; j<m; j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfshelper(0,j,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfshelper(n-1,j,grid,vis);
            }
        }

        int moves=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            if(grid[i][j]==1 && !vis[i][j]){
                moves++;
            }
        }
        }
        return moves;
    }
};