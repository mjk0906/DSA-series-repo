class MinStack {
public:
    stack<long long int> s ;
    long long int minVal ;
    MinStack() {
    }
    
    void push(long long int val) {
        if(s.empty()){
            s.push(val) ;
            minVal = val ;
        }
        else if(val<minVal){
            s.push(2*val-minVal) ;
            minVal = val ;
        }else{
            s.push(val) ;
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()<minVal){
                minVal = 2*minVal - s.top() ;
            }
            s.pop() ;
        }
    }
    
    long long int top() {
        if(!s.empty()){
            if(s.top()<minVal){
                return minVal ;
            }
            return s.top() ;
        }
        return -1 ;
    }
    
    long long int getMin() {
        return minVal ;
    }
};

//very good and crazy approach(easy, standard)