class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false ;
        vector<int> mapST (128,-1) ;
        vector<int> mapTS (128,-1) ;
        for(int i=0;i<s.size();i++){
            if(mapST[s[i]]==-1 && mapTS[t[i]]==-1){
                mapST[s[i]]=t[i] ;
                mapTS[t[i]]=s[i] ;
            }else if(mapST[s[i]]!=t[i] || mapTS[t[i]]!=s[i]){
                return false ;
            }
        }
        return true ;
    }
};
//important problem, the logic of using ascii values in a problem like this where we need indexing for 2 simultaneous arrays
//basically here when we are mapping elements or chars we are using ascii values because it is easier to map and keep a track insead of using a map to do so
//ascii importance

//this code is for using unordered maps, will use extra spacenO(n) SC 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for(int i = 0; i < s.size(); i++) {

            if(mapST.find(s[i]) == mapST.end() &&
               mapTS.find(t[i]) == mapTS.end()) {

                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            }

            else if(mapST[s[i]] != t[i] || mapTS[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};