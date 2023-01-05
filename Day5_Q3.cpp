class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3]={};
        int start=0, end=0, total=0;
        int n = s.size();
        while(end < n) {
            freq[s[end]-'a']++;
            while(freq[0] && freq[1] && freq[2]) {
                total += n - end;
                freq[s[start]-'a']--;
                start++;
            }
            end++;
        }
        return total;
    }
};