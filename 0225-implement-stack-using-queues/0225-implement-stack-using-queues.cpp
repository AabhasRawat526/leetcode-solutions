class MyStack {
public:

queue<int> input;
queue<int> output;

    MyStack() {
        
    }
    
    void push(int x) {
        input.push(x);
        while(!output.empty()){
            input.push(output.front());
            output.pop();
        }
        swap(input,output);
    }
    
    int pop() {
        int value=output.front();
        output.pop();
        return value;
    }
    
    int top() {
        return output.front();
    }
    
    bool empty() {
        if (output.empty() && input.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */