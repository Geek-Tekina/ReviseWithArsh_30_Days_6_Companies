class Solution {
public:
    string binary(int n)
    {
        string s = "";
        while(n>0)
        {
            int a = n%2;
            s+=to_string(a);
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int dp[32][2][2];
    int rec(string &num,int n,bool tight,bool one)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][tight][one]!=-1)
        {
            return dp[n][tight][one];
        }
        int ans=0;
        int ub = (tight)?num[num.size()-n]-'0':1;
        for(int dig=0;dig<=ub;dig++)
        {
            if(one and dig==1)
            {
                continue;
            }
            else if(one and dig==0)
            {
                ans+=rec(num,n-1,tight&(dig==ub),0);
            }else if(!one and dig==1)
            {
               ans+=rec(num,n-1,tight&(dig==ub),1);
            }else
            {
                ans+=rec(num,n-1,tight&(dig==ub),0);
            }
        }
        return dp[n][tight][one]=ans;
    }
    int findIntegers(int n) {
        string num = binary(n);
        memset(dp,-1,sizeof(dp));
        return rec(num,num.size(),1,0);
    }
};