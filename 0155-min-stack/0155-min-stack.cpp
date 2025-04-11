class MinStack {
public:
    stack<pair<int , int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            int prevMin = st.top().second;
            if( prevMin < val ){// previous minimum is still the minimum
                st.push({val,prevMin});
            } else{
                st.push({val,val});
            }
        }
    }
    
    void pop() {
        return st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */