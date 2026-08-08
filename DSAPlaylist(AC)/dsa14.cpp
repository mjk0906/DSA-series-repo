#include <iostream>
#include <vector> 
using namespace std ;
// this is the code for the function of container with max water (easy problem)
int maxArea(vector<int>& height) {
    int maxWater = 0 ;
    int lp = 0 , rp = height.size()-1 ;
    int currWater = 0 ;
    while (lp<rp){
        int w = rp-lp ;
        int ht = min(height[lp],height[rp]);
        currWater = w*ht ;
        maxWater = max(currWater , maxWater) ;
        height[lp] > height[rp] ? rp-- : lp ++ ;
    }
    
    return maxWater ;
}


