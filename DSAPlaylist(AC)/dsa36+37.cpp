

//code for the solution of prob 74 leet

class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix , int target , int row){
        int n = matrix[0].size() ;
        int st = 0 , end = n-1 ;
        while (st<=end){
            int mid = st + (end-st)/2 ;
            if (target == matrix[row][mid]){
                return true;
            }
            if (target<matrix[row][mid]){
                end = mid -1  ;
            }
            if (target>matrix[row][mid]){
                st = mid + 1 ;
            }
        }
        return false ;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() ; int n = matrix[0].size() ;
        int st_row = 0 , end_row = m-1 ;
        while (st_row<=end_row){
            int mid_r = st_row + (end_row-st_row)/2 ;
            if (matrix[mid_r][0] <= target && matrix[mid_r][n-1] >= target){
                // apply binary search here on that row of mid value
                return searchRow(matrix,target,mid_r) ;
            }
            else if (matrix[mid_r][0] > target){
                end_row = mid_r - 1 ;
            }
            else if (matrix[mid_r][n-1] < target){
                st_row = mid_r + 1 ;
            }
        }
        return false ;
    }
};
// be careful with else if and if statements !!!!

// code for spiral matrix prob 54 leet 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        int st_r = 0 ; int e_r = m-1 ;
        int st_c = 0 ; int e_c = n-1 ;
        vector<int> ans ;
        while (st_r<=e_r && st_c<=e_c) {
            //top
            for(int j=st_c ; j<=e_c ; j++){
                ans.push_back(matrix[st_r][j]) ;
            }
            //right
            for(int i = st_r+1 ; i<=e_r ;i++){
                ans.push_back(matrix[i][e_c]) ;
            }
            //bottom
            for (int j=e_c-1 ; j>=st_c ;j--){
                if (st_r == e_r){
                    break ;
                }
                ans.push_back(matrix[e_r][j]) ;
            }
            //left
            for (int i = e_r - 1; i>= st_r+1 ; i--){
                if(st_c == e_c){
                    break ;
                }
                ans.push_back(matrix[i][st_c]) ;
            }
            st_r ++ ; e_r -- ; st_c ++ ; e_c-- ;
        }
        return ans ;
    }
};