/*Directed Graph Cycle
Difficulty: MediumAccuracy: 27.88%Submissions: 554K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]



Output: true
Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]


Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V ≤ 105
0 ≤ E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V*/


class Solution {
  public:

    bool dfshelper(int u, vector<bool> &vis,vector<bool> &recpath, vector<vector<int>> &adj){
        vis[u] = true;
        recpath[u]= true;

        for(int i : adj[u]){
            if(!vis[i]){
                if(dfshelper(i,vis, recpath,adj)){
                    return true;
                }
            }
            else if(recpath[i]){
                    return true;
                }
            

        }
        recpath[u]=false;
        return false;
    }



    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj{V};
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(V,false);
        vector<bool> recpath(V,false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfshelper(i,vis,recpath,adj)){
                    return true;
                }
            }
        }
        return false;
        
    }
};