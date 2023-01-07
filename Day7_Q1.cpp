class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(); 
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int x = points[i][0];
            int y = points[i][1];
            for(int j=0;j<n;j++){
                if(j == i) continue;
                mp[(points[j][0]-x)*(points[j][0]-x) + (points[j][1]-y)*(points[j][1]-y)]++;
            }
            for(auto it : mp){
                ans += it.second*(it.second-1);
            }
        }
        return ans;
    }
};