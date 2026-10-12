#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x0 , y0 , R ;
        cin >> x0 >> y0 >> R ;
        for(long long x = x0 - R ;x<=x0+R ; x++){
            long long dy2 = R*R - (x-x0)*(x-x0) ;
            if(dy2 < 0){
                continue ;
            }
            long long k = sqrt(dy2) ;
            if(k*k == dy2){
                cout<< x << " " << y0 - k << endl ;
                break ;
            }
        }
    }

    return 0;
}