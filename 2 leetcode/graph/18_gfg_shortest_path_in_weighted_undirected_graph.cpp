/*Shortest Path in Weighted undirected graph
Difficulty: MediumAccuracy: 50.0%Submissions: 92K+Points: 4Average Time: 20m
You are given a weighted undirected graph with n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between vertex 1 and vertex n. Each edge is given as {a, b, w}, denoting an edge between vertices a and b with weight w.

If a path exists, return a list of integers where the first element is the total weight of the shortest path, and the remaining elements are the nodes along that path (from 1 to n). If no path exists, return a list containing only {-1}.

Note: The driver code will internally verify your returned list.

If both the path and its total weight are valid, only the total weight will be displayed as output.
If your list contains only -1, the output will be -1.
If the returned list is invalid, the output will be -2.
Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
Input: n = 2, m= 0, edges = [ ]
Output: -1
Explanation: Since there are no edges, so no answer is possible.
Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n+m)

Constraint:
2 <= n <= 106
0 <= m <= 106
1 <= a, b <= n
1 <= w <= 105*/


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e : edges){
            int u= e[0];
            int v= e[1];
            int wt= e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);

        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
        dist[1]=0;
        pq.push({0,1});

        while(pq.size()>0){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();

            for(auto &it : adj[node]){
                int v = it.first;
                int wt = it.second;

                if(dist[v]>dis + wt){
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                    parent[v]= node;
                }
            }
        }
        if(dist[n]==1e9){
            return {-1};
        }

        vector<int>path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        
        vector<int> result;
        result.push_back(dist[n]);
        for(int x : path) result.push_back(x);
        
        return result;
           

    }
};