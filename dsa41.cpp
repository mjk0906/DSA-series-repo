class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        int count = 0 ;
        vector<int> prefixSum(n,0);
        prefixSum[0]=nums[0] ;

        for (int i=1 ; i<n ;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i] ;
        }
        unordered_map<int,int> m ; //one is value of the prefix sum and another is the value of frequency of that prefix sum occuring 
        for(int j=0 ; j<n ; j++){
            if (prefixSum[j]==k){ //if 
                count ++ ;
            }
            int x = prefixSum[j]-k ;
            if(m.find(x)!=m.end()){
                count+=m[x] ;
            }
            if(m.find(prefixSum[j])==m.end()){
                m[prefixSum[j]]=0 ; //that 0 is the value of freq of prefixSum[j] in map m 
            }
            m[prefixSum[j]]++ ;
        }
        return count ;
    }
};
