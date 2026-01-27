/*Shortest Path in Undirected Graph
Difficulty: MediumAccuracy: 49.98%Submissions: 175K+Points: 4Average Time: 20m
You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertices u and v.

Your task is to find the shortest path distance from a given source vertex src to all other vertices in the graph.
If a vertex is not reachable from the source, return -1 for that vertex.


Note: All edges have unit weight (1).

Examples :

Input: V = 9, E = 10, 
edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]], src = 0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

Input: V = 4, E = 2,
edges[][]= [[0, 3], [1, 3]], src = 3
Output: [1, 1, -1, 0]

Constraints:
1 ≤ V ≤ 104
0 ≤ E ≤ V*(V-1)/2
0 ≤ edges[i][0], edges[i][1] < V  */

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        vector<vector<int>>adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V,-1);
        queue<int>q;

        dist[src] = 0;
        q.push(src);

        while(q.size()>0){
            int node = q.front();
            q.pop();

            for(auto v : adj[node]){
                if(dist[v] == -1){
                    dist[v] = dist[node] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};