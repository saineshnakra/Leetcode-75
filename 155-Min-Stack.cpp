class MinStack {
public:

    stack<pair<int,int>>st;
    MinStack() {
    }

    void push(int val) {
    int mn = st.empty() ? val : min(val, st.top().second);
    st.push(make_pair(val,mn));
    }
    
    void pop() { 
        if(st.empty()){
            return;
        }
       st.pop();            
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
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
