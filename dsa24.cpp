#include <iostream>
#include <vector>
using namespace std ;

// Sorting algorithms 

void bubbleSort(int arr[],int n){
    for (int i=1;i<n;i++){
        bool isSwap = false ;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]) ;
                isSwap = true;
            }
        }
        if(!isSwap){  //if there is no swapping at the first time then all the elements are kept sorted
            return ;
        }
    }
}

// Selection sort 

void selectionSort(int arr[],int n ){
    for(int i=0 ; i<n ; i++){
        int smallestindex = i ;
        for(int j=i+1 ; j<n ; j++){
            if (arr[smallestindex]>arr[j]){
                smallestindex = j ;
            }
        }
        swap(arr[smallestindex],arr[i]) ;
    }
}

//Insertion sort 
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev=i-1;

        while(curr<arr[prev] && prev>=0){
            arr[prev+1] = arr[prev] ;
            prev-- ;
        }
        arr[prev+1]=curr ;
    }
}
int main(){
    int nums[] = {8,7,4,5,3,1};
    int n = 6 ;
    selectionSort(nums,n) ;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<' ' ;
    }
    cout<<endl ;
    return 0 ;
}
