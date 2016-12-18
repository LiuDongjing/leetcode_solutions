//Implement Queue using Stacks
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while(!data.empty()) {
            tmp.push(data.top());
            data.pop();
        }
        tmp.push(x);
        while(!tmp.empty()){
            data.push(tmp.top());
            tmp.pop();
        }
    }
    // Removes the element from in front of queue.
    void pop(void) {
        data.pop();
    }
    // Get the front element.
    int peek(void) {
        return data.top();
    }
    // Return whether the queue is empty.
    bool empty(void) {
        return data.empty();
    }
private:
    stack<int> data;
};
