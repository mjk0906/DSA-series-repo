class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedArray ;
        int n = intervals.size() ;
        int i = 0 ;
        //push before newInterval
        while(i<n && intervals[i][1]<newInterval[0]){
            mergedArray.push_back(intervals[i]);
            i++;
        }
        //push overlaps with newInterval
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        mergedArray.push_back(newInterval) ;
        //push past the newInterval 
        while(i<n){
            mergedArray.push_back(intervals[i]) ;
            i++ ;
        }
        return mergedArray ;
    }
};

// tc of this would be O(n) 
//this became easy because the array was sorted already, so if it wasnt we have to sort it again