class StockSpanner {
    stack<pair<int,int>> st ;
public:
    StockSpanner() {
    }
    // this is just a function that needs to be called there in the original code
    int next(int price) {
        int span = 1 ;
        while(!st.empty() && st.top().first<=price){
            span+= st.top().second ;
            st.pop();
        }
        st.push({price,span});
        return span ;
    }
};

//easy but interesting and quite good(just we need to write the function)
//somewhat similar to DP style of solving the quesitons