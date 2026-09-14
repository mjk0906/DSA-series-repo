class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> leftMin(n) , rightMin(n) ,leftMax(n) ,rightMax(n);
        stack<int> st ;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                leftMin[i] = i+1 ;
            }else{
                leftMin[i] = i-st.top() ;
            }
            st.push(i) ;
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){ //be careful with this loop
                st.pop();
            }
            if(st.empty()){
                rightMin[i] = n-i ;
            }else{
                rightMin[i] = st.top() - i;
            }
            st.push(i) ;
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                leftMax[i] = i+1 ;
            }else{
                leftMax[i] = i-st.top() ;
            }
            st.push(i) ;
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){ //be careful with this loop
                st.pop();
            }
            if(st.empty()){
                rightMax[i] = n-i ;
            }else{
                rightMax[i] = st.top() - i;
            }
            st.push(i) ;
        }
        long long ans = 0 ;
        for(int i=0;i<n;i++){
            long long MaxElements = 1LL*arr[i]*leftMax[i]*rightMax[i] ;
            long long MinElements = 1LL*arr[i]*leftMin[i]*rightMin[i] ;
            ans = ans+ (MaxElements-MinElements) ;
        }
        return ans ;
    }
};

//easy same as subarray ranges problem, think logically