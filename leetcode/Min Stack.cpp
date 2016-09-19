class MinStack {
public:
    stack<int> st1, st2;
    
    int getMin() {
    	return st2.top();
    }
    
    void push(int x) {
    	st1.push(x);
    	if (st2.empty() || x <= st2.top())
    		st2.push(x);
    }
    
    void pop() {
    	int x = st1.top();
    	st1.pop();
    	if (x == st2.top()) st2.pop();
    }
    
    int top() {
    	return st1.top();
    }

};
