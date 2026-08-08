#include <iostream>
#include <vector>
using namespace std ;

bool isValid(vector<int> arr ,int n ,int m ,int maxAllowedpages){
    int stu = 1 , pages = 0 ;
    for(int i=0;i<n;i++){
        if(arr[i]>maxAllowedpages){
            return false ;
        }
        if(pages+arr[i]<=maxAllowedpages){
            pages+=arr[i];
        }
        else{
            stu++ ;
            pages=arr[i];
        }
    }
    return stu > m ? false : true ;
}

int bookAllocation (vector<int> &arr , int books ,int stu) {
    if (stu>books){
        return -1 ;
    }
    int sum = 0 ;
    for (int i=0 ;i<books ;i++){
        sum += arr[i] ;
    }
    int st = 0 , end=sum ;
    int ans = -1 ;
    while(st<=end){
    int mid = st + (end-st)/2 ;
    if (isValid(arr,books,stu,mid)){
        ans = mid ;  //the mid value is valid (search on the left side i.e. minimise the value of maxallocated pages)
        end = mid-1 ;
    }
    else{
        st = mid + 1 ; //the mid value is not valid (search for a new maximum on the right side)
    }
    
}
return ans ;
}


int main () {
    vector<int> A = {2,1,3,4} ;
    cout<< bookAllocation(A,4,2) << endl ;
    return 0 ;
}