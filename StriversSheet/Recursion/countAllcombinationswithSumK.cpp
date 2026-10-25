class Solution {
  public:
    void helper(vector<int>& arr,int i,vector<int>& current,int& ans ,int target){
        
        if(target<0 || i>arr.size()){
            return ;
        }
        if(i==arr.size()){
            if(target==0){
                ans++ ;
            }
            return ;
        }
        current.push_back(arr[i]); //include the element done (base command of inclusion not a call for rest)
        helper(arr,i+1,current,ans,target - arr[i]) ; // include the same element multiple times ,call for rest
        current.pop_back() ; //  done now remove the present element
        helper(arr,i+1,current,ans,target) ; //  call for rest for the not including present element case
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int ans = 0 ;
        vector<int> combin ;
        helper(arr,0,combin,ans,target) ;
        return ans ;
    }
};

// very important this is, this solution will take 2pown time, optimise it with the use of DP