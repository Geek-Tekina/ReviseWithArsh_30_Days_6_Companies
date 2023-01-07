class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int& n: nums) {
            freq[n]++;
        }
        unordered_map<int, int> tail;
        for (int& n: nums) {
            if (freq[n] == 0) {
                continue;
            }
            if (tail[n - 1] > 0) {
                tail[n - 1]--;
                tail[n]++;
            } else if (freq[n + 1] > 0 && freq[n + 2] > 0) {                
                freq[n + 1]--;
                freq[n + 2]--;
                tail[n + 2]++;
            } else {
                return false;
            }
            freq[n]--;
        }
        return true;
    }
};