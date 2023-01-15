class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1;
        int ind1=-1,ind2=-1;//ind1->first unmatching,ind2->last unmatching
        for(int x:nums)
            nums1.push_back(x);
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=nums1[i])
            {
                ind1=i;
                break;
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            if(nums1[j]!=nums[j])
            {
                ind2=j;
                break;
            }
        }
        if(ind1==-1 or ind2==-1)//condition if array is sorted
            return 0;
        return ind2-ind1+1;//else returning length of window
    }
};