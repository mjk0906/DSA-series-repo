#include <iostream>
using namespace std ;

void reverseArray(int arr[] , int sz) {
    int start = 0 ;
    int end = sz - 1 ;
    while (start < end){
        swap(arr[start],arr[end]) ;  //the main command of the whole code here used to swap the numbers 
        start ++ ;
        end -- ;
    }
}    

int main () {
    int arr[] = {1,2,3,4,5,6,7} ;
    int sz = 7 ;
    reverseArray(arr , sz) ;
    for (int i = 0 ; i<sz ; i++) 
    {
        cout << arr[i] << endl ;
    }
     
}

//--------------homework problems--------------

int swapsmalllarge() {
    int arr[] = {56,78,23,47,67,89,22} ;
    int sz = 7 ;
    int smallest = INT_MAX ;
    int largest = INT_MIN ;
    int i = 0 ;
    int smallesti ;
    int largesti ;

    while (i<sz) {
        if (arr[i]<smallest){
            smallesti = i;
            smallest = arr[i] ;
        }
        
        if (arr[i]>largest){
            largesti  = i ;
            largest = arr[i] ;
        }
        i++ ;
    }
    swap(arr[largesti],arr[smallesti]) ;
    for (i=0;i<sz;i++){
        cout << arr[i] << endl ;
    }
    return 0 ;
} 

void printUniq(int arr[] , int sz){
    
    for (int i = 0; i<sz ; i++){
        bool isunique = true ;
        for(int j = 0 ; j<sz ; j++){
            if ( i!=j && arr[i]==arr[j]){
                isunique = false ;
                break ; // if more than 2 elements are commmon then two times it will be printed so to avoid that we need break
            }
        }
        if (isunique == true){
            cout << arr[i] << endl ;
        }
    }
    
}



void printInter(int arr1[] ,int arr2[] , int sz1 , int sz2){
    
    for (int i = 0; i<sz1; i++){
        bool inter = false ;
        for(int j = 0 ; j<sz2 ; j++){
            if (arr1[i]==arr2[j]){
                inter = true  ;
                break ; 
            }
        }
        if (inter == true){
            cout << arr1[i] << endl ;
        }
    }
    
}

int main () {
    int arr1[] = {1,22,33,33,44,55,6,78,99,33} ;
    int sz1 = 10 ;
    int arr2[] = {2,34,55,79,66,434,543,22,33} ;
    int sz2 = 9 ;
    printInter(arr1,arr2,sz1,sz2) ;
    return 0 ;
} 
