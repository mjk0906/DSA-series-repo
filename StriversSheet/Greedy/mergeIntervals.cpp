class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> curr ;
        vector<int> merged ;
        vector<vector<int>> ans ;
        sort(intervals.begin(),intervals.end(),[](const vector<int> a,const vector<int> b){
            return a[0] < b[0] ;
        });
        merged = intervals[0] ;
        for(int i=1;i<n;i++){
            curr=intervals[i] ;
            if(merged[1]>=curr[0]){
                merged[1] = max(merged[1],curr[1]);
            }else{
                ans.push_back(merged) ;
                merged = intervals[i] ;
            }
        }
        ans.push_back(merged) ; //this would be the last merged interval int the array
        return ans ;
    }
};
//whole intuition was own and good problem
//here we sort based on the starting points as we want to see overlapping which is done through starting point only