#include <iostream>
#include <vector> 
#include <stack>
using namespace std ;

//with Memoization
int fibDP(int n,vector<int> f){
    if(n<=1) return n;

    if(f[n]!=-1){
        return f[n];
    }
    return f[n]=fibDP(n-1,f)+fibDP(n-2,f);
}
// with Tabulation
int FibDP(int n){
    vector<int> f(n+1);
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n] ;
}
int main(){
    int N = 6 ;
    vector<int> f(N+1,-1); //0<->N will be n+1 values
    int x = fibDP(N,f);

    int y = FibDP(6);
    cout<< x <<endl ;
    cout<< y <<endl ;
}
