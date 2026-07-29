class MinStack {
public:

stack<int> stack1;
stack<int> stack2;
int minvalue;

    MinStack() {
        
    }
    
    void push(int value) {
        //stack1.push(value);
        if(stack1.empty()){
            stack1.push(value);
            minvalue=value;
            stack2.push(value);
        }
        else {
            stack1.push(value);
            minvalue=min(minvalue,stack1.top());
            stack2.push(minvalue);
            
        }
    }
    
    void pop() {
        if (!stack1.empty() && !stack2.empty()){
            int value=stack1.top();
            stack1.pop();
            int value1=stack2.top();
            stack2.pop();
            if(!stack2.empty()){
                minvalue=stack2.top();
            }
        }
    }
    
    int top() {
        int value=stack1.top();
        return value;
    }
    
    int getMin() {
        int value=stack2.top();
        return value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */