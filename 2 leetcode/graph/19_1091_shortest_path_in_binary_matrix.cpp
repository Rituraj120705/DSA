/*1091. Shortest Path in Binary Matrix
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1*/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
         
        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return -1;
        }

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        q.push({1,{0,0}});
        dist[0][0]=1;

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(q.size()>0){
            auto it = q.front();
            q.pop();

            int dis= it.first;
            int r= it.second.first;
            int c= it.second.second;

            for(int i =0; i<8; i++){
                int newr= r + dr[i];
                int newc= c + dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && dis + 1 < dist[newr][newc] ){
                    dist[newr][newc] = 1 + dis;
                    
                    q.push({1+dis, {newr,newc}});
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];
    }
};