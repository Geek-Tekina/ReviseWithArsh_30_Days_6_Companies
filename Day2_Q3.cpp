#define mod 1000000007
#define ll long long

class Solution {
public:
    
    void dfs(unordered_map<ll,ll>& mp, vector<vector<int>>& rectangles, int idx, vector<bool>& visited){
        visited[idx]=1;
        
        ll key1= (ll)(1000000LL*rectangles[idx][2])+rectangles[idx][1];
        ll key2= (ll)(1000000LL*rectangles[idx][0])+rectangles[idx][3];
        
        if(mp.count(key1)){
            if(!visited[mp[key1]]) dfs(mp,rectangles,mp[key1],visited);
        }
        
        if(mp.count(key2)){
            if(!visited[mp[key2]]) dfs(mp,rectangles,mp[key2],visited);
        }
                                                                            
    }
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // section 1:
        // identify the boundary
        int bmax=INT_MIN;
        int amax=INT_MIN;
        int xmin=INT_MAX;
        int ymin=INT_MAX;
        
        for(auto it: rectangles){
            xmin= min(xmin,it[0]);
            ymin= min(ymin,it[1]);
            amax= max(amax,it[2]);
            bmax= max(bmax,it[3]);
        }
         
        // section 2;
        // check for possible fitting of all rectangle
        ll actualArea= ((ll)(amax-xmin)*(bmax-ymin))%mod;
        
        ll curArea=0LL;
        
        for(auto it: rectangles){
            ll rect= (ll)(it[2]-it[0])*(it[3]-it[1]);
            curArea= (curArea+rect)%mod;
        }   
                
        if(curArea!=actualArea) return false;
        
        // section 3:
        // check whether all the rectangles are connected (non-overlapping or discrete)
        int n= rectangles.size();
        
        vector<bool> visited(n,0);
        
        int startIdx=-1;
        
        for(int i=0;i<n;i++){
            if(rectangles[i][2]==amax && rectangles[i][3]==bmax){
                startIdx=i;
                break;
            }
        }
        
        if(startIdx==-1) return false; // if top-right corner is not present of the covered rectangle
        
        unordered_map<ll,ll> mp;
        
        for(int i=0;i<n;i++){
            // hashing the top-right corner of each rectangle to its index
            // it will provide unique hashing since each element goes upto 10^5
            ll key = (ll)(1000000LL*rectangles[i][2])+rectangles[i][3];
            mp[key]=i;
        }
        
        dfs(mp,rectangles,startIdx,visited);
        
        //check for overlap or unreachable rectangle
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        
        return true;
    }
};