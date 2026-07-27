class MyQueue {
public:

stack<int> input;

stack<int> output;

int peekelement=-1;


    MyQueue() {
        
    }
    
    void push(int x) {
        if (input.empty()){
            peekelement=x;
        }
        input.push(x);
    }
    
    int pop() {
        // amortize 0(1)
        if(output.empty()){
            while(!input.empty()){
                int value=input.top();
                input.pop();
                output.push(value);
            }
        }
        int topper=output.top();
        output.pop();
        return topper;
    }
    
    int peek() {

        if (output.empty()){
            return peekelement;
        }
        return output.top();
        
    }
    
    bool empty() {
        if (input.empty() && output.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */