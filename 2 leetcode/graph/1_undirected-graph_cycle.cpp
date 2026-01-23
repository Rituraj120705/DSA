/*Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 679K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

*/




class Solution {
  public:
    bool dfshelper(int u , int parent, vector<vector<int>> &adj, vector<bool> &vis ){
        vis[u]=true;

        for(int i : adj[u]){
            if(!vis[i]){
                 if(dfshelper(i,u,adj,vis)){
                return true;
                 }
            }
            else{
                if(i!=parent){
                    return true;
                }
            }
        }
        return false;
    }


    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfshelper(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
        
        
    }
};