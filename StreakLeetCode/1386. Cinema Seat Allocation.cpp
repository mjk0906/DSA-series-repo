class Solution {
public:
    bool isAvailable(int n, set<int>&seats ,int l ,int r){
        for(int i=l;i<=r;i++){
            if(seats.count(i)){
                return false ;
            }
        }
        return true ;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,set<int>> reserved ;
        for(auto seat : reservedSeats){
            int row = seat[0];
            int col = seat[1];
            reserved[row].insert(col) ;
        } //instead of all rows, we are just traversing the reserved seats
        int maxfam = 2*n ;

        for(auto &entry : reserved){
            int row = entry.first ; //this gives the row of the seat
            set<int> seats = entry.second ; //this gives the seat number in the row 

            bool leftAvail = isAvailable(n,seats,2,5);
            bool rightAvail = isAvailable(n,seats,6,9);
            bool middleAvail = isAvailable(n,seats,4,7);
            int groups = 0 ;
            if(leftAvail && rightAvail){
                groups+=2 ;
            }else if (leftAvail || rightAvail || middleAvail){
                groups+=1 ;
            }

            maxfam-=2;
            maxfam+=groups ;
        } 
        return maxfam ;
    }
};

//sexy problem