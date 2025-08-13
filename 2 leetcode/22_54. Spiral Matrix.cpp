/*54. Spiral Matrix
Solved
Medium
Topics
Companies
Hint





Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/


class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
                
            int srow =0 ,scol=0;
            int n=matrix[0].size();
            int m=matrix.size();
            int erow =m-1,ecol=n-1;
            
    
            while(srow<=erow && scol<=ecol){
    
                for(int j= scol; j<=ecol;j++){
                    //cout<<matrix[srow][j]<<" ";
                    ans.push_back(matrix[srow][j]);
                }
    
                for(int i= srow+1; i<=erow;i++){
                   // cout<<matrix[i][ecol]<<" ";
                   ans.push_back(matrix[i][ecol]);
                }
    
                for(int j= ecol-1; j>=scol;j--){
                    if(srow==erow){
                        break;
                    }
                    //cout<<matrix[erow][j]<<" ";
                    ans.push_back(matrix[erow][j]);
                }
                
                for(int i= erow-1; i>=srow+1;i--){
                    if(scol==ecol){
                        break;
                    }
                    
                    //cout<<matrix[i][scol]<<" ";
                    ans.push_back(matrix[i][scol]);
                }
                
                srow++,scol++;
                erow--,ecol--;
    
            }
            cout<<endl;
           return ans; 
            
        }
    };
    