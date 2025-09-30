// Last updated: 10/1/2025, 12:47:58 AM
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {
                color[i]=0;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto edge : graph[node]) {

                        if (color[edge] == -1) {
                          
                            color[edge] = !color[node];
                            q.push(edge);
                        }

                        else if (color[edge] == color[node])
                            return false;
                    }
                }
            }
           
            
        }
         return true;
    }
    };