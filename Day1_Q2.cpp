class Solution {
    vector<vector<int>>ans;
    void solve(int k,int val,int n,vector<int>&ds){
        if(val>9 || k<0 || n<0)return;
         
        if(!k && !n){
            ans.push_back(ds);
            return;
        } 

        ds.push_back(val+1);
        solve(k-1,val+1,n-val-1,ds);
        ds.pop_back();
        solve(k,val+1,n,ds);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        solve(k,0,n,ds);
        return ans;
    }
};