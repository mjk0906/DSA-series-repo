class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n = arr.size();
        int plarforms = 0 ;
        int i = 0 ;
        int j = 0 ;
        int activePlatforms = 0 ;
        int ans = 0 ;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                activePlatforms++ ;
                i++ ;
                ans = max(ans,activePlatforms) ;
            }else{
                j++;
                activePlatforms-- ;
            }
        }
        return ans ;
    }
};
// very interesting problem and good intuition, simple but legendary