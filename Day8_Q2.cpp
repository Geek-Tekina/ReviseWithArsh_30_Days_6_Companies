class Solution {
private : 
    vector<int> ans;
    bool checkProfit(vector<int>&bob,vector<int>& alice){
        int prevProfit = 0;
        for(int i=0;i<ans.size();i++){
            if(ans[i] > alice[i]) prevProfit += i;
        }

        int newProfit = 0;
        for(int i=0;i<bob.size();i++){
            if(bob[i] > alice[i]) newProfit += i;
        }

        return newProfit > prevProfit;
    }

    void helper(int i,int numArrows,vector<int>& alice,vector<int>&bob){
        if(i==0){
            bob[i] = numArrows;
            if(checkProfit(bob,alice)) ans = bob;
            bob[i] = 0;
            return;
        }
        if(numArrows - alice[i] - 1 >= 0){
            bob[i] = alice[i] + 1;
            helper(i-1,numArrows - alice[i] - 1,alice,bob);
            bob[i] = 0;
        }

        helper(i-1,numArrows,alice,bob);
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>bob(12,0);
        helper(11,numArrows,aliceArrows,bob);
        return ans;
    }
};