#include <iostream>
#include <vector> 
using namespace std ;

int merge(vector<int> &arr,int st,int mid,int end){
    vector<int> temp ;
    int i = st;
    int j = mid+1 ;
    int invCount = 0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invCount+= mid-i+1 ;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0 ; idx<temp.size() ;idx++){
        arr[idx+st]=temp[idx];
    }
    return invCount ;
}

int breakformerge(vector<int> &arr,int st,int end){

    if(st<end){
        int mid = st + (end-st)/2 ;
        int leftInvcount = breakformerge(arr,st,mid); //for the left part of the cut array 
        int rightInvcount = breakformerge(arr,mid+1,end); //for the right part of the cut array or the right element
        int invCount = merge(arr,st,mid,end);
        return invCount + rightInvcount + leftInvcount ;
    }
    return 0 ;
}

int main(){
    vector<int> arr = {3,2,4,1};
    cout<< breakformerge(arr,0,3) << endl;
    int* number = new int(10) ;
    cout<< *number << endl ;
    return 0 ;
};
 