/*Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.*/

class MyQueue {
public:
stack<int> i,o;
    MyQueue() {
        
    }
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        if(o.empty()){
            while(!i.empty()){
                o.push(i.top());
                i.pop();
            }
        }
        int x = o.top();
        o.pop();
        return x;
    }
    
    int peek() {
        if(o.empty()){
            while(!i.empty()){
                o.push(i.top());
                i.pop();
            }
        }
        int x = o.top();
        return x;
    }
    
    bool empty() {
        return ((i.size()+o.size() )== 0);
    }
};