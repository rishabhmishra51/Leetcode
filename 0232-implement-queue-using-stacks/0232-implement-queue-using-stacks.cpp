class MyQueue {
public:
   stack<int>input;
   stack<int>output;
   int peekEle=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekEle = x;
        }
        input.push(x);
    }
    //Amortized O(1)
    int pop() {
        if(output.empty()){
        while(!input.empty()){
           int x = input.top();
           input.pop();
           output.push(x);
        }
        }
        int x = output.top();
        output.pop();
        return x;
        
    }
    
    int peek() {
        if(output.empty()){
            return peekEle;
        }
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
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