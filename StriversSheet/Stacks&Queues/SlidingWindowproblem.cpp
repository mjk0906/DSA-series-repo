class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq ;
        vector<int> ans ; 
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back() ;
            }
            dq.push_back(i) ;
        }
        //as we push the indices it is easy for us to track the elements (using indices)
        for(int i=k ;i<nums.size();i++){
            ans.push_back(nums[dq.front()]) ;
            while(!dq.empty() && dq.front()<=i-k){ //remove all the previous window elements
                dq.pop_front() ;
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back() ;  //now pop back all the elements which are in the current window, but this is from the back side
            }
            dq.push_back(i) ; //push the element that is just smaller than the prev frontal element in the dq or maybe this is the largest(dq might have emptied)
        }
        ans.push_back(nums[dq.front()]) ;
        return ans ;
    }

};

//very important problem, just one thing take the first window at once and then just increment by 1 element(k-i would be negative before )