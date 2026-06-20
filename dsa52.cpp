#include <iostream>
#include <vector> 
using namespace std ;

int partition(vector<int>&arr,int st,int end){
    int idx = st-1 ; 
    int pivot = arr[end];
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){ //if we keep greater than here we will get descending order of the array 
            idx++;
            swap(arr[idx],arr[j]);   //this whole for loop partitions the array into 2 parts (less than pivot and greater than pivot)
        }
    }
    idx++;
    swap(arr[idx],arr[end]); //this gives the pivot its correct desired location

    return idx ;
}

void quickSort(vector<int> &arr,int st,int end){
    if(st<end){
        int pivIdx = partition(arr,st,end);
        quickSort(arr,st,pivIdx-1); //left part of the pivot 
        quickSort(arr,pivIdx+1,end); //right part of the pivot
    }
}
int main(){
    vector<int> arr = {1,4,5,3,2,6,9,8,7};
    quickSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" " ;
    }
    return 0 ;
}

//this is the code for whole function of quicksort
// TC = O(nlogn) general cases 
// TC = O(n^2) worst case when the pivot is either the largest or the smallest element in the whole array
// SC = O(1) this is better than the merge sort algorrithm