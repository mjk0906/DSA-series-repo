class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false ;
        }
        string temp = s+s ;
        return temp.find(goal) != string::npos ;
    }
};
//important thing, the npos thing , npos means that the required or desired thing is not found in the array, it is like map.end()
