class Solution {
    //function is use to find the distance between the points
    // We are not taking square root, its distance square. So, there is no rounding required. All values are integers.
    int get_length(vector<int>& a, vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> sides = {
            //in case of sq only six points is applicable 
            //if p1p2p3p4 exists 
            //p1 can shake hands only with p2p3p4
            //p2 with p3p4
            //p3 with p4 
            
            get_length(p1, p2),
            get_length(p1, p3),
            get_length(p1, p4),
            get_length(p2, p3),
            get_length(p2, p4),
            get_length(p3, p4),
        };
        //map will hold the value of distance and it's times 
        unordered_map<int, int> m;
        for(auto& s: sides){
            if(!m.count(s))
                m.insert({s, 1});
            else m[s]++;
        }
        
        return !m.count(0) && m.size() == 2;
        // if(m.size() != 2) return false;
        // for(auto& p: m) return (p.second == 4) || (p.second == 2);
        // return false;
    }
};