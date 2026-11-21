class Solution {
  public:
    void reverse(vector<int>& nums, int l,int r){
        while(l<r){
            swap(nums[l],nums[r]) ;
            l++ ;
            r-- ;
        }
    }
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size() ;
        d = d%n ;
        
        reverse(arr,0,n-1) ;
        reverse(arr,0,n-d-1) ;
        reverse(arr,n-d,n-1) ;
    }
};
//sexy problem, this is similar to rotating an array by n-d units right
//done bois