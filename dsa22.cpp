#include <iostream>
#include <vector>
using namespace std ;

bool isValid(vector<int> arr ,int n ,int m ,int maxMins){
    int painters = 1 , minutes = 0 ;
    for(int i=0;i<n;i++){
        if(arr[i]>maxMins){
            return false ;
        }
        if(minutes+arr[i]<=maxMins){
            minutes+=arr[i];
        }
        else{
            painters++ ;
            minutes=arr[i];
        }
    }
    return painters > m ? false : true ;
}

int painterPartition(vector<int> &arr , int boards ,int painter) {
    int sum = 0 , mostMintime = 0 ;
    for (int i=0 ;i<boards ;i++){
        sum += arr[i] ;
        mostMintime = max(mostMintime , arr[i]) ;  //lowest value of time taken by the painters to finish 
    }
    int st = mostMintime , end=sum ;
    int ans = -1 ;
    while(st<=end){
    int mid = st + (end-st)/2 ;
    if (isValid(arr,boards,painter,mid)){
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
    vector<int> A = {40,30,10,20} ;
    cout<< painterPartition(A,4,2) << endl ;
    return 0 ;
}


//this problem has the same logic as the previous problem and code is the same only 
//just you need to understand the logic that the max value in the array of board lengths is the minimum time taken by the painters to paint all the board which is obtained when each board is assigned to a single painter only(no of painters == no of boards)
// therefore the range of mid value checking should technically lie between min possible value and sum of time taken by painters