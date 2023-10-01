class MinStack {
public:
stack<int>st,min;
    MinStack() {
        
    }
    
    void push(int val) {
      st.push(val);
      if(min.empty()||val<=min.top())
      min.push(val);  
    }
    
    void pop() {
     if(st.top()==min.top()){
         min.pop();
     }
     st.pop();
       

    }
    
    int top() {
       if(!st.empty())
       return st.top();
       else
       return 0;
    }
    
    int getMin() {
        if(!min.empty())
        return min.top();
        else 
        return 0;
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