class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size() ;
        vector<int> leftS(n,0) ;
        vector<int> rightS(n,0) ;
        stack<int> s ;
        //left smallest array(traverse from left)
        for(int i=0;i<n;i++){
            while(!s.empty() && ht[s.top()]>=ht[i]){
                s.pop() ;
            }
            leftS[i] = s.empty() ? -1 : s.top() ;
            s.push(i) ;
        }
        while(!s.empty()){
            s.pop() ;
        }
        //right smallest nearest array(traverse from right)
        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && ht[s.top()]>=ht[i]){
                s.pop() ;
            }
            rightS[i] = s.empty() ? n : s.top() ;
            s.push(i) ;
        }
        int ans = 0 ;
        for(int i=0;i<n;i++){
            int w = rightS[i] - leftS[i] - 1; //this -1 is very important
            int currArea = ht[i]*w ;
            ans = max (currArea,ans) ;
        }
        return ans ;
    }
};

//hard problem but not as such hard