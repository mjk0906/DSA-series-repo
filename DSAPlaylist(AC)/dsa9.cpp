#include <iostream>
#include <vector>
using namespace std ;

// also look at the -std flag in terminal used to run this code due to stl existence 

int main () {
    vector<char> vec = {'a','b','c','d','e','f','g'} ;
    for(char val : vec){
        cout << val << endl ;
    }
    // very important code here: subarray printing 
    int arr[] = {1,2,3,4,5} ;
    int n = 5 ;
    for (int st = 0 ; st<n ; st++){
        for (int end = st ; end<n ; end++){
            for (int i=st ; i<=end ;i++){
                cout << arr[i] ;
            }
            cout << ' ' ;
        }
        cout << endl ;
    }
    // kadane's algorithm (print the maximum sum possible among all the subarrays)
    int curr_sum = 0;
    int max_sum = INT_MIN ;
    for (int i = 0 ;i <n; i++){
        curr_sum+= arr[i] ; 
        max_sum = max(max_sum,curr_sum) ;
        if (curr_sum < 0){
            curr_sum = 0 ;
        }
    }
    cout << max_sum << endl ;
    return 0 ;
}

