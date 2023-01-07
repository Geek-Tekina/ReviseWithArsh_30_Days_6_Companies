int minimumCardPickup(vector<int>& cards) {
    unordered_map<int,vector<int>>mp;
    
    for(int i=0;i<cards.size();i++)
    {
        mp[cards[i]].push_back(i);
    }
    
    int ans=INT_MAX;
    
    for(auto x:mp)
    {
        vector<int>v=x.second;
        
        if(v.size()>1)
        {
            for(int i=0;i<v.size()-1;i++)
            {
                ans=min(ans,v[i+1]-v[i]+1);               
            }
        }
    }
    
    if(ans==INT_MAX)
        return -1;
    
    return ans;
    
}