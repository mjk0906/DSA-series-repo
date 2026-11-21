class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size() ;
        k = k%n ;
        reverse(nums.begin(),nums.end()) ;
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.begin()+k);
        //reverse works like this, first element is the begin index in the array and end is the imaginary after last index in the array, important to know
    }
};
//important problem in the arrays thing 