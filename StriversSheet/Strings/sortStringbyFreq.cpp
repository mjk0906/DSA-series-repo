class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp ;
        for(auto x : s){
            mp[x]++ ;
        }
        priority_queue<pair<int,char>> pq ;
        for(auto x : mp){
            pq.push({x.second,x.first}) ;
        }
        string ans = "" ;
        while(!pq.empty()){
            auto x = pq.top() ;
            pq.pop();
            char c = x.second;
            int freq = x.first ;
            ans += string(freq,c) ;
        }
        return ans ;
    }
};
//important question