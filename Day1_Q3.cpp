class Solution {
public:
   string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> numbers(10, 0);

        for(int i = 0; i < secret.size(); i++){
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if(s == g){
                bulls++;
            }
            else{
                // so g or s must be previously encounterd
                // if s is previous encounterd in guess then it must be marked or decremented by 1 so numbers[s] < 0
                if(numbers[s] < 0) cows++;
                if(numbers[g] > 0) cows++;
                // marking for new numbers
                numbers[s]++;
                numbers[g]--;
            }
        }
        return to_string(bulls)+ "A" + to_string(cows) +"B";
    }
};