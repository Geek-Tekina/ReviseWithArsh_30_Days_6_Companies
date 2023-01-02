class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n+1,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] ==0 || nums[j]%nums[i]==0){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans = *max_element(dp.begin(),dp.end());
        int idx = -1;
        for(int i=0; i<n; i++){
            if(dp[i]==ans){
                idx = i;
                break;
            }
        }
        vector<int> res;
        int temp = nums[idx];
        int prev = idx;
        for(int i=idx; i>=0; i--){
            if(nums[prev]%nums[i]==0 && dp[i]+res.size()==ans){
                res.push_back(nums[i]);
                prev = i;
            }
        }
        return res;


    }
};