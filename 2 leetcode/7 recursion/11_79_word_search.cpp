
/*79. Word Search


Solved
Medium
Topics
premium lock icon
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 */



class Solution {
public:

    bool backtrack(int i, int j, int index,vector<vector<char>>& board,string word,vector<vector<bool>>& visited){
        if(index == word.size()){
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        
        if(i>=m || j>=n || i<0 || j<0 || visited[i][j]|| board[i][j]!=word[index]){
            return false;
        }
        
        visited[i][j] = true;

        bool found = backtrack(i+1,j,index+1,board,word,visited) || backtrack(i-1,j,index+1,board,word,visited) || backtrack(i,j+1,index+1,board,word,visited) || backtrack(i,j-1,index+1,board,word,visited);

        visited[i][j] = false;

        return found;

    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(backtrack(i,j,0,board,word,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};