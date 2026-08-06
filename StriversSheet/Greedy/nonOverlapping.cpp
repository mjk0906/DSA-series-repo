class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> curr ;
        int ans = 0;
        sort(intervals.begin(),intervals.end(),[](const vector<int> a,const vector<int> b){
            return a[1] < b[1] ;
        });
        int lastend = intervals[0][1] ;
        for(int i=1;i<n;i++){
            curr=intervals[i] ;
            if(curr[0]<lastend){
                ans++ ;
            }else{
                lastend = curr[1] ;
            }
        }
        return ans ;
    }
};

// good problem