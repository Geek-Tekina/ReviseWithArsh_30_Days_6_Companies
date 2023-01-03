class Solution {
private:
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Edge case
        if(edges.size() == 0) return true;
        // Create Adj_list for directed graph
        unordered_map<int, vector<int>>adj_list;
        for(auto i: edges){
            adj_list[i[0]].push_back(i[1]);
        }
        // Step 1: Find indegree of all nodes
        vector<int>indegree(n);
        for(auto i: adj_list){
            for(auto j: i.second){
                indegree[j]++;
            }
        }
        // Step 2: Push element with 0 ingree in queue
        queue<int>q;
        for(int i = 0; i < indegree.size() ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // Step 3: Do BFS
        int cnt =0;
        while(!q.empty()){
            // Remove and store front
            int front = q.front();
            q.pop();
            cnt++;
            // Find all neightbours of front
            for(auto neighbour: adj_list[front]){
                // As front have been removed update their indegree
                indegree[neighbour] -= 1;
                // Push the neighbours with indegree 0 in queue
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        // if(cnt == n) => cycle not present
        // else cycle present
        return cnt == n;
    }
};