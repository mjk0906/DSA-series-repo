class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = INT_MIN ;
        for(int i=0;i<arr.size();i++){
            largest = max(arr[i],largest) ;
        }
        int second_largest = -1 ;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=largest){
                second_largest = max(second_largest,arr[i]) ;
            }
        }
        return second_largest ;
    }
};

//very easy written on own