class Solution {
public:
    string largestOddNumber(string num) {

        for(int i= num.length() - 1 ;i>=0 ;i--){
            if((num[i] - '0') % 2 ==1){
                return num.substr(0,i+1) ;
            }
        }
        return "" ;
    }
};

//very easy code just small intuition come from back as we need the largest odd number so if the last number is odd then whole number is odd, as we need to keep the order same
//we can just directly return the substring 