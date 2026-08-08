#include <iostream>
#include <vector> 
using namespace std ;

//this code consists of backtracking (print all the subsets of a parent set)

void printSubsets(vector<int>&arr , vector<int> &ans , int i){
    if (i==arr.size()){
        for(int val : ans){
            cout<< val << " ";
        }
        cout << endl ; // we are not printing all the value of the ans at once but after we attain a subset we print it and the condition for the obtainance of a subset is i = arr.size() if you want clarity draw the tree manually and check the tree you will be getting it the same :) 
        return ;
    }

    ans.push_back(arr[i]); // running the rest of tree including the current element
    printSubsets(arr,ans,i+1);

    ans.pop_back(); //here we are running the rest of the tree by popping back the current element 
    printSubsets(arr,ans,i+1);
    //no need to worry about the i+2 tree, it is recursion so everything is taken care i order 
}
int main () {
    vector<int> arr = {1,2,3} ;
    vector<int> ans ;
    printSubsets(arr,ans,0) ;
    return 0 ;
}