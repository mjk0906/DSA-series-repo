#include <iostream>
using namespace std ;

int main () {
    // linear search algorithm or method 
    int arr[] = {45,56,78,90,12,35,76} ;
    int sz = 7 ;
    int target = 35 ;
    for (int i = 0 ; i<sz ; i++)
    {
        if (arr[i]==target) {   // the search is perofrmed using a loop here
            cout << i << endl ;
            return 0 ;
        }
    }
    cout << "-1" << endl ;
    return 0 ;
}

// end 