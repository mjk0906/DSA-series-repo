class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentChildren = 0 ;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0 ; //for child
        int j = 0 ; //for cookie
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                contentChildren++;
                i++;
            }
            j++;
        }
        return contentChildren ;
    }
};

//interesting TC which is O(nlogn + mlogm), here sorting causes this TC and the while loop tc is overridden by the sorting one because it is less timetaking than overall sorting