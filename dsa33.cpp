class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size() ;
        int idx = 0 ;
        for (int i=0;i<n;i++){
            int count = 0 ;
            char ch = chars[i];
            while(i<n && ch == chars[i]){
                count++ ; i++ ;
            }
            if (count == 1){
                chars[idx++] = ch ;
            }
            else{
                chars[idx++] = ch ;
                string str = to_string(count) ;
                for (char x : str){
                    chars[idx++] = x ;
                }
            }
            i-- ;
        }
        chars.resize(idx) ; //the last time it will ++ so we have to keep the idx value only not the idx+1 inside the bracket
        return idx ;
    }
}:

// this is code of problem 443 on leetcode (string compression)

c