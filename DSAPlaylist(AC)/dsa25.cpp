
// this is the code for dutch national flag algorithm (easy)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;
        int l = 0 , m = 0 , h = n-1 ;
        while (m<=h){
            if (nums[m]==0){
                swap(nums[l],nums[m]) ;
                l++ ; m++ ;
            }
            else if(nums[m]==1) {
                m++ ;
            }
            else {
                swap(nums[m],nums[h]) ; // we swapped with h and h is the part of our unsorted array so we do not know which element is the new mid so no need to change the value of m 
                h-- ;
            }
        }
    }
};
