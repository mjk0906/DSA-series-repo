#include <iostream>
#include <vector> 
using namespace std ;

int main(){
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n ;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int zeroes = 0 ;
        for(int x : a){
            if(x==0){
                zeroes++ ;
            }
        }
        if(a[0]==0 && a[n-1]==0){
            cout<< 0 <<endl ;
        }
        else if(((a[0]==0 && a[n-1]==1) || (a[0]==1 && a[n-1]==0)) && zeroes>1){
            cout<< 1 << endl ;
        }
        else if(a[0]==1 && a[n-1]==1 && zeroes>1){
            cout<< 2 << endl ;
        }else{
            cout<< -1 << endl ;
        }
    }
}