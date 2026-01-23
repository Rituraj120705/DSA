/*Connected Components in an Undirected Graph
Difficulty: MediumAccuracy: 48.5%Submissions: 33K+Points: 4
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
Explanation:

Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: [[0, 1, 6], [2, 3, 4], [5]]
Explanation:

Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

*/



class Solution {
  public:
        void dfshelper(int u, vector<bool> &vis , vector<int> &component ,vector<vector<int>>& adj){
          vis[u]=true;
          component.push_back(u);

          for(int i: adj[u] ){
            if(!vis[i]){
              dfshelper(i,vis,component,adj);
            }
          }
        }






    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto &e : edges){
          adj[e[0]].push_back(e[1]);
          adj[e[1]].push_back(e[0]);

        }
        vector<bool> vis(V,false);
        vector<vector<int>> result;

        for(int i=0 ; i<V; i++){
            if(!vis[i]){
              vector<int>component;
              dfshelper(i,vis,component,adj);
              result.push_back(component);
            }
        }
        return result;
            
    }
};
