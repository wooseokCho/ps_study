class MyQueue {
private:
    stack<int> stk, tmpStk;
public:
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        while(stk.size() > 1) {
            tmpStk.push(stk.top());
            stk.pop();
        }

        int qPop = stk.top();
        stk.pop();

        while(!tmpStk.empty()) {
            stk.push(tmpStk.top());
            tmpStk.pop();
        }

        return qPop;
    }
    
    int peek() {
        while(stk.size() > 1) {
            tmpStk.push(stk.top());
            stk.pop();
        }

        int front = stk.top();

        while(!tmpStk.empty()) {
            stk.push(tmpStk.top());
            tmpStk.pop();
        }

        return front;
    }
    
    bool empty() {
        return stk.empty();
    }
};