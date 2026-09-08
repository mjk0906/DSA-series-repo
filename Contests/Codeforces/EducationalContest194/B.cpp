#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long ans = 0 ;
        long long x, y, k;
        cin >> x >> y >> k;
        int i = 0 ;
        while(x+i <= y-x && k>0 ){
            long long emp = x+i ;
            long long proj = y+i ;
            ans+= proj%emp ;
            i++ ;
            k-- ;
        }
        ans+= k*(y-x) ;
        cout<<ans<< '\n' ;
    }

    return 0;
}