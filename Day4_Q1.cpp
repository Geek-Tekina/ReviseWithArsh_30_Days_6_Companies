class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortNums;
        sortNums = nums;
        bool flag = true;
        int start=0, end=0;
        sort(sortNums.begin(), sortNums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != sortNums[i]){
                if(flag){
                    start = i;
                    flag = false;
                }else{
                    end = i;
                }
            }
        }
        if(start==end) return 0;
        return end-start+1;
    }
};