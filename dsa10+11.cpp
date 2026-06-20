#include <iostream>
#include <vector> 
using namespace std ;

//brute force method of pair sum 
vector<int> pairSum(int target , vector<int> vec) { 
    int n = vec.size() ;
    vector<int> ans ;
    for (int i = 0 ; i<n ; i++){
        for (int j = i+1 ; j<n ;j++){
            if (vec[i]+vec[j]== target){
                ans.push_back(i) ;
                ans.push_back(j) ;
                return ans ;
            }
        }
    }
    return ans ;
}
// more efficient method (single loop) optimal 
vector<int> pairSum2(int target , vector<int> vec){
    int n = vec.size() ;
    int i = 0 ;
    int j = n-1 ;
    vector<int> ans ;
    while (i<j){
        int x = vec[i]+vec[j] ;
        if (x<target){
            i++ ;
        }
        else if (x>target){
            j-- ;
        }
        else if (x==target){
            ans.push_back(i) ;
            ans.push_back(j) ;
            return ans ;
        }
    }
    return ans ;
}
// majority element (here we need sorted array for this type of approach)
int majorityElem(vector <int> vec ){
    int n = vec.size() ;
    int freq = 1 ;
    int majelem = vec[0] ;
    for (int i = 1 ; i<n ; i++){
        if (vec[i]==vec[i-1]){
            freq++ ;
        }
        else {
            freq = 1 ;
            majelem = vec[i] ;
        }
        if (freq>n/2){
            majelem = vec[i] ;
            return majelem ;
        }
    
    }
    return majelem ;
}

// Moore's voting method for solving majority element problem 

int majELEM(vector<int> nums) {
    int freq = 0 , ans;
    int n = nums.size() ;
    for (int i = 0 ; i<n ; i++ ){
        if (freq==0){
            ans = nums[i] ;
        }
        if (ans==nums[i]){
            freq++ ;
        }
        else {
            freq-- ;
        }
    }
    return ans ;
}

// for sorting 
vector<int> vec_sort(vector<int> nums) {
    sort(nums.begin(),nums.end()) ; //learn pointers in next lectures
    cout <<nums[0]<<nums[1]<<nums[2]<<nums[5]<< endl ;
    return nums ;
}

int main () {
    vector<int> nums = {2,3,4,4,4,6,4,4,4,4,5,7,8} ;
    int ans = majELEM(nums) ;
    cout << ans << endl ;
    return 0 ;
}

