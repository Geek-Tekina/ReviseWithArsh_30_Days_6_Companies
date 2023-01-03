class Solution {
public:
    vector<int> adj[100007];
    bool vis[100007];
    int ans;
    int cur;
//dfs to find path between alice and bob
    void dfs(int x, int bob,vector<int> &v,vector<int> &path){
        v.push_back(x);
        
        if(!vis[x]&&x==bob){
            path = v;
            return;
        }
        vis[x]=1;
        for(auto y:adj[x]){
            if(!vis[y]){
                dfs(y,bob,v,path);
            }
        }
        v.pop_back();
        
    }

// dfs to find the max valued path
    void dfs_max(int x, vector<int>& a){
        vis[x]=1;
        cur += a[x];
        for(auto y:adj[x]){
            if(!vis[y]){
                dfs_max(y,a);
            }
        }
        if(x&&adj[x].size()==1) // if x is a leaf node update answer
        ans = max(ans,cur);
        cur-=a[x];
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        for(int i =0;i<n;i++) vis[i]=0;
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> v;
         vector<int>path;
        dfs(0,bob,v,path);
        int ps = path.size();
        int st;
        if(ps&1){
            amount[path[ps/2]]/=2;
            st = ps/2+1;
        }else{
            st = ps/2;
        }
        for(auto x: path) cout<<x<<" ";
        for(int i =st;i<ps;i++){
            amount[path[i]]=0;
        }
        for(int i =0;i<n;i++) vis[i] = 0;
        ans  = INT_MIN;
        cur =0;
        dfs_max(0, amount);
        return ans;
    }
};