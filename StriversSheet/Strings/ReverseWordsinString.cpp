class Solution {
public:
    string reverseWords(string s) {
        vector<string> words ;
        string word ;
        for(char ch : s){
            if(ch != ' '){
                word+=ch ;
            }
            else{
                if(!word.empty()){
                    words.push_back(word) ;
                    word.clear() ;
                }
            }
        }
        if(!word.empty()){
            words.push_back(word) ;
        }

        reverse(words.begin(),words.end()); //how can you forget this dont just learn the code,enjoy coding

        string ans ;
        for(int i=0;i<words.size();i++){
            if(i>0){
                ans += " " ;
            }
            ans += words[i] ;
        }
        return ans ;
    }
};

//good approach