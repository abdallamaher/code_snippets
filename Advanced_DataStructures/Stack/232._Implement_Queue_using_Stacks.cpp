// Runtime: 0 ms, faster than 100.00% of C++
// Implementation of Queue Using One Stack
// push O(n) pop O(1)
class MyQueue {
    stack<int> st;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size() == 0) {
            st.push(x);
            return;
        }
        int t = st.top();
        st.pop();
        push(x);
        st.push(t);
    }
    
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        int x = st.top();
        return x;
    }
    
    bool empty() {
        return !(int)st.size();
    }
};


/*
// Runtime: 4 ms, faster than 31.03% of C++
// Implementation of Queue Using One Stack
// push O(1) pop O(1)
class MyQueue {
    stack<int> st1;
    stack<int> st2;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.size() ==0) {
            while(st1.size()) {
                int t = st1.top();
                st1.pop();
                st2.push(t);
            }
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.size() == 0) {
            while(st1.size()) {
                int t = st1.top();
                st1.pop();
                st2.push(t);
            }
        }

        return st2.top();
    }
    
    bool empty() {
        return !( (int)st1.size() + (int)st2.size());
    }
};
*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
