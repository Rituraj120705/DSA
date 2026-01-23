/*130. Surrounded Regions
Solved
Medium
Topics
premium lock icon
Companies
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.*/



class Solution {
public:

    void dfshelper(int u, int v, vector<vector<char>> &board, vector<vector<bool>> &vis){
        int n= board.size();
        int m= board[0].size();

        vis[u][v]=true;

        int dx[]= {-1,1,0,0};
        int dy[]= {0,0,-1,1};

        for(int d=0; d<4; d++){
            int nrow= u + dx[d];
            int ncol= v + dy[d];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfshelper(nrow,ncol,board,vis);
            }
        }
    }



    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                 dfshelper(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                 dfshelper(i,m-1,board,vis);
            }
        }

        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && !vis[0][j]){
                 dfshelper(0,j,board,vis);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                 dfshelper(n-1,j,board,vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    
    }
};