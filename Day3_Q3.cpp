class Solution {
public:
    #define ll long long

    ll merge(vector<ll>&container,vector<ll>&temp,ll start,ll mid,ll high,int &diff){
        ll i=start,j=mid,k,count=0;
        while(i<mid && j<=high){
            if(container[j]+diff>=container[i]){
                count+=(high-j+1);
                i++;
            }
            else{
                j++;
            }
        }
        i=start;j=mid,k=start;
        while(i<mid && j<=high){
            if(container[i]<=container[j]){
                temp[k++]=container[i++];
            }
            else{
                temp[k++]=container[j++];
            }
        }
        while(i<mid){
            temp[k++]=container[i++];
        }
        while(j<=high){
            temp[k++]=container[j++];
        }
        for(ll i=start;i<=high;i++){
            container[i]=temp[i];
        }
        return count;
    }

    ll solve(vector<ll>&container,vector<ll>&temp,ll start,ll end,int &diff){
        ll answer=0,mid;
        if(end>start){
            mid=(start+end)>>1;
            answer+=solve(container,temp,start,mid,diff);
            answer+=solve(container,temp,mid+1,end,diff);
            answer+=merge(container,temp,start,mid+1,end,diff);
        }
        return answer;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ll n=nums1.size();
        vector<ll>container(n,0),temp(n,0);
        for(ll i=0;i<n;i++){
            container[i]=nums1[i]-nums2[i];
        }
        return solve(container,temp,0,n-1,diff);
    }
};