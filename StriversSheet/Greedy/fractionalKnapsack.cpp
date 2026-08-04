class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,int>> items ;
        double ans = 0;
        for(int i=0;i<val.size();i++){
            double ratio = (double)val[i]/wt[i] ; 
            items.push_back({ratio,i}) ;
        }
        
        sort(items.begin(),items.end(),greater<pair<double,int>>());
        for(auto item : items){
            int idx = item.second ;
            double ratio = item.first ;
            if(wt[idx]<=capacity){
                ans+=val[idx] ;
                capacity-=wt[idx] ;
            }else{
                ans+= capacity*ratio ;
                break ;
            }
        }
        return ans ;
    }
};

//a very good problem to clearly understand greedy