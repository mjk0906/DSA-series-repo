#include <iostream>
#include <vector> 
using namespace std ;

void merge(vector<int> &arr,int st,int mid,int end){
    vector<int> temp ;
    int i = st;
    int j = mid+1 ;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
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
}

void breakformerge(vector<int> &arr,int st,int end){
    cout << "Entering: " << st << " to " << end << endl;
    if(st<end){
        int mid = st + (end-st)/2 ;
        breakformerge(arr,st,mid); //for the left part of the cut array 
        breakformerge(arr,mid+1,end); //for the right part of the cut array or the right element
        merge(arr,st,mid,end);
        cout << "Exiting: " << st << " to " << end << " (Merging happened here)" << endl;
    }

}

int main(){
    vector<int> arr = {3,2,4,1};
    breakformerge(arr,0,3);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" " ;
    }
    return 0 ;
}

//this is the code of merge sort working algorithm O(nlogn)=tc and sc =O(n)