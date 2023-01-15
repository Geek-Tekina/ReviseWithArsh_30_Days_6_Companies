class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q: queries){
            int trim= q[1];
            int k= q[0];
            priority_queue<pair<string,int>> pq;
            for (int i=0; i<nums.size(); i++){
                string  val= nums[i];
                if (trim< nums[i].size()) val= nums[i].substr(nums[i].size()-trim,trim);

                pair<string,int> val1= {val,i};
                if (pq.size()<k){
                    pq.push(val1);
                }
                else{
                    if (val1 < pq.top()){
                        pq.pop();
                        pq.push(val1);
                    }
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};