class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> ans ;
        int i = 0 ;
        int j = 0 ;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                if(ans.empty() || ans.back()!=a[i]){
                    ans.push_back(a[i]);
                }
                i++ ;
                j++ ;
            }else if(a[i]>b[j]){
                if(ans.empty() || ans.back()!=b[j]){ //check for duplicate elements
                    ans.push_back(b[j]);
                }
                j++ ;
            }else{
                if(ans.empty() || ans.back()!=a[i]){
                    ans.push_back(a[i]);
                }
                i++;
            }
        }
        if(i<a.size()){
            while(i<a.size()){
                if(ans.empty() || ans.back()!=a[i]){
                    ans.push_back(a[i]);
                }
                i++ ;
            }
        }else if(j<b.size()){
            while(j<b.size()){
                if(ans.empty() || ans.back()!=b[j]){
                    ans.push_back(b[j]);
                }
                j++ ;
            }
        }
        return ans ;
    }
};

//important problem, whole approach was own just a little bit of problem in the duplicate handling(didnt think of it)