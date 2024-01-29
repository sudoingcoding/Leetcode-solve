class MyQueue {
public:
    stack<int> list;
    MyQueue() {}

    void push(int x) {
        if (list.empty()) {
            list.push(x);
            return;
        }
        int val = list.top();
        list.pop();
        push(x);
        list.push(val);
    }

    int pop() {
        int temp = list.top();
        list.pop();
        return temp;
    }

    int peek() {
        return list.top();
        ;
    }

    bool empty() { return list.empty(); }
};
