class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        vector<int> arr(n,0);
        int lastind=n-1;
        int sum=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
          sum+=nums[i];
          curr+=i*nums[i];
        }
        arr[0]=curr;
        maxi=max(arr[0],maxi);
        for(int i=1;i<n;i++)
        {
            arr[i]=arr[i-1]+sum-(n*nums[lastind]);
            maxi=max(maxi,arr[i]);
            lastind--;
        }
        return maxi;
    }
}