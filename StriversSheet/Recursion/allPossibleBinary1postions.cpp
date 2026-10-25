#include <iostream>
#include <vector> 
#include <string>
using namespace std;

void rec(int idx,string&s,vector<string>&ans){
    if(idx>=s.size()){ //finally after traversing the whole include it in the ans
        ans.push_back(s) ;
        return ;
    }
    //keep the current one as 0 and move to next index
    s[idx] = '0' ;
    rec(idx+1,s,ans) ;
    //now change curr to 1(avoid consecutive ones)
    s[idx] = '1' ;
    rec(idx+2,s,ans) ;

    //make the curr 0 for the next iteration
    s[idx] = '0' ;
}
vector<string> generateCombins(int n){
    string s(n,'0') ;
    vector<string> ans ;
    rec(0,s,ans) ;
    return ans ;
}

int main(){
    vector<string> ans = generateCombins(4) ;
    for(auto curr : ans){
        cout<< curr << endl ;
    }
    return 0 ;
}