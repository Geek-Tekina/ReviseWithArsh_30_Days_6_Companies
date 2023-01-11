class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long A = numerator; 
        long long B = denominator; 
        if(A==0) return "0";
        int neg = 1;
        if(A<0) {neg*=-1; A=abs(A);}
        if(B<0) {neg*=-1; B=abs(B);}
        string ans = "";
        if(neg<0) ans+='-';
        ans+=to_string(A/B);
        if(A%B==0) return ans;
        else ans+='.';
        unordered_map<int,int> mp;
        long long C = A%B;
        while(C!=0 && mp.find(C)==mp.end()){
            mp[C]=ans.size();
            ans.push_back('0'+(C*10)/B);
            C=C*10%B;
        }
        if(C==0) return ans;
        ans.insert(ans.begin()+mp[C],'(');
        ans.push_back(')');
        return ans;
    }
};